//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define MAX_RETRY 5
#define TIMEOUT 2

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    int addrlen = sizeof(server_addr);
    char buffer[BUFFER_SIZE];
    int ret;
    int count = 0;
    int max_count = atoi(argv[2]);
    time_t start_time, end_time;
    double elapsed_time;

    if (argc!= 4) {
        printf("Usage: %s <IP Address> <Max Retry Count>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    ret = connect(sock, (struct sockaddr *)&server_addr, addrlen);
    if (ret == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    start_time = time(NULL);
    while (count < max_count) {
        ret = send(sock, "PING", strlen("PING"), 0);
        if (ret == -1) {
            printf("Error sending data\n");
            exit(1);
        }

        ret = recv(sock, buffer, BUFFER_SIZE, 0);
        if (ret == -1) {
            printf("Error receiving data\n");
            exit(1);
        }

        if (strncmp(buffer, "PONG", strlen("PONG")) == 0) {
            count++;
        } else {
            printf("Invalid response received\n");
        }

        if (count >= max_count) {
            break;
        }

        usleep(100000); // Sleep for 100ms
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    printf("Total time taken: %.2f seconds\n", elapsed_time);

    close(sock);
    return 0;
}