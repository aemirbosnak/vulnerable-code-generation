//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: future-proof
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <netdb.h>
    #include <unistd.h>
    #include <errno.h>

    #define PING_BUFFER_SIZE 64
    #define PING_TIMEOUT_MS 1000

    int main(int argc, char *argv[]) {
        int sockfd, n;
        char buffer[PING_BUFFER_SIZE];
        struct sockaddr_in server;
        struct hostent *server_info;

        if (argc < 2) {
            fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
            exit(1);
        }

        if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
            perror("socket");
            exit(1);
        }

        if ((server_info = gethostbyname(argv[1])) == NULL) {
            fprintf(stderr, "Unknown host: %s\n", argv[1]);
            exit(1);
        }

        memset(&server, 0, sizeof(server));
        server.sin_family = AF_INET;
        server.sin_port = htons(1234);
        server.sin_addr.s_addr = *((unsigned long *)server_info->h_addr);

        if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
            perror("connect");
            exit(1);
        }

        memset(buffer, 0, PING_BUFFER_SIZE);
        n = send(sockfd, buffer, PING_BUFFER_SIZE, 0);
        if (n < 0) {
            perror("send");
            exit(1);
        }

        n = recv(sockfd, buffer, PING_BUFFER_SIZE, 0);
        if (n < 0) {
            perror("recv");
            exit(1);
        }

        printf("Received %d bytes: %s\n", n, buffer);

        close(sockfd);
        return 0;
    }