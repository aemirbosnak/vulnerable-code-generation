//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX 100
#define PORT 8080

int main(int argc, char *argv[]) {
    int sock, valread, sd;
    struct sockaddr_in serv_addr;
    char senddata[1024] = "GET / HTTP/1.1\r\n";
    char recvdata[1024];
    int addrlen = sizeof(serv_addr);
    int max = 3;
    int min = 1;
    int avg = 0;
    int sum = 0;
    int count = 0;
    int i;
    double result;
    time_t start, end;

    if (argc < 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < max; i++) {
        start = time(NULL);
        send(sock, senddata, strlen(senddata), 0);
        sd = accept(sock, (struct sockaddr *)&serv_addr, (socklen_t*)&addrlen);
        if (sd < 0) {
            printf("Failed to accept\n");
            exit(EXIT_FAILURE);
        }
        recv(sd, recvdata, sizeof(recvdata), 0);
        end = time(NULL);
        close(sd);
        result = difftime(end, start);
        sum += result;
        count++;
    }

    avg = sum / count;
    printf("Average response time: %.2lf ms\n", avg);

    return 0;
}