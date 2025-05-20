//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 100
#define PORT_RANGE_MIN 1
#define PORT_RANGE_MAX 65535

struct hostent *gethostbyname(const char *name);
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

void *scan_ports(void *arg) {
    int sockfd;
    struct sockaddr_in server_addr;
    int port;

    char *ip_address = (char *) arg;
    printf("Scanning ports for %s\n", ip_address);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    for (port = PORT_RANGE_MIN; port <= PORT_RANGE_MAX; port++) {
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = inet_addr(ip_address);

        if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open\n", port);
            close(sockfd);
            return NULL;
        }
    }

    printf("No open ports found\n");
    close(sockfd);
    return NULL;
}

int main(int argc, char *argv[]) {
    int num_threads;
    pthread_t threads[MAX_THREADS];
    char **ip_addresses;
    int i, port_range[2];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <start_ip> <end_ip> <port_range>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sscanf(argv[2], "%d.%d.%d.%d", &port_range[0], &port_range[1], &port_range[2], &port_range[3]);
    num_threads = port_range[3] - port_range[2] + 1;

    ip_addresses = (char **) malloc(num_threads * sizeof(char *));
    for (i = 0; i < num_threads; i++) {
        ip_addresses[i] = (char *) malloc(16 * sizeof(char));
        sprintf(ip_addresses[i], "%d.%d.%d.%d", port_range[0], port_range[1], port_range[2], i + port_range[2]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, scan_ports, ip_addresses[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    free(ip_addresses);
    return 0;
}