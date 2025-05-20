//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>

#define PORT 8080

void handle_sig(int signum) {
    printf("Caught signal %d\n", signum);
    exit(1);
}

int main() {
    int sockfd, n;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    char buf[1024];
    int i = 0;

    signal(SIGINT, handle_sig);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind failed");
        exit(1);
    }

    if (listen(sockfd, 5) == -1) {
        perror("listen failed");
        exit(1);
    }

    while (1) {
        clilen = sizeof(cli_addr);
        if ((n = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen)) == -1) {
            perror("accept failed");
            exit(1);
        }

        printf("Connection from %s\n", inet_ntoa(cli_addr.sin_addr));

        for (;;) {
            if ((n = recv(sockfd, buf, 1024, 0)) == -1) {
                perror("recv failed");
                exit(1);
            }

            if (n == 0) {
                printf("Client disconnected\n");
                close(sockfd);
                break;
            }

            buf[n] = '\0';
            printf("Received: %s\n", buf);
            send(sockfd, "ACK\n", strlen("ACK\n"), 0);
        }

        close(sockfd);
    }

    return 0;
}