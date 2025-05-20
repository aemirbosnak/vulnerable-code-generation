//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int sock;
    struct hostent *host;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char *username, *password;
    int port;

    if (argc!= 5) {
        printf("Usage: %s host port username password\n", argv[0]);
        exit(1);
    }

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error: could not resolve host %s\n", argv[1]);
        exit(1);
    }

    port = atoi(argv[2]);

    username = argv[3];
    password = argv[4];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: could not create socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: could not connect to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    char auth_str[50];
    sprintf(auth_str, "USER %s\r\n", username);
    send(sock, auth_str, strlen(auth_str), 0);

    char pass_str[50];
    sprintf(pass_str, "PASS %s\r\n", password);
    send(sock, pass_str, strlen(pass_str), 0);

    char response[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sock, response, BUFFER_SIZE, 0)) > 0) {
        response[bytes_received - 1] = '\0';
        printf("%s", response);
    }

    close(sock);
    exit(0);
}