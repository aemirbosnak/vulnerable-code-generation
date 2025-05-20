//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: optimized
// FTP Client Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    // Variable Declarations
    int sockfd, port;
    char *host;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    char filename[BUFFER_SIZE];
    FILE *fp;
    ssize_t n;

    // Input Validation
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    host = argv[1];
    port = atoi(argv[2]);

    // Create Socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR creating socket");
        exit(EXIT_FAILURE);
    }

    // Get Hostname Information
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "ERROR: No such host\n");
        exit(EXIT_FAILURE);
    }

    // Set Server Address Structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr*)server->h_addr));
    serv_addr.sin_port = htons(port);

    // Connect to Server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    // Request User Input for Commands
    while (1) {
        printf("FTP> ");
        fgets(command, BUFFER_SIZE, stdin);
        strtok(command, "\n");

        // Handle Commands
        if (strstr(command, "exit") != NULL) {
            break;

        } else if (strstr(command, "get") != NULL) {
            // Send GET Command
            send(sockfd, command, strlen(command), 0);

            // Get Filename From Command
            sscanf(command, "get %s", filename);

            // Open File and Write to It
            fp = fopen(filename, "wb");
            while(1) {
                // Read Data From Socket
                n = recv(sockfd, buffer, BUFFER_SIZE, 0);
                if (n <= 0) break;

                // Write Data to File
                fwrite(buffer, sizeof(char), n, fp);
                if (feof(fp)) break;
            }
            fclose(fp);
            printf("%s downloaded successfully!\n", filename);

        } else if (strstr(command, "put") != NULL) {
            // Send PUT Command
            send(sockfd, command, strlen(command), 0);

            // Get Filename From Command
            sscanf(command, "put %s", filename);

            // Open File and Read From It
            fp = fopen(filename, "rb");
            if (fp == NULL) {
                fprintf(stderr, "ERROR: Cannot open file %s\n", filename);
                continue;
            }
            while(1) {
                // Read Data From File
                n = fread(buffer, sizeof(char), BUFFER_SIZE, fp);
                if (n <= 0) break;

                // Send Data to Socket
                send(sockfd, buffer, n, 0);
            }
            fclose(fp);
            printf("%s uploaded successfully!\n", filename);

        } else {
            printf("Invalid command!\n");
        }
    }

    // Close Socket
    close(sockfd);
    return 0;
}