//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define MAX_ATTEMPTS 5
#define TIME_OUT 5

void print_usage(char *program) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", program);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage(argv[0]);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);
    int sockfd, retval;
    struct sockaddr_in server_addr;
    int attempts = 0;
    int status = 0;
    time_t start_time, end_time;
    double elapsed_time;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket creation failed");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr))!= 0) {
        perror("connection failed");
        exit(1);
    }

    start_time = time(NULL);
    while (attempts < MAX_ATTEMPTS && (retval = send(sockfd, "PING", strlen("PING"), 0))!= strlen("PING")) {
        attempts++;
        usleep(100000);
    }

    if (retval == strlen("PING")) {
        status = 1;
    } else {
        status = 0;
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    if (status) {
        printf("Host %s is alive\n", hostname);
        printf("Round trip time: %.6f seconds\n", elapsed_time);
    } else {
        printf("Host %s is not responding\n", hostname);
    }

    close(sockfd);
    return 0;
}