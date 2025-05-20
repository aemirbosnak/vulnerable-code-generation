//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

#define PORT 80
#define MAX_BUFFER_SIZE 1024

int sockfd;

void sigint_handler(int sig) {
    printf("Scanner stopped.\n");
    close(sockfd);
    exit(0);
}

void scan_ip(const char *ip_address) {
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    inet_aton(ip_address, &addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*) &addr, sizeof(addr)) == 0) {
        printf("%s\topen\n", ip_address);
    }
}

int main(int argc, char **argv) {
    signal(SIGINT, sigint_handler);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    int flags = fcntl(sockfd, F_GETFL, 0);
    fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);

    printf("Wireless Network Scanner\n");
    printf("Enter IP range to scan (e.g. 192.168.1.1-255): ");
    char ip_range[20];
    fgets(ip_range, 20, stdin);

    int start_ip, end_ip;
    sscanf(ip_range, "%d.%d.%d.%d-%d", &start_ip, &start_ip, &start_ip, &start_ip, &end_ip);

    printf("Scanning...\n");
    char ip_address[20];

    for (int i = start_ip; i <= end_ip; i++) {
        sprintf(ip_address, "%d.%d.%d.%d", start_ip >> 24, (start_ip >> 16) & 0xff, (start_ip >> 8) & 0xff, start_ip & 0xff);
        start_ip++;

        scan_ip(ip_address);
    }

    printf("Scanner stopped.\n");
    close(sockfd);
    return 0;
}