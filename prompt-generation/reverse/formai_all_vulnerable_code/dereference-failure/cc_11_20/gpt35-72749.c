//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <signal.h>
#include <time.h>

#define MAX_BUFFER_SIZE 65536
#define INTERVAL 1

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    int fd, error_code;
    struct addrinfo hints, *result, *rp;
    int backlog = 10;
    char buffer[MAX_BUFFER_SIZE];
    
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    
    if ((error_code = getaddrinfo(NULL, argv[1], &hints, &result)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(error_code));
        exit(EXIT_FAILURE);
    }
    
    for (rp = result; rp != NULL; rp = rp->ai_next) {
        fd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (fd == -1) {
            continue;
        }
        
        if (bind(fd, rp->ai_addr, rp->ai_addrlen) == 0) {
            break;
        }
        
        close(fd);
    }
    
    if (rp == NULL) {
        fprintf(stderr, "Could not bind to address\n");
        exit(EXIT_FAILURE);
    }
    
    freeaddrinfo(result);
    
    if (listen(fd, backlog) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    struct sockaddr_storage client_addr;
    socklen_t addr_size = sizeof(struct sockaddr_storage);
    int client_fd;
    double bandwidth, jitters, packet_loss;
    int packet_count = 0, packet_lost = 0;
    struct timespec start_time, end_time;
    
    fd_set read_fds, master_fds;
    FD_ZERO(&master_fds);
    FD_SET(fd, &master_fds);
    
    while (1) {
        read_fds = master_fds;
        if (select(FD_SETSIZE, &read_fds, NULL, NULL, NULL) == -1) {
            perror("select");
            exit(EXIT_FAILURE);
        }
        
        for (int i = 0; i < FD_SETSIZE; i++) {
            if (FD_ISSET(i, &read_fds)) {
                if (i == fd) {
                    client_fd = accept(fd, (struct sockaddr *)&client_addr, &addr_size);
                    if (client_fd == -1) {
                        perror("accept");
                        exit(EXIT_FAILURE);
                    }
                    FD_SET(client_fd, &master_fds);
                } else {
                    clock_gettime(CLOCK_MONOTONIC, &start_time);
                    int bytes_recv = recv(i, buffer, MAX_BUFFER_SIZE, 0);
                    if (bytes_recv == -1) {
                        perror("recv");
                        exit(EXIT_FAILURE);
                    } else if (bytes_recv == 0) {
                        close(i);
                        FD_CLR(i, &master_fds);
                    } else {
                        clock_gettime(CLOCK_MONOTONIC, &end_time);
                        
                        double time_taken = ((double)(end_time.tv_sec - start_time.tv_sec) * 1e9 + (double)(end_time.tv_nsec - start_time.tv_nsec)) / 1e3;
                        double packet_size = bytes_recv * 8;
                        double packet_delay = time_taken;
                        packet_count++;
                        
                        if (packet_count > 1) {
                            bandwidth = ((packet_size * 1000) / packet_delay) / 1000;
                            jitters = jitters + (abs(time_taken - (packet_size / bandwidth)) - jitters) / packet_count;
                            packet_loss = packet_lost / packet_count;
                        }
                    }
                }
            }
        }
        
        printf("Bandwidth: %.2f kbps, Jitter: %.2f us, Packet Loss: %.2f%%\n", bandwidth, jitters, packet_loss);
        sleep(INTERVAL);
    }
    
    close(fd);
    return 0;
}