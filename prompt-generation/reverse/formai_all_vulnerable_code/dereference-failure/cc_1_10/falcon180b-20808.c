//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <netdb.h>

#define MAX 65535
#define CHECK_PORT 80

int main(int argc, char *argv[]) {
    int sock, port;
    struct sockaddr_in server;
    char hostname[50];
    int hostlen;
    char *ptr;
    int i;

    if (argc!= 2) {
        printf("Usage:./portscanner <hostname>\n");
        exit(1);
    }

    strcpy(hostname, argv[1]);

    hostlen = strlen(hostname);

    if ((ptr = strrchr(hostname, '.'))!= NULL) {
        *ptr = '\0';
    }

    if (hostlen < 1 || hostlen > 50) {
        printf("Invalid hostname!\n");
        exit(1);
    }

    for (i = 1; i <= MAX; i++) {
        if (i == CHECK_PORT)
            continue;

        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
            perror("socket failed");
            exit(EXIT_FAILURE);
        }

        server.sin_family = AF_INET;
        server.sin_addr.s_addr = inet_addr(hostname);
        server.sin_port = htons(i);

        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open.\n", i);
            close(sock);
        } else {
            printf("Port %d is closed.\n", i);
            close(sock);
        }
    }

    return 0;
}