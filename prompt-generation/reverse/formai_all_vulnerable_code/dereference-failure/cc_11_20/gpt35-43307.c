//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char mail_from[BUFFER_SIZE];
    char rcpt_to[BUFFER_SIZE];
    char message[BUFFER_SIZE];
    char *server_addr_str;
    int port;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    server_addr_str = argv[1];
    port = atoi(argv[2]);

    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, server_addr_str, &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton() failed for %s\n", server_addr_str);
        exit(EXIT_FAILURE);
    }

    if (connect(client_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        exit(EXIT_FAILURE);
    }

    printf("220 %s ESMTP server ready\n", server_addr_str);
    printf("HELO test.com\n");

    while ((read = getline(&line, &len, stdin)) != -1) {
        if (strstr(line, "MAIL FROM") != NULL) {
            sscanf(line, "MAIL FROM:<%s>", mail_from);
            printf("250 Mail OK\n");
        }
        else if (strstr(line, "RCPT TO") != NULL) {
            sscanf(line, "RCPT TO:<%s>", rcpt_to);
            printf("250 Recipient OK\n");
        }
        else if (strstr(line, "DATA") != NULL) {
            printf("354 Start mail input\n");
            while ((read = getline(&line, &len, stdin)) != -1) {
                if (strstr(line, ".\r\n") != NULL) {
                    break;
                }
                strcat(message, line);
            }
            printf("250 Message accepted for delivery\n");
            memset(message, 0, sizeof(message));
        }
        else if (strstr(line, "QUIT") != NULL) {
            printf("221 Goodbye\n");
            break;
        }
        else {
            printf("500 Unknown command\n");
        }
    }

    free(line);
    close(client_socket);
    exit(EXIT_SUCCESS);
}