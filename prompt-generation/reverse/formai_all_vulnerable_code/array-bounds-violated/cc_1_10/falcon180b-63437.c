//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct hostent *host;
    struct sockaddr_in server;
    char username[50];
    char password[50];
    char command[100];
    char response[BUFSIZE];
    int port = 110;
    int n;

    if (argc!= 5) {
        printf("Usage: %s <hostname> <username> <password> <command>\n", argv[0]);
        exit(1);
    }

    strcpy(username, argv[2]);
    strcpy(password, argv[3]);
    strcpy(command, argv[4]);

    if ((host = gethostbyname(argv[1])) == NULL) {
        printf("Error: Invalid hostname\n");
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error: Failed to create socket\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1) {
        printf("Error: Failed to connect to server\n");
        exit(1);
    }

    sprintf(command, "USER %s\r\n", username);
    send(sock, command, strlen(command), 0);

    n = recv(sock, response, BUFSIZE, 0);
    response[n] = '\0';

    if (strncmp(response, "+OK", 3)!= 0) {
        printf("Error: Invalid username or password\n");
        exit(1);
    }

    sprintf(command, "PASS %s\r\n", password);
    send(sock, command, strlen(command), 0);

    n = recv(sock, response, BUFSIZE, 0);
    response[n] = '\0';

    if (strncmp(response, "+OK", 3)!= 0) {
        printf("Error: Invalid username or password\n");
        exit(1);
    }

    sprintf(command, "%s\r\n", argv[4]);
    send(sock, command, strlen(command), 0);

    n = recv(sock, response, BUFSIZE, 0);
    response[n] = '\0';

    printf("Response: %s\n", response);

    close(sock);

    return 0;
}