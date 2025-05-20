//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *pop3_server = "pop3.example.com";
    int pop3_port = 110;
    char *username = "user@example.com";
    char *password = "password";

    int sockfd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    struct hostent *server;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    // get server address
    server = gethostbyname(pop3_server);
    if (server == NULL) {
        perror("ERROR getting server by name");
        return 1;
    }

    // fill in server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(pop3_port);

    // connect to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR connecting to server");
        return 1;
    }

    // read greeting message from server
    if (read(sockfd, buffer, BUFFER_SIZE - 1) < 0) {
        perror("ERROR reading from socket");
        return 1;
    }
    printf("%s\n", buffer);

    // send username
    snprintf(buffer, BUFFER_SIZE, "USER %s\r\n", username);
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("ERROR writing to socket");
        return 1;
    }
    if (read(sockfd, buffer, BUFFER_SIZE - 1) < 0) {
        perror("ERROR reading from socket");
        return 1;
    }
    printf("%s\n", buffer);

    // send password
    snprintf(buffer, BUFFER_SIZE, "PASS %s\r\n", password);
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("ERROR writing to socket");
        return 1;
    }
    if (read(sockfd, buffer, BUFFER_SIZE - 1) < 0) {
        perror("ERROR reading from socket");
        return 1;
    }
    printf("%s\n", buffer);

    // send command to list messages
    snprintf(buffer, BUFFER_SIZE, "LIST\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("ERROR writing to socket");
        return 1;
    }
    if (read(sockfd, buffer, BUFFER_SIZE - 1) < 0) {
        perror("ERROR reading from socket");
        return 1;
    }
    printf("%s", buffer);

    // extract message count from response
    int message_count;
    sscanf(buffer, "+OK %d", &message_count);

    // read each message
    for (int i = 1; i <= message_count; i++) {
        // send command to retrieve message
        snprintf(buffer, BUFFER_SIZE, "RETR %d\r\n", i);
        if (write(sockfd, buffer, strlen(buffer)) < 0) {
            perror("ERROR writing to socket");
            return 1;
        }
        memset(buffer, '\0', BUFFER_SIZE);

        // read message header
        if (read(sockfd, buffer, BUFFER_SIZE - 1) < 0) {
            perror("ERROR reading from socket");
            return 1;
        }
        printf("%s", buffer);

        // read message body
        memset(buffer, '\0', BUFFER_SIZE);
        while (read(sockfd, buffer, BUFFER_SIZE - 1)) {
            printf("%s", buffer);
            if (strstr(buffer, ".\r\n")) {
                break;
            }
            memset(buffer, '\0', BUFFER_SIZE);
        }
        printf("\n");
    }

    // send command to quit session
    snprintf(buffer, BUFFER_SIZE, "QUIT\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("ERROR writing to socket");
        return 1;
    }
    if (read(sockfd, buffer, BUFFER_SIZE - 1) < 0) {
        perror("ERROR reading from socket");
        return 1;
    }
    printf("%s\n", buffer);

    // close socket
    close(sockfd);

    return 0;
}