//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024
#define MAX_HOST_LEN 100

struct host_info {
    char *host;
    int port;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <host_ip>\n", argv[0]);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        return 2;
    }

    struct host_info *hosts = malloc(sizeof(struct host_info) * PORT_RANGE);
    if (hosts == NULL) {
        perror("memory allocation failed");
        return 3;
    }

    int i = 0;
    char host_ip[INET_ADDRSTRLEN];
    char port_str[6];

    // Parse the host IP address and port range
    sscanf(argv[1], "%hu:%hu", &host_ip[0], &port_str[0]);
    int start_port = atoi(port_str);
    int end_port = start_port + PORT_RANGE - 1;

    // Connect to the host and scan the specified port range
    for (i = start_port; i <= end_port; i++) {
        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(i);
        inet_pton(AF_INET, host_ip, &server_addr.sin_addr);

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            // Found a open port!
            hosts[i].host = host_ip;
            hosts[i].port = i;
            printf("Port %d open on %s\n", i, host_ip);
        }
    }

    // Print the host and port information
    for (i = 0; i < PORT_RANGE; i++) {
        if (hosts[i].host != NULL) {
            printf("%d. %s: %d\n", i + 1, hosts[i].host, hosts[i].port);
        }
    }

    // Clean up
    free(hosts);
    close(sock);

    return 0;
}