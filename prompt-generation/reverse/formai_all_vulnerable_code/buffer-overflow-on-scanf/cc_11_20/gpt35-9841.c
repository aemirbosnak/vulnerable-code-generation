//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: satisfied
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: ./ftpclient <IP Address> <Port>\n");
        exit(EXIT_FAILURE);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(atoi(argv[2]));

    if(connect(sock, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    int command;
    while(1) {
        printf("Enter command (1: List files, 2: Download file, 3: Exit): ");
        scanf("%d", &command);

        if(command == 1) {
            // Send command to server
            if(send(sock, "LIST", 4, 0) < 0) {
                perror("Command sending failed");
                exit(EXIT_FAILURE);
            }

            // Receive response from server
            memset(buffer, 0, sizeof(buffer));
            if(recv(sock, buffer, sizeof(buffer), 0) < 0) {
                perror("Response receiving failed");
                exit(EXIT_FAILURE);
            }

            printf("List of files:\n%s\n", buffer);
        } else if(command == 2) {
            // Enter file name
            printf("Enter file name: ");
            char filename[100];
            scanf("%s", filename);

            // Send command to server
            if(send(sock, filename, strlen(filename), 0) < 0) {
                perror("Command sending failed");
                exit(EXIT_FAILURE);
            }

            // Receive response from server
            memset(buffer, 0, sizeof(buffer));
            int filesize;
            if(recv(sock, &filesize, sizeof(filesize), 0) < 0) {
                perror("Response receiving failed");
                exit(EXIT_FAILURE);
            }

            if(filesize == 0) {
                printf("File not found\n");
                continue;
            }

            // Download file
            FILE *file = fopen(filename, "wb");
            if(file == NULL) {
                perror("File opening failed");
                exit(EXIT_FAILURE);
            }

            int total_bytes = 0;
            while(total_bytes < filesize) {
                int bytes_read = recv(sock, buffer, sizeof(buffer), 0);
                if(bytes_read < 0) {
                    perror("File receiving failed");
                    exit(EXIT_FAILURE);
                }
                fwrite(buffer, 1, bytes_read, file);
                total_bytes += bytes_read;
            }

            fclose(file);
            printf("File downloaded successfully\n");
        } else if(command == 3) {
            // Send command to server
            if(send(sock, "QUIT", 4, 0) < 0) {
                perror("Command sending failed");
                exit(EXIT_FAILURE);
            }

            // Close connection
            close(sock);
            printf("Connection closed\n");
            exit(EXIT_SUCCESS);
        } else {
            printf("Invalid command\n");
        }
    }
    return 0;
}