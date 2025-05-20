//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOSTS 10
#define MAX_DATA 1024

int main(int argc, char *argv[]) {
    int i, j, num_hosts;
    int sockets[MAX_HOSTS];
    struct hostent *hosts[MAX_HOSTS];
    char data[MAX_DATA];

    if (argc < 3) {
        printf("Usage: %s host1 [host2...]\n", argv[0]);
        return 1;
    }

    num_hosts = 0;
    for (i = 2; i < argc; i++) {
        if (num_hosts >= MAX_HOSTS) {
            printf("Too many hosts specified.\n");
            return 1;
        }
        hosts[num_hosts] = gethostbyname(argv[i]);
        if (hosts[num_hosts] == NULL) {
            printf("Host not found: %s\n", argv[i]);
            return 1;
        }
        num_hosts++;
    }

    for (i = 0; i < num_hosts; i++) {
        sockets[i] = socket(AF_INET, SOCK_STREAM, 0);
        if (sockets[i] == -1) {
            printf("Failed to create socket: %s\n", strerror(errno));
            return 1;
        }
    }

    for (i = 0; i < num_hosts; i++) {
        if (connect(sockets[i], (struct sockaddr *)hosts[i]->h_addr, hosts[i]->h_length) == -1) {
            printf("Failed to connect to host: %s\n", strerror(errno));
            close(sockets[i]);
            sockets[i] = -1;
        }
    }

    for (i = 0; i < num_hosts; i++) {
        if (sockets[i]!= -1) {
            memset(data, 'A', MAX_DATA);
            if (send(sockets[i], data, MAX_DATA, 0) == -1) {
                printf("Failed to send data to host: %s\n", strerror(errno));
                close(sockets[i]);
                sockets[i] = -1;
            }
        }
    }

    for (i = 0; i < num_hosts; i++) {
        if (sockets[i]!= -1) {
            memset(data, 0, MAX_DATA);
            if (recv(sockets[i], data, MAX_DATA, 0) == -1) {
                printf("Failed to receive data from host: %s\n", strerror(errno));
                close(sockets[i]);
                sockets[i] = -1;
            } else {
                printf("Received data from host: %s\n", data);
            }
        }
    }

    for (i = 0; i < num_hosts; i++) {
        if (sockets[i]!= -1) {
            close(sockets[i]);
        }
    }

    return 0;
}