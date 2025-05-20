//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>

#define MAX_PINGS 10
#define PING_INTERVAL 1

void sig_handler(int signum) {
    if (signum == SIGINT) {
        printf("\nExiting...\n");
        exit(0);
    }
}

int ping(char *hostname) {
    int sock;
    struct hostent *host;
    struct sockaddr_in server;
    char buffer[1024];
    int bytes_received;
    int i;

    if ((host = gethostbyname(hostname)) == NULL) {
        printf("Error: could not resolve hostname.\n");
        return -1;
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error: could not create socket.\n");
        return -1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(7);
    server.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error: could not connect to host.\n");
        return -1;
    }

    for (i = 0; i < MAX_PINGS; i++) {
        send(sock, "PING", strlen("PING"), 0);
        bytes_received = recv(sock, buffer, sizeof(buffer), 0);

        if (bytes_received <= 0) {
            printf("No response from host.\n");
            close(sock);
            return -1;
        }

        if (strncmp(buffer, "PONG", strlen("PONG"))!= 0) {
            printf("Invalid response from host.\n");
            close(sock);
            return -1;
        }

        usleep(PING_INTERVAL * 1000);
    }

    close(sock);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        return -1;
    }

    signal(SIGINT, sig_handler);

    int result = ping(argv[1]);

    if (result == 0) {
        printf("Host is reachable.\n");
    } else {
        printf("Host is not reachable.\n");
    }

    return 0;
}