//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_LINE 1024
#define MAX_ARGS 10

int main(int argc, char *argv[])
{
    int sockfd, port;
    char *host, *username, *password, *command, *args[MAX_ARGS];
    int i, arg_count;

    if (argc < 4) {
        fprintf(stderr, "Usage: %s host port username [password] [command] [args...]\n", argv[0]);
        return EXIT_FAILURE;
    }

    host = argv[1];
    port = atoi(argv[2]);
    username = argv[3];

    if (argc >= 5) {
        password = argv[4];
    } else {
        password = "";
    }

    if (argc >= 6) {
        command = argv[5];
        arg_count = argc - 6;
    } else {
        command = "LIST";
        arg_count = 0;
    }

    for (i = 0; i < arg_count; i++) {
        args[i] = argv[6 + i];
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(host);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the username and password to the server
    char buf[MAX_LINE];
    sprintf(buf, "USER %s\r\n", username);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }
    if (recv(sockfd, buf, MAX_LINE, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    if (strncmp(buf, "331 ", 4) != 0) {
        fprintf(stderr, "Error: %s\n", buf);
        return EXIT_FAILURE;
    }
    sprintf(buf, "PASS %s\r\n", password);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }
    if (recv(sockfd, buf, MAX_LINE, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    if (strncmp(buf, "230 ", 4) != 0) {
        fprintf(stderr, "Error: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Send the command to the server
    sprintf(buf, "%s", command);
    for (i = 0; i < arg_count; i++) {
        strcat(buf, " ");
        strcat(buf, args[i]);
    }
    strcat(buf, "\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the server
    while (1) {
        if (recv(sockfd, buf, MAX_LINE, 0) == -1) {
            perror("recv");
            return EXIT_FAILURE;
        }
        if (strncmp(buf, "226 ", 4) == 0) {
            break;
        }
        printf("%s", buf);
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}