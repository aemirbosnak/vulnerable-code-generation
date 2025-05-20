//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PORT 21

void error_handling(char* message);

int main(int argc, char* argv[]) {

    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    int n;

    if (argc!= 3) {
        printf("Usage:./ftp_client <IP address> <port number>\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error_handling("Error opening socket");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        error_handling("Error connecting to server");
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter command (get/put/quit): ");
        scanf("%s", buffer);

        if (strcmp(buffer, "get") == 0) {
            printf("Enter filename: ");
            scanf("%s", buffer);

            send(sockfd, buffer, strlen(buffer), 0);

            n = recv(sockfd, buffer, BUFFER_SIZE, 0);

            if (n < 0) {
                error_handling("Error receiving data");
            }

            printf("File contents:\n%s", buffer);
        } else if (strcmp(buffer, "put") == 0) {
            printf("Enter filename: ");
            scanf("%s", buffer);

            send(sockfd, buffer, strlen(buffer), 0);

            FILE* file = fopen(buffer, "rb");

            if (file == NULL) {
                error_handling("Error opening file");
            }

            while (fread(buffer, 1, BUFFER_SIZE, file) > 0) {
                send(sockfd, buffer, BUFFER_SIZE, 0);
            }

            fclose(file);
        } else if (strcmp(buffer, "quit") == 0) {
            printf("Quitting...\n");
            close(sockfd);
            exit(0);
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}

void error_handling(char* message) {
    perror(message);
    exit(1);
}