//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("Usage: ftpclient <hostname> <port>\n");
        exit(1);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    printf("Welcome to the FTP client!\n\n");

    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_SIZE];
    memset(buffer, 0, sizeof(buffer));

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        printf("Error creating socket!\n");
        exit(1);
    }

    server = gethostbyname(hostname);
    if(server == NULL) {
        printf("Error! No such host found!\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *) &serv_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server!\n");
        exit(1);
    }

    printf("Successfully connected to server!\n\n");

    while(1) {
        printf("Please type the FTP command:\n");
        char user_input[MAX_SIZE];
        memset(user_input, 0, MAX_SIZE);
        fgets(user_input, MAX_SIZE, stdin);

        if((strlen(user_input) > 0) && (user_input[strlen(user_input) - 1] == '\n')) {
            user_input[strlen(user_input) - 1] = '\0';
        }

        char *command = strtok(user_input, " ");
        if(command == NULL) {
            printf("Error! Invalid command!\n");
            continue;
        }

        if(strcmp(command, "QUIT") == 0) {
            printf("Exiting...\n");
            break;
        }

        if(strcmp(command, "LIST") != 0) {
            printf("Error! Unsupported command!\n");
            continue;
        }

        if(send(sockfd, user_input, strlen(user_input), 0) < 0) {
            printf("Error sending command to server!\n");
            continue;
        }

        printf("Waiting for response from server...\n");

        memset(buffer, 0, sizeof(buffer));
        while((n = read(sockfd, buffer, MAX_SIZE-1)) > 0) {
            printf("%s", buffer);
            memset(buffer, 0, MAX_SIZE);
        }

        printf("\nResponse completed!\n\n");
    }

    close(sockfd);
    return 0;
}