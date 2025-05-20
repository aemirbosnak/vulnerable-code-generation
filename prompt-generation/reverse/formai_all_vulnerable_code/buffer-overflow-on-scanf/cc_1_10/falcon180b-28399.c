//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_PORTS 65535

void print_port_status(int port, int is_open) {
    if (is_open) {
        printf("Port %d is open\n", port);
    } else {
        printf("Port %d is closed\n", port);
    }
}

int main() {
    int target_ip[4] = {192, 168, 1, 1}; // replace with target IP address
    char target_hostname[64];
    struct hostent *host_entry;
    int target_port_start = 1;
    int target_port_end = MAX_PORTS;
    int is_open;

    printf("Enter target hostname or IP address: ");
    scanf("%s", target_hostname);

    host_entry = gethostbyname(target_hostname);
    if (host_entry == NULL) {
        printf("Invalid hostname or IP address\n");
        return 1;
    }

    memcpy(target_ip, host_entry->h_addr, host_entry->h_length);

    for (int i = target_port_start; i <= target_port_end; i++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            printf("Socket creation failed with error code %d\n", errno);
            continue;
        }

        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(i);
        server_addr.sin_addr.s_addr = htonl(target_ip[0]);

        int result = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (result == 0) {
            is_open = 1;
        } else if (result == -1 && errno == ECONNREFUSED) {
            is_open = 0;
        } else {
            is_open = -1;
        }

        close(sock);

        print_port_status(i, is_open);
    }

    return 0;
}