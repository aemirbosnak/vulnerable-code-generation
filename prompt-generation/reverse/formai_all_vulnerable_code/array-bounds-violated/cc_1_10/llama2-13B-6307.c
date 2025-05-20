//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_START 1024
#define PORT_END 65535

#define MAX_CONNECTIONS 10

struct connection {
    int sock;
    struct sockaddr_in address;
};

void scan_ports(int start, int end) {
    int i, j, num_connections = 0;
    struct connection connections[MAX_CONNECTIONS];

    for (i = start; i <= end; i++) {
        if (connect_to_port(i) == 0) {
            num_connections++;
            connections[num_connections - 1].sock = i;
            connections[num_connections - 1].address.sin_port = htons(i);
            printf("Found open port %d\n", i);
        }
    }

    for (j = 0; j < num_connections; j++) {
        if (send_message(connections[j].sock) == -1) {
            perror("send_message");
        }
    }
}

int connect_to_port(int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in address;

    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = INADDR_ANY;

    if (connect(sock, (struct sockaddr *)&address, sizeof(address)) == -1) {
        perror("connect");
        return -1;
    }

    return sock;
}

int send_message(int sock) {
    char message[] = "Hello, my dear!";
    int len = strlen(message);

    if (send(sock, message, len, 0) == -1) {
        perror("send");
        return -1;
    }

    return len;
}

int main() {
    scan_ports(PORT_START, PORT_END);
    return 0;
}