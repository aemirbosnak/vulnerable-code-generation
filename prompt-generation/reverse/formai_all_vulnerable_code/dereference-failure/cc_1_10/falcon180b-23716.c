//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

#define BUF_SIZE 1024
#define MAX_HOSTS 10

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <host> [<host>...]\n", argv[0]);
        return 1;
    }

    int num_hosts = 0;
    char *hosts[MAX_HOSTS];
    for (int i = 2; i < argc; i++) {
        if (num_hosts >= MAX_HOSTS) {
            printf("Error: Too many hosts specified\n");
            return 1;
        }
        hosts[num_hosts++] = argv[i];
    }

    printf("Pinging hosts:\n");
    for (int i = 0; i < num_hosts; i++) {
        char hostname[1024];
        strcpy(hostname, hosts[i]);
        struct hostent *host = gethostbyname(hostname);
        if (host == NULL) {
            printf("%s: Unknown host\n", hosts[i]);
            continue;
        }

        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            printf("%s: Error creating socket: %s\n", hosts[i], strerror(errno));
            continue;
        }

        struct sockaddr_in sin;
        memset(&sin, 0, sizeof(sin));
        sin.sin_family = AF_INET;
        sin.sin_port = htons(7);
        sin.sin_addr.s_addr = *(unsigned long *)host->h_addr;

        if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) == -1) {
            printf("%s: Connection failed: %s\n", hosts[i], strerror(errno));
            close(sock);
            continue;
        }

        char buf[BUF_SIZE];
        snprintf(buf, BUF_SIZE, "PING %s\r\n", hosts[i]);
        send(sock, buf, strlen(buf), 0);

        int bytes_received = 0;
        char response[BUF_SIZE];
        while (bytes_received < BUF_SIZE) {
            int n = recv(sock, response + bytes_received, BUF_SIZE - bytes_received, 0);
            if (n <= 0) {
                printf("%s: Ping failed\n", hosts[i]);
                close(sock);
                break;
            }
            bytes_received += n;
        }

        response[bytes_received] = '\0';
        printf("%s: %s\n", hosts[i], response);
        close(sock);
    }

    return 0;
}