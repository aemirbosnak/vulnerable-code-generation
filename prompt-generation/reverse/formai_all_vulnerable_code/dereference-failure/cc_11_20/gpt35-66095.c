//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define PORT "143" // IMAP default port
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    int sockfd, num_bytes;
    struct addrinfo hints, *res;
    char buffer[BUFFER_SIZE];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    memset(&hints, 0, sizeof hints); // set hints to zero
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    getaddrinfo(argv[1], PORT, &hints, &res);

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        perror("Unable to open socket");
        exit(1);
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        perror("Unable to connect to IMAP server");
        exit(1);
    }

    // receive server welcome message
    memset(buffer, 0, BUFFER_SIZE);
    num_bytes = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (num_bytes > 0) {
        printf("%s", buffer);
    } else {
        perror("Unable to receive welcome message");
        exit(1);
    }

    // send login command
    char username[] = "username";
    char password[] = "password";
    char login_cmd[BUFFER_SIZE];
    sprintf(login_cmd, "LOGIN %s %s\r\n", username, password);
    send(sockfd, login_cmd, strlen(login_cmd), 0);

    // receive login response
    memset(buffer, 0, BUFFER_SIZE);
    num_bytes = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (num_bytes > 0) {
        printf("%s", buffer);
    } else {
        perror("Unable to receive login response");
        exit(1);
    }

    // send select command
    char select_cmd[BUFFER_SIZE];
    sprintf(select_cmd, "SELECT INBOX\r\n");
    send(sockfd, select_cmd, strlen(select_cmd), 0);

    // receive select response
    memset(buffer, 0, BUFFER_SIZE);
    num_bytes = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (num_bytes > 0) {
        printf("%s", buffer);
    } else {
        perror("Unable to receive select response");
        exit(1);
    }

    // send search command
    char search_cmd[BUFFER_SIZE];
    sprintf(search_cmd, "SEARCH UNSEEN\r\n");
    send(sockfd, search_cmd, strlen(search_cmd), 0);

    // receive search response
    memset(buffer, 0, BUFFER_SIZE);
    num_bytes = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (num_bytes > 0) {
        // process search results
        char *msg_ids = strstr(buffer, "SEARCH");
        if (msg_ids != NULL) {
            msg_ids += strlen("SEARCH ");
            char *token = strtok(msg_ids, " ");
            while (token != NULL) {
                // retrieve message contents
                char retrieve_cmd[BUFFER_SIZE];
                sprintf(retrieve_cmd, "FETCH %s BODY[]\r\n", token);
                send(sockfd, retrieve_cmd, strlen(retrieve_cmd), 0);

                // receive message contents
                memset(buffer, 0, BUFFER_SIZE);
                num_bytes = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
                if (num_bytes > 0) {
                    printf("%s", buffer);
                } else {
                    perror("Unable to receive message contents");
                    exit(1);
                }

                token = strtok(NULL, " ");
            }
        } else {
            printf("No unseen messages.\n");
        }
    } else {
        perror("Unable to receive search response");
        exit(1);
    }

    // send logout command
    char logout_cmd[BUFFER_SIZE];
    sprintf(logout_cmd, "LOGOUT\r\n");
    send(sockfd, logout_cmd, strlen(logout_cmd), 0);

    // receive logout response
    memset(buffer, 0, BUFFER_SIZE);
    num_bytes = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (num_bytes > 0) {
        printf("%s", buffer);
    } else {
        perror("Unable to receive logout response");
        exit(1);
    }

    close(sockfd);
    freeaddrinfo(res);

    return 0;
}