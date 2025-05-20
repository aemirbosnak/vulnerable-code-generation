//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define MAX_HOSTS 10

struct host_info {
    char *hostname;
    int sockfd;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname [hostname...]\n", argv[0]);
        exit(1);
    }

    int num_hosts = argc - 1;
    struct host_info hosts[MAX_HOSTS];

    for (int i = 0; i < num_hosts; i++) {
        hosts[i].hostname = argv[i+1];
        hosts[i].sockfd = -1;
    }

    int max_sockfd = -1;

    for (int i = 0; i < num_hosts; i++) {
        hosts[i].sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (hosts[i].sockfd == -1) {
            fprintf(stderr, "Error: Failed to create socket for %s: %s\n",
                    hosts[i].hostname, strerror(errno));
            exit(1);
        }

        if (max_sockfd == -1 || hosts[i].sockfd > max_sockfd) {
            max_sockfd = hosts[i].sockfd;
        }
    }

    fd_set read_fds;
    FD_ZERO(&read_fds);

    for (int i = 0; i < num_hosts; i++) {
        FD_SET(hosts[i].sockfd, &read_fds);
    }

    int num_connected = 0;

    while (num_connected < num_hosts) {
        int retval = select(max_sockfd + 1, &read_fds, NULL, NULL, NULL);
        if (retval == -1) {
            fprintf(stderr, "Error: Failed to select: %s\n", strerror(errno));
            exit(1);
        }

        for (int i = 0; i < num_hosts; i++) {
            if (FD_ISSET(hosts[i].sockfd, &read_fds)) {
                char buffer[BUF_SIZE];
                int bytes_received = recv(hosts[i].sockfd, buffer, BUF_SIZE, 0);
                if (bytes_received <= 0) {
                    fprintf(stderr, "Error: Failed to receive data from %s: %s\n",
                            hosts[i].hostname, strerror(errno));
                    close(hosts[i].sockfd);
                    hosts[i].sockfd = -1;
                } else {
                    fprintf(stdout, "Received data from %s:\n%s",
                            hosts[i].hostname, buffer);
                }
            }
        }
    }

    for (int i = 0; i < num_hosts; i++) {
        if (hosts[i].sockfd!= -1) {
            close(hosts[i].sockfd);
        }
    }

    return 0;
}