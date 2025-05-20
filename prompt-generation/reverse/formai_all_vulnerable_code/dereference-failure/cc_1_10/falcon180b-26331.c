//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/resource.h>

#define SERVER "speedtest.net"
#define PORT 80

int main(void) {
    int sockfd;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    int opt = 1;
    char buffer[1024];
    char send_data[1024];
    int bytes_read, bytes_written;
    struct timeval start, end;
    double elapsed_time;
    double speed;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("Error setting socket option\n");
        exit(1);
    }

    if ((server = gethostbyname(SERVER)) == NULL) {
        printf("Error getting host by name\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    send(sockfd, "GET / HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n"), 0);

    while ((bytes_read = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        send_data[bytes_read - 1] = '\0';
        strcat(send_data, buffer);
    }

    close(sockfd);

    gettimeofday(&start, NULL);
    send_data[bytes_read - 1] = '\0';
    send(sockfd, send_data, strlen(send_data), 0);
    gettimeofday(&end, NULL);

    elapsed_time = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
    speed = (double)bytes_read / elapsed_time;

    printf("Internet speed: %.2f kbps\n", speed / 1024);

    return 0;
}