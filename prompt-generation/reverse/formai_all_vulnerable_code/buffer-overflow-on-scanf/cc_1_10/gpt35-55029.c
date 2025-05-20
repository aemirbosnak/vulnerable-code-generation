//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXSIZE 1024

int main(int argc, char* argv[]) {
    int client_socket;
    struct sockaddr_in server_address;
    char buf[MAXSIZE];

    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof server_address);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(21);

    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) != 1) {
        perror("inet_pton error");
        exit(EXIT_FAILURE);
    }

    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof server_address) == -1) {
        perror("connect error");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    recv(client_socket, buf, MAXSIZE, 0);
    printf("%s\n", buf);

    // Login process
    char user[MAXSIZE], pass[MAXSIZE];
    printf("Username: ");
    scanf("%s", user);
    snprintf(buf, sizeof buf, "USER %s\r\n", user);
    write(client_socket, buf, strlen(buf));
    recv(client_socket, buf, MAXSIZE, 0);
    printf("%s\n", buf);

    printf("Password: ");
    scanf("%s", pass);
    snprintf(buf, sizeof buf, "PASS %s\r\n", pass);
    write(client_socket, buf, strlen(buf));
    recv(client_socket, buf, MAXSIZE, 0);
    printf("%s\n", buf);

    // Enter passive mode
    write(client_socket, "PASV\r\n", strlen("PASV\r\n"));
    recv(client_socket, buf, MAXSIZE, 0);
    printf("%s\n", buf);

    // Set up data connection
    char ip_addr[MAXSIZE];
    int port_nums[6];
    sscanf(buf, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)", &port_nums[0], &port_nums[1], &port_nums[2], &port_nums[3], &port_nums[4], &port_nums[5]);
    snprintf(ip_addr, sizeof ip_addr, "%d.%d.%d.%d", port_nums[0], port_nums[1], port_nums[2], port_nums[3]);
    int data_port = port_nums[4] * 256 + port_nums[5];

    int data_socket;
    struct sockaddr_in data_address;
    if ((data_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    memset(&data_address, 0, sizeof data_address);
    data_address.sin_family = AF_INET;
    data_address.sin_port = htons(data_port);

    if (inet_pton(AF_INET, ip_addr, &data_address.sin_addr) != 1) {
        perror("inet_pton error");
        exit(EXIT_FAILURE);
    }

    if (connect(data_socket, (struct sockaddr *)&data_address, sizeof data_address) == -1) {
        perror("connect error");
        exit(EXIT_FAILURE);
    }

    printf("Data connection established\n");

    // Retrieve file
    char filename[MAXSIZE];
    printf("File name: ");
    scanf("%s", filename);

    snprintf(buf, sizeof buf, "RETR %s\r\n", filename);
    write(client_socket, buf, strlen(buf));
    recv(client_socket, buf, MAXSIZE, 0);
    printf("%s\n", buf);

    FILE* fp;
    if ((fp = fopen(filename, "wb")) == NULL) {
        perror("file error");
        exit(EXIT_FAILURE);
    }

    ssize_t num_read;
    while ((num_read = recv(data_socket, buf, MAXSIZE, 0)) > 0) {
        if (fwrite(buf, sizeof(char), num_read, fp) != num_read) {
            perror("write error");
            exit(EXIT_FAILURE);
        }
    }

    fclose(fp);
    close(data_socket);
    close(client_socket);

    return EXIT_SUCCESS;
}