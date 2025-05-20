//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {

    int sock = 0, n = 0;
    char recv_buff[BUFF_SIZE] = {0};
    struct sockaddr_in serv_addr;
    char command[BUFF_SIZE];
    char file_name[BUFF_SIZE];
    char mode[BUFF_SIZE];
    char buffer[BUFF_SIZE];

    if (argc != 3) {
        printf("\nUsage: %s <server IP> <port>\n", argv[0]);
        return 1;
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\nSocket creation error \n");
        return 1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return 1;
    }

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return 1;
    }

    printf("\nSuccessfully connected to the FTP server");

    while (1) {
        printf("\nPlease enter a command (GET/PUT/QUIT): ");
        fgets(command, BUFF_SIZE, stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "QUIT") == 0) {
            printf("\nExiting FTP client...");
            break;
        } else if (strcmp(command, "GET") == 0) {
            printf("\nPlease enter the name of the file to get: ");
            fgets(file_name, BUFF_SIZE, stdin);
            file_name[strcspn(file_name, "\n")] = 0;

            printf("\nPlease enter the mode (ASCII/BINARY): ");
            fgets(mode, BUFF_SIZE, stdin);
            mode[strcspn(mode, "\n")] = 0;

            send(sock, command, strlen(command), 0);
            send(sock, file_name, strlen(file_name), 0);
            send(sock, mode, strlen(mode), 0);

            int file_fd = open(file_name, O_CREAT | O_WRONLY, 0666);
            int file_size = 0;
            recv(sock, &file_size, sizeof(file_size), 0);

            if (file_size == -1) {
                printf("\nFile not found on server\n");
                close(file_fd);
                continue;
            }

            int bytes_received = 0;
            int total_bytes_received = 0;
            while (total_bytes_received < file_size) {
                bytes_received = recv(sock, buffer, BUFF_SIZE, 0);
                total_bytes_received += bytes_received;
                write(file_fd, buffer, bytes_received);
            }

            printf("\nFile successfully received from server!\n");
            close(file_fd);
        } else if (strcmp(command, "PUT") == 0) {
            printf("\nPlease enter the name of the file to put: ");
            fgets(file_name, BUFF_SIZE, stdin);
            file_name[strcspn(file_name, "\n")] = 0;

            printf("\nPlease enter the mode (ASCII/BINARY): ");
            fgets(mode, BUFF_SIZE, stdin);
            mode[strcspn(mode, "\n")] = 0;

            int file_fd = open(file_name, O_RDONLY);
            if (file_fd == -1) {
                printf("\nFile not found on client\n");
                continue;
            }

            int file_size = lseek(file_fd, 0, SEEK_END);
            lseek(file_fd, 0, SEEK_SET);

            send(sock, command, strlen(command), 0);
            send(sock, file_name, strlen(file_name), 0);
            send(sock, mode, strlen(mode), 0);
            send(sock, &file_size, sizeof(file_size), 0);

            int bytes_sent = 0;
            int total_bytes_sent = 0;
            while (total_bytes_sent < file_size) {
                bytes_sent = read(file_fd, buffer, BUFF_SIZE);
                total_bytes_sent += bytes_sent;
                send(sock, buffer, bytes_sent, 0);
            }

            printf("\nFile successfully sent to server!\n");
            close(file_fd);
        } else {
            printf("\nInvalid command, please try again...\n");
        }

    }

    close(sock);
    return 0;
}