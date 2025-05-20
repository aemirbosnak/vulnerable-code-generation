//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_BUFFER_SIZE 1024

void create_dir(char *dirname) {
    mkdir(dirname, 0777);
}

void dir_list_files(char *dirname) {
    DIR *dir;
    struct dirent *directory;
    dir = opendir(dirname);
    if (dir) {
        while ((directory = readdir(dir)) != NULL) {
            printf("%s\n", directory->d_name);
        }
        closedir(dir);
    }
}

int main(int argc, char **argv) {
    int client_socket;
    struct sockaddr_in server_address;
    char buffer[MAX_BUFFER_SIZE];
    char curr_dir[MAX_BUFFER_SIZE] = ".";
    char filename[MAX_BUFFER_SIZE] = "";
    char command[MAX_BUFFER_SIZE];

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(21);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    client_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        printf("Couldn't connect to server\n");
        return 1;
    }

    printf("Connected to server\n");

    recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
    printf("[Server] %s", buffer);

    sprintf(buffer, "USER user\r\n");
    send(client_socket, buffer, strlen(buffer), 0);

    recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
    printf("[Server] %s", buffer);

    sprintf(buffer, "PASS password\r\n");
    send(client_socket, buffer, strlen(buffer), 0);

    recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
    printf("[Server] %s", buffer);

    while (1) {
        printf("> ");
        fgets(command, MAX_BUFFER_SIZE, stdin);
        command[strcspn(command, "\n")] = 0;

        if (strncmp(command, "QUIT", 4) == 0) {
            sprintf(buffer, "QUIT\r\n");
            send(client_socket, buffer, strlen(buffer), 0);
            break;
        } else if (strncmp(command, "PWD", 3) == 0) {
            sprintf(buffer, "PWD\r\n");
            send(client_socket, buffer, strlen(buffer), 0);

            recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
            printf("%s", buffer);
        } else if (strncmp(command, "LIST", 4) == 0) {
            sprintf(buffer, "PASV\r\n");
            send(client_socket, buffer, strlen(buffer), 0);

            recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
            printf("[Server] %s", buffer);

            int h1, h2, h3, h4, p1, p2;
            char *pos1 = strchr(buffer, '(');
            sscanf(pos1+1, "%d,%d,%d,%d,%d,%d", &h1, &h2, &h3, &h4, &p1, &p2);

            struct sockaddr_in data_connection_address;
            memset(&data_connection_address, 0, sizeof(data_connection_address));
            data_connection_address.sin_family = AF_INET;
            data_connection_address.sin_port = htons(p1*256+p2);
            char data_conn_str[30];
            sprintf(data_conn_str, "%d.%d.%d.%d", h1, h2, h3, h4);
            data_connection_address.sin_addr.s_addr = inet_addr(data_conn_str);

            int data_socket = socket(AF_INET, SOCK_STREAM, 0);
            if (connect(data_socket, (struct sockaddr *)&data_connection_address, sizeof(data_connection_address)) == -1) {
                printf("Couldn't connect to server\n");
                return 1;
            }

            sprintf(buffer, "LIST\r\n");
            send(client_socket, buffer, strlen(buffer), 0);

            recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
            printf("[Server] %s", buffer);

            while (recv(data_socket, buffer, MAX_BUFFER_SIZE, 0)) {
                printf("[Data] %s", buffer);
            }
            close(data_socket);

            recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
            printf("[Server] %s", buffer);
        } else if (strncmp(command, "CWD", 3) == 0) {
            char param[MAX_BUFFER_SIZE];
            sscanf(command+3, "%s", param);

            sprintf(buffer, "CWD %s\r\n", param);
            send(client_socket, buffer, strlen(buffer), 0);

            recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
            printf("[Server] %s", buffer);
        } else if (strncmp(command, "CDUP", 4) == 0) {
            sprintf(buffer, "CDUP\r\n");
            send(client_socket, buffer, strlen(buffer), 0);

            recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
            printf("[Server] %s", buffer);
        } else if (strncmp(command, "MKD", 3) == 0) {
            char param[MAX_BUFFER_SIZE];
            sscanf(command+3, "%s", param);

            sprintf(buffer, "MKD %s\r\n", param);
            send(client_socket, buffer, strlen(buffer), 0);

            recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
            printf("[Server] %s", buffer);
        } else if (strncmp(command, "RMD", 3) == 0) {
            char param[MAX_BUFFER_SIZE];
            sscanf(command+3, "%s", param);

            sprintf(buffer, "RMD %s\r\n", param);
            send(client_socket, buffer, strlen(buffer), 0);

            recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
            printf("[Server] %s", buffer);
        } else if (strncmp(command, "RETR", 4) == 0) {
            char param[MAX_BUFFER_SIZE];
            sscanf(command+4, "%s", param);

            sprintf(buffer, "PASV\r\n");
            send(client_socket, buffer, strlen(buffer), 0);

            recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
            printf("[Server] %s", buffer);

            int h1, h2, h3, h4, p1, p2;
            char *pos1 = strchr(buffer, '(');
            sscanf(pos1+1, "%d,%d,%d,%d,%d,%d", &h1, &h2, &h3, &h4, &p1, &p2);

            struct sockaddr_in data_connection_address;
            memset(&data_connection_address, 0, sizeof(data_connection_address));
            data_connection_address.sin_family = AF_INET;
            data_connection_address.sin_port = htons(p1*256+p2);
            char data_conn_str[30];
            sprintf(data_conn_str, "%d.%d.%d.%d", h1, h2, h3, h4);
            data_connection_address.sin_addr.s_addr = inet_addr(data_conn_str);

            int data_socket = socket(AF_INET, SOCK_STREAM, 0);
            if (connect(data_socket, (struct sockaddr *)&data_connection_address, sizeof(data_connection_address)) == -1) {
                printf("Couldn't connect to server\n");
                return 1;
            }

            sprintf(buffer, "RETR %s\r\n", param);
            send(client_socket, buffer, strlen(buffer), 0);

            recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
            printf("[Server] %s", buffer);

            FILE *fp = fopen(param, "wb");
            if (fp == NULL) {
                printf("Error creating file\n");
                return 1;
            }

            while (recv(data_socket, buffer, MAX_BUFFER_SIZE, 0)) {
                fwrite(buffer, 1, sizeof(buffer), fp);
            }
            fclose(fp);
            close(data_socket);

            recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
            printf("[Server] %s", buffer);
        } else if (strncmp(command, "STOR", 4) == 0) {
            char param[MAX_BUFFER_SIZE];
            sscanf(command+4, "%s", param);

            sprintf(buffer, "PASV\r\n");
            send(client_socket, buffer, strlen(buffer), 0);

            recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
            printf("[Server] %s", buffer);

            int h1, h2, h3, h4, p1, p2;
            char *pos1 = strchr(buffer, '(');
            sscanf(pos1+1, "%d,%d,%d,%d,%d,%d", &h1, &h2, &h3, &h4, &p1, &p2);

            struct sockaddr_in data_connection_address;
            memset(&data_connection_address, 0, sizeof(data_connection_address));
            data_connection_address.sin_family = AF_INET;
            data_connection_address.sin_port = htons(p1*256+p2);
            char data_conn_str[30];
            sprintf(data_conn_str, "%d.%d.%d.%d", h1, h2, h3, h4);
            data_connection_address.sin_addr.s_addr = inet_addr(data_conn_str);

            int data_socket = socket(AF_INET, SOCK_STREAM, 0);
            if (connect(data_socket, (struct sockaddr *)&data_connection_address, sizeof(data_connection_address)) == -1) {
                printf("Couldn't connect to server\n");
                return 1;
            }

            sprintf(buffer, "STOR %s\r\n", param);
            send(client_socket, buffer, strlen(buffer), 0);

            recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
            printf("[Server] %s", buffer);

            FILE *fp = fopen(param, "rb");
            if (fp == NULL) {
                printf("Error reading file\n");
                return 1;
            }

            while (!feof(fp)) {
                int size = fread(buffer, 1, sizeof(buffer), fp);
                send(data_socket, buffer, size, 0);
            }
            fclose(fp);
            close(data_socket);

            recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
            printf("[Server] %s", buffer);
        }
    }

    close(client_socket);

    return 0;
}