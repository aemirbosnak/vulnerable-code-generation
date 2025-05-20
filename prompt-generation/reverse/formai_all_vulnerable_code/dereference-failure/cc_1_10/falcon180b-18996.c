//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: optimized
/* C Network Ping Test Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/time.h>

#define BUFFER_SIZE 1024

// Function to print usage instructions
void print_usage() {
    printf("Usage:./ping <IP Address>\n");
    exit(1);
}

// Function to send an ICMP echo request and receive a response
int ping(char* ip_address) {
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock == -1) {
        printf("Error creating socket.\n");
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_address);

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    int bytes_sent = sendto(sock, "PING", strlen("PING"), 0, (struct sockaddr*)&addr, sizeof(addr));
    if (bytes_sent == -1) {
        printf("Error sending ping request.\n");
        close(sock);
        return 1;
    }

    struct timeval tv;
    tv.tv_sec = 5;
    tv.tv_usec = 0;

    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(sock, &read_fds);

    int select_result = select(sock+1, &read_fds, NULL, NULL, &tv);
    if (select_result == -1) {
        printf("Error selecting socket.\n");
        close(sock);
        return 1;
    }

    if (FD_ISSET(sock, &read_fds)) {
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received == -1) {
            printf("Error receiving response.\n");
            close(sock);
            return 1;
        } else if (bytes_received == 0) {
            printf("No response received.\n");
            close(sock);
            return 1;
        } else {
            buffer[bytes_received] = '\0';
            printf("Response received: %s\n", buffer);
        }
    } else {
        printf("No response received.\n");
    }

    close(sock);
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        print_usage();
    }

    char* ip_address = argv[1];
    ping(ip_address);

    return 0;
}