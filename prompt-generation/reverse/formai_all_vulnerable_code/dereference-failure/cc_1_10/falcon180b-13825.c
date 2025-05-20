//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_HOSTNAME 256
#define MAX_RECV_BUFFER 1024

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct hostent *host;
    struct sockaddr_in server_addr;
    char hostname[MAX_HOSTNAME];
    char recv_buffer[MAX_RECV_BUFFER];

    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    strcpy(hostname, argv[1]);

    if ((host = gethostbyname(hostname)) == NULL) {
        printf("Error: Host not found\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Socket creation failed\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error: Connection failed\n");
        exit(1);
    }

    printf("Connected to %s\n", hostname);

    struct rlimit rl;
    rl.rlim_cur = 1024 * 1024; // 1 MB
    rl.rlim_max = 1024 * 1024; // 1 MB
    setrlimit(RLIMIT_NOFILE, &rl);

    while (1) {
        memset(recv_buffer, 0, MAX_RECV_BUFFER);
        ret = recv(sockfd, recv_buffer, MAX_RECV_BUFFER, 0);
        if (ret == 0) {
            printf("Connection closed by server\n");
            break;
        } else if (ret == -1) {
            printf("Error: Receive failed\n");
            exit(1);
        }

        printf("Received data: %s\n", recv_buffer);
    }

    close(sockfd);

    return 0;
}