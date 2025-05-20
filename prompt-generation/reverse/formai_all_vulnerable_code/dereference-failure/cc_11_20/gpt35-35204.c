//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("USAGE: ./ftpclient [SERVER IP] [PORT NUMBER]\n");
        return 1;
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Couldn't create socket");
        return 1;
    }

    // Set server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        perror("Invalid IP address");
        return 1;
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Couldn't connect");
        return 1;
    }

    // Receive welcome message from server
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Couldn't receive message from server");
        return 1;
    }
    printf("%s", buffer);

    // Main loop
    while (1) {
        printf("ftp>");
        memset(buffer, 0, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE, stdin);

        // Parse command
        char *token = strtok(buffer, " \n");
        if (strcmp(token, "quit") == 0) {
            break;
        }
        else if (strcmp(token, "get") == 0) {
            token = strtok(NULL, " \n");
            if (!token) {
                printf("USAGE: get [REMOTE FILENAME]\n");
                continue;
            }

            // Send request to server
            char request[BUFFER_SIZE];
            memset(request, 0, BUFFER_SIZE);
            sprintf(request, "GET %s", token);
            send(sockfd, request, strlen(request), 0);

            // Receive response from server
            int filesize;
            memset(buffer, 0, BUFFER_SIZE);
            if (recv(sockfd, &filesize, sizeof(filesize), 0) < 0) {
                perror("Couldn't receive file size from server");
                continue;
            }

            // Open local file for writing
            token = strtok(token, "/");
            char local_filename[BUFFER_SIZE];
            memset(local_filename, 0, BUFFER_SIZE);
            sprintf(local_filename, "local_%s", token);
            FILE *local_file = fopen(local_filename, "wb");
            if (!local_file) {
                perror("Couldn't open local file for writing");
                continue;
            }

            // Receive file data and write to local file
            int remaining_bytes = filesize;
            while (remaining_bytes > 0) {
                memset(buffer, 0, BUFFER_SIZE);
                int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
                if (bytes_received < 0) {
                    perror("Couldn't receive file data from server");
                    break;
                }
                fwrite(buffer, sizeof(char), bytes_received, local_file);
                remaining_bytes -= bytes_received;
            }

            // Close local file
            fclose(local_file);
            printf("File transferred successfully\n");
        }
        else {
            printf("Invalid command\n");
        }
    }

    // Close socket
    close(sockfd);
    return 0;
}