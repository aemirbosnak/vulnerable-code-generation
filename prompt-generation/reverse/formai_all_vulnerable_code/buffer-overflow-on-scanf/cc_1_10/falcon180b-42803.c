//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 1024
#define POP3_PORT 110

int main(int argc, char *argv[]) {

    char server[MAX_LINE];
    char username[MAX_LINE];
    char password[MAX_LINE];
    char command[MAX_LINE];
    char response[MAX_LINE];
    char *ptr;
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *host;
    int port;
    int ret;

    // Get server, username, and password from user
    printf("Enter POP3 server address: ");
    scanf("%s", server);
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Connect to server
    host = gethostbyname(server);
    if (host == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;
    ret = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Authenticate with server
    sprintf(command, "USER %s\r\n", username);
    send(sock, command, strlen(command), 0);
    ret = recv(sock, response, MAX_LINE, 0);
    if (ret <= 0) {
        printf("Error receiving response\n");
        exit(1);
    }
    response[ret] = '\0';
    printf("Server response: %s", response);

    sprintf(command, "PASS %s\r\n", password);
    send(sock, command, strlen(command), 0);
    ret = recv(sock, response, MAX_LINE, 0);
    if (ret <= 0) {
        printf("Error receiving response\n");
        exit(1);
    }
    response[ret] = '\0';
    printf("Server response: %s", response);

    // List messages on server
    sprintf(command, "LIST\r\n");
    send(sock, command, strlen(command), 0);
    ret = recv(sock, response, MAX_LINE, 0);
    if (ret <= 0) {
        printf("Error receiving response\n");
        exit(1);
    }
    response[ret] = '\0';
    printf("Server response: %s", response);

    // Close connection
    close(sock);

    return 0;
}