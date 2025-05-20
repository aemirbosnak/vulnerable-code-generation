//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_HOST_NAME 256
#define MAX_DATA_SIZE 1024

// Function to print usage instructions
void print_usage(char* program_name) {
    printf("Usage: %s <IP Address>\n", program_name);
}

// Function to send ICMP echo request and receive response
int ping(char* hostname) {
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    inet_pton(AF_INET, hostname, &addr.sin_addr);

    char buffer[MAX_DATA_SIZE];
    memset(buffer, 0, sizeof(buffer));

    int bytes_sent = sendto(sock, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", strlen("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), 0, (struct sockaddr*)&addr, sizeof(addr));
    if (bytes_sent == -1) {
        perror("sendto");
        close(sock);
        return 1;
    }

    int bytes_received = recv(sock, buffer, sizeof(buffer), 0);
    if (bytes_received == -1) {
        perror("recv");
        close(sock);
        return 1;
    }

    close(sock);
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        print_usage(argv[0]);
        return 1;
    }

    char* hostname = argv[1];
    if (strlen(hostname) > MAX_HOST_NAME) {
        printf("Error: Hostname too long\n");
        return 1;
    }

    int result = ping(hostname);
    if (result == 0) {
        printf("Host is reachable\n");
    } else {
        printf("Host is not reachable\n");
    }

    return 0;
}