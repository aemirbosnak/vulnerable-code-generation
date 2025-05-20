//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int sock, err, ret;
    struct sockaddr_in server;
    int count = 0;
    int max_count = atoi(argv[1]);
    int timeout = 500; // 500ms
    char buffer[1024];
    time_t start_time, end_time;
    double elapsed_time;

    if (argc!= 2) {
        printf("Usage: %s <max_count>\n", argv[0]);
        exit(1);
    }

    if (max_count <= 0) {
        printf("Error: max_count must be greater than zero.\n");
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: failed to create socket.\n");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);
    server.sin_port = htons(1234);

    ret = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (ret == -1) {
        printf("Error: failed to connect to server.\n");
        exit(1);
    }

    start_time = time(NULL);

    while (count < max_count) {
        ret = send(sock, "PING", strlen("PING"), 0);
        if (ret == -1) {
            printf("Error: failed to send PING.\n");
            close(sock);
            exit(1);
        }

        ret = recv(sock, buffer, sizeof(buffer), 0);
        if (ret == -1) {
            printf("Error: failed to receive PONG.\n");
            close(sock);
            exit(1);
        }

        if (strncmp(buffer, "PONG", strlen("PONG"))!= 0) {
            printf("Error: received invalid response.\n");
            close(sock);
            exit(1);
        }

        count++;
        usleep(timeout * 1000);
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    printf("Sent %d PINGs and received %d PONGs in %.2f seconds.\n", max_count, count, elapsed_time);

    close(sock);
    return 0;
}