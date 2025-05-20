//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_THREADS 100

// Function to scan a single port
void *scan_port(void *arg) {
    char *ip = (char *) arg;
    int port = *(int *) ip;
    ip += sizeof(int);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return NULL;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Port %d on %s is closed\n", port, ip);
        close(sockfd);
        return NULL;
    }

    printf("Port %d on %s is open\n", port, ip);
    close(sockfd);
    return NULL;
}

// Function to scan multiple ports
void scan_ports(char *ip, int start_port, int end_port) {
    int num_ports = end_port - start_port + 1;
    pthread_t threads[num_ports];

    for (int i = 0; i < num_ports; i++) {
        int port = start_port + i;
        char *port_str = malloc(sizeof(int) + strlen(ip) + 1);
        sprintf(port_str, "%d:%s", port, ip);
        pthread_create(&threads[i], NULL, scan_port, port_str);
    }

    for (int i = 0; i < num_ports; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    char ip[16];
    printf("Enter IP address: ");
    scanf("%s", ip);

    int start_port, end_port;
    printf("Enter start port: ");
    scanf("%d", &start_port);
    printf("Enter end port: ");
    scanf("%d", &end_port);

    scan_ports(ip, start_port, end_port);

    return 0;
}