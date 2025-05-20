//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: genius
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

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct host_info *hosts = calloc(1, sizeof(struct host_info));
    if (!hosts) {
        perror("calloc failed");
        exit(EXIT_FAILURE);
    }

    char *host_list = getenv("HOST_LIST");
    if (!host_list) {
        host_list = "localhost";
    }

    char *token, *next;
    char host[MAX_HOST_LEN], port_str[6];
    int port, i;

    token = strtok(host_list, ",");
    while (token) {
        next = strtok(NULL, ",");
        if (next) {
            sscanf(token, "%6s:%d", host, port_str, &port);
            hosts[i].host = host;
            hosts[i].port = atoi(port_str);
            i++;
        }
        token = next;
    }

    for (i = 0; i < i; i++) {
        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        inet_pton(AF_INET, hosts[i].host, &server_addr.sin_addr);
        server_addr.sin_port = htons(hosts[i].port);

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            printf("Connected to %s on port %d\n", hosts[i].host, hosts[i].port);
            char buffer[1024];
            recv(sock, buffer, 1024, 0);
            printf("%s\n", buffer);
            close(sock);
        } else {
            perror("connect failed");
        }
    }

    free(hosts);
    return 0;
}