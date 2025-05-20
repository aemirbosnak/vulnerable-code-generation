//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define MAX_SERVERS 10
#define TIMEOUT 1

typedef struct {
    char ip[16];
    int port;
} Server;

typedef struct {
    double response_time;
    int status_code;
} QoS_Result;

void print_result(Server server, QoS_Result result) {
    printf("Server: %s:%d - Response Time: %.2f ms, Status Code: %d\n",
           server.ip, server.port, result.response_time, result.status_code);
}

QoS_Result measure_qos(Server server) {
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];
    QoS_Result result;
    result.response_time = 0.0;
    result.status_code = 0;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation error");
        return result;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server.port);
    if (inet_pton(AF_INET, server.ip, &server_address.sin_addr) <= 0) {
        perror("Invalid address");
        close(sockfd);
        return result;
    }

    // Non-blocking socket for timeout control
    fcntl(sockfd, F_SETFL, O_NONBLOCK);
    clock_t start = clock();

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        if (errno != EINPROGRESS) {
            perror("Connection failed");
            close(sockfd);
            return result;
        }

        fd_set fdset;
        struct timeval tv;

        // Set timeout
        tv.tv_sec = TIMEOUT;
        tv.tv_usec = 0;

        FD_SET(sockfd, &fdset);
        int return_code = select(sockfd + 1, NULL, &fdset, NULL, &tv);
        if (return_code > 0) {
            socklen_t len = sizeof(result.status_code);
            if (getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &result.status_code, &len) < 0) {
                perror("getsockopt failed");
                result.status_code = 0;
            } else {
                result.status_code = (result.status_code == 0) ? 200 : result.status_code;
            }
            clock_t end = clock();
            result.response_time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000; // milliseconds
        }
    }

    close(sockfd);
    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    Server servers[MAX_SERVERS];
    int server_count = 0;

    // Read server information from file
    while (fscanf(file, "%15s %d", servers[server_count].ip, &servers[server_count].port) == 2) {
        if (server_count >= MAX_SERVERS) {
            fprintf(stderr, "Reached maximum server limit of %d\n", MAX_SERVERS);
            break;
        }
        server_count++;
    }
    fclose(file);

    for (int i = 0; i < server_count; ++i) {
        QoS_Result result = measure_qos(servers[i]);
        print_result(servers[i], result);
    }

    return 0;
}