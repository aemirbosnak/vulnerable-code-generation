//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 25
#define BUFLEN 512

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <hostname> <message>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    char *message = argv[2];

    struct hostent *host;
    struct sockaddr_in server;
    int sock;
    char buffer[BUFLEN];

    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error: Unable to resolve hostname %s\n", hostname);
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Unable to create socket\n");
        return 1;
    }

    server.sin_addr = *((struct in_addr *) host->h_addr);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == -1) {
        printf("Error: Unable to connect to host %s\n", hostname);
        return 1;
    }

    send(sock, message, strlen(message), 0);
    recv(sock, buffer, BUFLEN, 0);

    printf("Received response: %s\n", buffer);

    close(sock);
    return 0;
}