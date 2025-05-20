//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: innovative
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    struct timeval start, end;

    if (argc!= 2) {
        printf("Usage: %s <server_ip>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    gettimeofday(&start, NULL);
    send(sockfd, "GET / HTTP/1.1\r\nHost: 127.0.0.1\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: 127.0.0.1\r\n\r\n"), 0);

    while ((n = recv(sockfd, buffer, 1024, 0)) > 0) {
        if (n == 0) {
            printf("Connection closed by server\n");
            break;
        }
        printf("%s", buffer);
    }

    gettimeofday(&end, NULL);
    printf("Time taken: %ld microseconds\n", (end.tv_usec - start.tv_usec) + (end.tv_sec - start.tv_sec) * 1000000);

    close(sockfd);
    return 0;
}