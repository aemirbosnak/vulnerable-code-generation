//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <netdb.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char message[MAX_SIZE];
    int len;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    host = gethostbyname("localhost");
    if (host == NULL) {
        herror("gethostbyname");
        exit(1);
    }

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy(host->h_addr, &server_addr.sin_addr, host->h_length);
    server_addr.sin_port = htons(1234);

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    while (1) {
        bzero(message, MAX_SIZE);
        printf("Enter message: ");
        fgets(message, MAX_SIZE, stdin);
        len = strlen(message);
        send(sock, message, len, 0);

        bzero(message, MAX_SIZE);
        len = recv(sock, message, MAX_SIZE, 0);
        if (len <= 0) {
            printf("Disconnected\n");
            break;
        }
        message[len] = '\0';
        printf("Received message: %s\n", message);
    }

    close(sock);
    exit(0);
}