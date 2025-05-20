//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int sockfd, n;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_address;

    if (argc < 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, '0', sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        perror("Failed to parse IP address");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server %s:%s\n", argv[1], argv[2]);

    while (1) {
        char command[BUFFER_SIZE];
        printf("\nPlease enter a command ('get' or 'put' followed by a filename, or 'quit'):\n");
        fgets(command, BUFFER_SIZE, stdin);

        // remove newline character from input
        command[strcspn(command, "\n")] = '\0';

        if (strncmp(command, "get", 3) == 0) {
            // send GET command to server
            write(sockfd, command, strlen(command));

            // receive file from server
            char filename[BUFFER_SIZE];
            FILE *file;
            int filesize;
            int bytes_received = 0;
            int bytes_remaining;

            // parse filename from command string
            strcpy(filename, command + 4);

            // receive file size from server
            read(sockfd, &filesize, sizeof(int));

            // open file for writing
            file = fopen(filename, "wb");

            if (file == NULL) {
                perror("Failed to open file for writing");
                continue;
            }

            printf("Receiving file %s (%d bytes)...\n", filename, filesize);

            bytes_remaining = filesize;

            while (bytes_remaining > 0) {
                n = read(sockfd, buffer, BUFFER_SIZE);

                if (n < 0) {
                    perror("Failed to receive file from server");
                    break;
                }

                fwrite(buffer, sizeof(char), n, file);

                bytes_received += n;
                bytes_remaining -= n;
            }

            fclose(file);

            printf("Received %d bytes\n", bytes_received);
        } else if (strncmp(command, "put", 3) == 0) {
            // send PUT command to server
            write(sockfd, command, strlen(command));

            // send file to server
            char filename[BUFFER_SIZE];
            FILE *file;
            int filesize;
            int bytes_sent = 0;

            // parse filename from command string
            strcpy(filename, command + 4);

            // open file for reading
            file = fopen(filename, "rb");

            if (file == NULL) {
                perror("Failed to open file for reading");
                continue;
            }

            // determine file size
            fseek(file, 0L, SEEK_END);
            filesize = ftell(file);
            fseek(file, 0L, SEEK_SET);

            // send file size to server
            write(sockfd, &filesize, sizeof(int));

            printf("Sending file %s (%d bytes)...\n", filename, filesize);

            while (!feof(file)) {
                n = fread(buffer, sizeof(char), BUFFER_SIZE, file);

                if (n <= 0) {
                    break;
                }

                write(sockfd, buffer, n);

                bytes_sent += n;
            }

            fclose(file);

            printf("Sent %d bytes\n", bytes_sent);
        } else if (strncmp(command, "quit", 4) == 0) {
            // send QUIT command to server
            write(sockfd, command, strlen(command));

            // close socket and exit program
            close(sockfd);
            exit(EXIT_SUCCESS);
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}