//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_DATA_SIZE 1024
#define PING_TIMEOUT 5 // seconds

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char data[MAX_DATA_SIZE];
    int data_size;
    int timeout;
    int ret;
    int i;
    struct timespec ts;
    double elapsed_time;

    if (argc!= 3) {
        printf("Usage:./ping <IP address> <port number>\n");
        return 1;
    }

    timeout = PING_TIMEOUT;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    ret = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        return 1;
    }

    printf("Connected to server\n");

    for (i = 0; i < 5; i++) {
        ret = send(sock, "PING", strlen("PING"), 0);
        if (ret == -1) {
            printf("Error sending PING: %s\n", strerror(errno));
            return 1;
        }

        ret = recv(sock, data, MAX_DATA_SIZE, 0);
        if (ret == -1) {
            printf("Error receiving data: %s\n", strerror(errno));
            return 1;
        }

        data_size = ret;
        data[data_size] = '\0';
        printf("PING %d: %s\n", i+1, data);

        if (strncmp(data, "PONG", strlen("PONG"))!= 0) {
            printf("Error: received unexpected data\n");
            return 1;
        }

        if (i == 0) {
            clock_gettime(CLOCK_REALTIME, &ts);
        }
    }

    elapsed_time = (double)ts.tv_sec + (double)ts.tv_nsec / 1000000000;
    printf("Average response time: %.3f seconds\n", elapsed_time / 5.0);

    close(sock);
    return 0;
}