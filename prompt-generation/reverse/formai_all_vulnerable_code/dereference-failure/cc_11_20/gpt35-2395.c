//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

#define MAX_LINE_LENGTH 1024
#define IMAP_PORT 143

int main(int argc, char *argv[]) {
    char *hostname;
    char *username;
    char *password;

    if (argc != 4) {
        fprintf(stderr, "Error: expected 3 arguments\n");
        exit(1);
    } else {
        hostname = argv[1];
        username = argv[2];
        password = argv[3];
    }

    struct hostent *he;
    if ((he = gethostbyname(hostname)) == NULL) {
        perror("Error: failed to resolve hostname");
        exit(2);
    }

    int server_socket;
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error: failed to create socket");
        exit(3);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(IMAP_PORT);
    server_address.sin_addr = *((struct in_addr *) he->h_addr);
    memset(&(server_address.sin_zero), '\0', 8);

    if (connect(server_socket,
                (struct sockaddr *)&server_address,
                sizeof(struct sockaddr)) == -1) {
        perror("Error: failed to connect to server");
        exit(4);
    }

    char buffer[MAX_LINE_LENGTH];
    memset(buffer, '\0', MAX_LINE_LENGTH);

    ssize_t bytes = recv(server_socket, buffer, MAX_LINE_LENGTH - 1, 0);
    if (bytes == -1) {
        perror("Error: failed to receive greeting from server");
        exit(5);
    }

    printf("Received: %s", buffer);

    snprintf(buffer, MAX_LINE_LENGTH,
             "a001 LOGIN %s %s\r\n", username, password);

    if (send(server_socket, buffer, strlen(buffer), 0) == -1) {
        perror("Error: failed to send login command to server");
        exit(6);
    }

    memset(buffer, '\0', MAX_LINE_LENGTH);

    bytes = recv(server_socket, buffer, MAX_LINE_LENGTH - 1, 0);
    if (bytes == -1) {
        perror("Error: failed to receive response to login command");
        exit(7);
    }

    printf("Received: %s", buffer);

    snprintf(buffer, MAX_LINE_LENGTH,
             "a002 SELECT INBOX\r\n");

    if (send(server_socket, buffer, strlen(buffer), 0) == -1) {
        perror("Error: failed to send select command to server");
        exit(8);
    }

    memset(buffer, '\0', MAX_LINE_LENGTH);

    bytes = recv(server_socket, buffer, MAX_LINE_LENGTH - 1, 0);
    if (bytes == -1) {
        perror("Error: failed to receive response to select command");
        exit(9);
    }

    printf("Received: %s", buffer);

    snprintf(buffer, MAX_LINE_LENGTH,
             "a003 FETCH 1:* (FLAGS BODY[HEADER.FIELDS (FROM SUBJECT DATE)])\r\n");

    if (send(server_socket, buffer, strlen(buffer), 0) == -1) {
        perror("Error: failed to send fetch command to server");
        exit(10);
    }

    memset(buffer, '\0', MAX_LINE_LENGTH);

    while (recv(server_socket, buffer, MAX_LINE_LENGTH - 1, 0) > 0) {
        printf("%s", buffer);
        memset(buffer, '\0', MAX_LINE_LENGTH);
    }

    snprintf(buffer, MAX_LINE_LENGTH,
             "a004 LOGOUT\r\n");

    if (send(server_socket, buffer, strlen(buffer), 0) == -1) {
        perror("Error: failed to send logout command to server");
        exit(11);
    }

    close(server_socket);
    return 0;
}