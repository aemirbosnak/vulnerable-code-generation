//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024
#define SERVER_ADDR "192.168.0.1" // Change this to your server address

void ftp_get(int sockfd, char* filename);
void ftp_put(int sockfd, char* filename);

int main(int argc, char* argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buf[BUF_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set server address and port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

    // Connect to server
    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Receive welcome message from server
    memset(buf, 0, BUF_SIZE);
    if(recv(sockfd, buf, BUF_SIZE, 0) == -1) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buf);

    // Login to server
    char username[BUF_SIZE], password[BUF_SIZE];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    sprintf(buf, "USER %s\r\n", username);
    send(sockfd, buf, strlen(buf), 0);
    memset(buf, 0, BUF_SIZE);
    recv(sockfd, buf, BUF_SIZE, 0);
    sprintf(buf, "PASS %s\r\n", password);
    send(sockfd, buf, strlen(buf), 0);
    memset(buf, 0, BUF_SIZE);
    recv(sockfd, buf, BUF_SIZE, 0);
    printf("%s\n", buf);

    // Enter passive mode
    sprintf(buf, "PASV\r\n");
    send(sockfd, buf, strlen(buf), 0);
    memset(buf, 0, BUF_SIZE);
    recv(sockfd, buf, BUF_SIZE, 0);

    // Parse passive mode response to get IP and port
    char* ip_start = strchr(buf, '(') + 1;
    char* ip_end = strchr(ip_start, ',');
    *ip_end = '\0';
    char* ip_parts[4];
    int i = 0;
    char* part_start = ip_start;
    while(part_start != NULL) {
        ip_parts[i++] = part_start;
        if(i == 4) {
            break;
        }
        part_start = strchr(part_start + 1, ',') + 1;
    }
    char ip_address[BUF_SIZE];
    sprintf(ip_address, "%s.%s.%s.%s", ip_parts[0], ip_parts[1], ip_parts[2], ip_parts[3]);
    char* port_start = ip_end + 1;
    char* port_end = strchr(port_start, ')');
    *port_end = '\0';
    int port = atoi(port_start) * 256 + atoi(port_end + 1);

    // Print IP and port
    printf("IP: %s\n", ip_address);
    printf("Port: %d\n", port);

    // Loop for user commands
    while(1) {
        printf("> ");
        char command[BUF_SIZE], filename[BUF_SIZE];
        scanf("%s %s", command, filename);
        if(strcmp(command, "get") == 0) {
            ftp_get(sockfd, filename);
        } else if(strcmp(command, "put") == 0) {
            ftp_put(sockfd, filename);
        } else if(strcmp(command, "quit") == 0) {
            sprintf(buf, "QUIT\r\n");
            send(sockfd, buf, strlen(buf), 0);
            memset(buf, 0, BUF_SIZE);
            recv(sockfd, buf, BUF_SIZE, 0);
            printf("%s\n", buf);
            close(sockfd);
            exit(EXIT_SUCCESS);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}

void ftp_get(int sockfd, char* filename) {
    char buf[BUF_SIZE];
    sprintf(buf, "RETR %s\r\n", filename);
    send(sockfd, buf, strlen(buf), 0);
    memset(buf, 0, BUF_SIZE);
    recv(sockfd, buf, BUF_SIZE, 0);
    if(strncmp(buf, "550", 3) == 0) {
        printf("File not found on server.\n");
    } else {
        FILE* file = fopen(filename, "w");
        if(file == NULL) {
            printf("Failed to open file.\n");
        } else {
            while(1) {
                memset(buf, 0, BUF_SIZE);
                int n = recv(sockfd, buf, BUF_SIZE, 0);
                fwrite(buf, sizeof(char), n, file);
                if(n < BUF_SIZE) {
                    break;
                }
            }
            fclose(file);
            printf("File transfer complete.\n");
        }
    }
}

void ftp_put(int sockfd, char* filename) {
    char buf[BUF_SIZE];
    FILE* file = fopen(filename, "r");
    if(file == NULL) {
        printf("Failed to open file.\n");
    } else {
        sprintf(buf, "STOR %s\r\n", filename);
        send(sockfd, buf, strlen(buf), 0);
        memset(buf, 0, BUF_SIZE);
        recv(sockfd, buf, BUF_SIZE, 0);
        while(1) {
            memset(buf, 0, BUF_SIZE);
            int n = fread(buf, sizeof(char), BUF_SIZE, file);
            send(sockfd, buf, n, 0);
            if(n < BUF_SIZE) {
                break;
            }
        }
        fclose(file);
        printf("File transfer complete.\n");
    }
}