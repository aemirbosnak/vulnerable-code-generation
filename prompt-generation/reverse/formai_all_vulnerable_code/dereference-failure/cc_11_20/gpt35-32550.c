//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/select.h>

#define BUFFER_SIZE 1024
#define QOS_THRESHOLD 200

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s host\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    struct addrinfo *addrs;
    int status = getaddrinfo(host, NULL, &hints, &addrs);
    if (status != 0) {
        fprintf(stderr, "Error: %s\n", gai_strerror(status));
        return 1;
    }

    int sockfd = -1;
    struct addrinfo *addr;
    for (addr = addrs; addr != NULL; addr = addr->ai_next) {
        sockfd = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
        if (sockfd == -1) {
            continue;
        }

        status = connect(sockfd, addr->ai_addr, addr->ai_addrlen);
        if (status == -1) {
            close(sockfd);
            sockfd = -1;
            continue;
        }

        break;
    }

    if (sockfd == -1) {
        fprintf(stderr, "Error: could not connect to host '%s'\n", host);
        return 1;
    }

    printf("Connected to host '%s'\n", host);

    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(sockfd, &read_fds);
    int max_fds = sockfd + 1;

    printf("Monitoring network QoS...\n");

    while (1) {
        fd_set tmp_fds = read_fds;
        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        int num_fds = select(max_fds, &tmp_fds, NULL, NULL, &timeout);
        if (num_fds == -1) {
            fprintf(stderr, "Error: select() failed\n");
            break;
        }

        if (num_fds > 0) {
            char buffer[BUFFER_SIZE];
            int num_bytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
            if (num_bytes == -1) {
                fprintf(stderr, "Error: recv() failed\n");
                break;
            } else if (num_bytes == 0) {
                printf("Connection closed by host '%s'\n", host);
                break;
            }

            buffer[num_bytes] = '\0';
            printf("Received data: %s", buffer);

            if (strlen(buffer) > QOS_THRESHOLD) {
                printf("Warning: network QoS exceeded threshold of %d bytes\n", QOS_THRESHOLD);
            }
        } else {
            printf("Network QoS is within acceptable limits\n");
        }
    }

    close(sockfd);
    freeaddrinfo(addrs);

    return 0;
}