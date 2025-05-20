//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    FILE *file;

    if (argc < 3) {
        printf("Usage:./ftp_client <IP_address> <file_name>\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error: Unable to create socket.\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    server_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Unable to connect to server.\n");
        return 1;
    }

    printf("Connected to server successfully.\n");

    if (argc == 3) {
        if (strcmp(argv[2], "upload") == 0) {
            printf("Enter the name of the file to upload: ");
            scanf("%s", buffer);

            file = fopen(buffer, "r");

            if (file == NULL) {
                printf("Error: File not found.\n");
                return 1;
            }

            while (fgets(buffer, BUFFER_SIZE, file)!= NULL) {
                send(sockfd, buffer, strlen(buffer), 0);
            }

            fclose(file);

            printf("File uploaded successfully.\n");
        } else if (strcmp(argv[2], "download") == 0) {
            printf("Enter the name of the file to download: ");
            scanf("%s", buffer);

            send(sockfd, buffer, strlen(buffer), 0);

            while (recv(sockfd, buffer, BUFFER_SIZE, 0) > 0) {
                fputs(buffer, stdout);
            }

            printf("\nFile downloaded successfully.\n");
        } else {
            printf("Invalid command.\n");
        }
    } else {
        printf("Invalid number of arguments.\n");
    }

    close(sockfd);

    return 0;
}