//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_RESPONSE_LENGTH 10240
#define POP3_PORT 110
#define POP3_USER "post-apocalyptic survivor"
#define POP3_PASS "password123"

int main(int argc, char **argv) {
    int sock;
    struct hostent *host;
    struct sockaddr_in server;
    char command[MAX_COMMAND_LENGTH];
    char response[MAX_RESPONSE_LENGTH];
    int bytes_received;
    int status;

    // Connect to POP3 server
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    host = gethostbyname("localhost");
    if (host == NULL) {
        printf("Error resolving host.\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(POP3_PORT);
    server.sin_addr = *(struct in_addr *)host->h_addr;

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server.\n");
        exit(1);
    }

    // Login to POP3 server
    sprintf(command, "USER %s\r\n", POP3_USER);
    send(sock, command, strlen(command), 0);

    bytes_received = recv(sock, response, MAX_RESPONSE_LENGTH, 0);
    response[bytes_received] = '\0';
    printf("Server response: %s", response);

    sprintf(command, "PASS %s\r\n", POP3_PASS);
    send(sock, command, strlen(command), 0);

    bytes_received = recv(sock, response, MAX_RESPONSE_LENGTH, 0);
    response[bytes_received] = '\0';
    printf("Server response: %s", response);

    // List messages on server
    sprintf(command, "LIST\r\n");
    send(sock, command, strlen(command), 0);

    bytes_received = recv(sock, response, MAX_RESPONSE_LENGTH, 0);
    response[bytes_received] = '\0';
    printf("Server response: %s", response);

    // Close connection to server
    close(sock);

    return 0;
}