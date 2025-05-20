//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER_IP "speedtest.net"
#define SERVER_PORT 80
#define BUFFER_SIZE 1024
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_data[BUFFER_SIZE], recv_data[BUFFER_SIZE];
    long int start_time, end_time;
    double elapsed_time;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error opening socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    srand(time(NULL));
    int random_number = rand() % 1000000;

    sprintf(send_data, "GET /speedtest/%d HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n", random_number);

    send(sockfd, send_data, strlen(send_data), 0);

    start_time = clock();
    n = recv(sockfd, recv_data, BUFFER_SIZE, 0);
    end_time = clock();

    if (n <= 0) {
        printf("Error receiving data from server\n");
        exit(1);
    }

    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Elapsed time: %.2f seconds\n", elapsed_time);

    close(sockfd);
    return 0;
}