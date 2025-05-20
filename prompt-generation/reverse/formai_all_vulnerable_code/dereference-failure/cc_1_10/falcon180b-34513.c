//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_PINGS 10
#define PING_INTERVAL 1
#define PING_TIMEOUT 5

int main(int argc, char *argv[]) {
    int sock, ret, i;
    struct sockaddr_in server_addr;
    char buffer[1024];
    double avg_ping, std_deviation;
    int ping_count = 0;
    int pings_sent = 0;
    int pings_received = 0;
    struct timeval start_time, end_time, diff_time;

    if (argc!= 3) {
        printf("Usage:./ping_test <IP address> <number of pings>\n");
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    server_addr.sin_port = htons(12345);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    gettimeofday(&start_time, NULL);

    for (i = 1; i <= atoi(argv[2]); i++) {
        send(sock, "PING", strlen("PING"), 0);
        ret = recv(sock, buffer, sizeof(buffer), 0);
        if (ret > 0) {
            pings_received++;
            gettimeofday(&end_time, NULL);
            timersub(&end_time, &start_time, &diff_time);
            ping_count += ret;
        }
    }

    close(sock);

    avg_ping = (double)ping_count / pings_received;
    std_deviation = sqrt((double)ping_count / pings_received - avg_ping * avg_ping);

    printf("Average Ping: %.2f ms\n", avg_ping);
    printf("Standard Deviation: %.2f ms\n", std_deviation);

    return 0;
}