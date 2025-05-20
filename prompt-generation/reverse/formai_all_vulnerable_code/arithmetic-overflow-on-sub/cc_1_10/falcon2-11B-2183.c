//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

// Function to print error message and exit program
void error(const char *msg) {
    perror(msg);
    exit(1);
}

// Function to monitor network quality of service
int monitor_qos(int socket, int interval) {
    int total_bytes = 0;
    int bytes_per_second = 0;
    int start_time = 0;
    int end_time = 0;

    start_time = time(NULL);
    while (1) {
        end_time = time(NULL);
        int bytes_received = recv(socket, NULL, 0, 0);
        if (bytes_received == -1) {
            error("Error receiving data");
        }
        total_bytes += bytes_received;
        int bytes_per_second = total_bytes / (end_time - start_time);
        start_time = end_time;

        if (interval > 0 && (end_time - start_time) > interval) {
            printf("Average bytes per second: %d\n", bytes_per_second);
            fflush(stdout);
            start_time = end_time;
        }

        usleep(interval * 1000);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        error("Error creating socket");
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    server_address.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        error("Error connecting to server");
    }

    int interval = atoi(argv[2]);

    if (interval <= 0) {
        interval = 100;
    }

    if (monitor_qos(socket_fd, interval) == -1) {
        error("Error monitoring network quality of service");
    }

    close(socket_fd);
    return 0;
}