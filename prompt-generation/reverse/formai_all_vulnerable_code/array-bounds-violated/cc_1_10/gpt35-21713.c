//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {

    if(argc != 4) {
        printf("Usage: %s server_ip username password\n", argv[0]);
        return -1;
    }

    char *server_ip = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    // Connect to the server
    struct sockaddr_in server_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;

    if(inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        printf("Invalid server IP address\n");
        return -1;
    }

    server_addr.sin_port = htons(993);

    if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Connection failed\n");
        return -1;
    }

    printf("Successfully connected to the server\n");

    // Authenticate the user
    char buffer[BUFF_SIZE];
    int len = 0;

    len = recv(sock, buffer, BUFF_SIZE, 0);
    buffer[len] = '\0';

    printf("Server: %s\n", buffer);

    sprintf(buffer, ". login %s %s\n", username, password);
    send(sock, buffer, strlen(buffer), 0);

    len = recv(sock, buffer, BUFF_SIZE, 0);
    buffer[len] = '\0';

    printf("Server: %s\n", buffer);

    if(strncmp(buffer, ". OK", 4) != 0) {
        printf("Error: Authentication failed\n");
        return -1;
    }

    // Select the mailbox
    sprintf(buffer, ". select inbox\n");
    send(sock, buffer, strlen(buffer), 0);

    len = recv(sock, buffer, BUFF_SIZE, 0);
    buffer[len] = '\0';

    printf("Server: %s\n", buffer);

    if(strncmp(buffer, ". NO", 4) == 0) {
        printf("Error: Failed to select the mailbox\n");
        return -1;
    }

    // Fetch the messages
    sprintf(buffer, ". fetch 1:* body[]\n");
    send(sock, buffer, strlen(buffer), 0);

    while(1) {
        len = recv(sock, buffer, BUFF_SIZE, 0);

        if(len <= 0) {
            break;
        }

        buffer[len] = '\0';

        printf("Server: %s\n", buffer);
    }

    // Logout and disconnect
    sprintf(buffer, ". logout\n");
    send(sock, buffer, strlen(buffer), 0);

    len = recv(sock, buffer, BUFF_SIZE, 0);
    buffer[len] = '\0';

    printf("Server: %s\n", buffer);

    close(sock);
    printf("Connection closed\n");

    return 0;
}