//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX_HOSTNAME_LEN 1024
#define MAX_PORT_LEN 16
#define MAX_IP_LEN 46

typedef struct {
    char hostname[MAX_HOSTNAME_LEN];
    char ip[MAX_IP_LEN];
    char port[MAX_PORT_LEN];
    struct in_addr inet_addr;
    struct hostent *host_info;
    struct sockaddr_in sockaddr;
} node_t;

node_t *create_node(char *hostname) {
    node_t *node = (node_t *) malloc(sizeof(node_t));
    strcpy(node->hostname, hostname);
    node->inet_addr.s_addr = inet_addr(hostname);
    node->host_info = gethostbyaddr((char *) &node->inet_addr, sizeof(struct in_addr), AF_INET);
    strcpy(node->ip, inet_ntoa(node->inet_addr));
    return node;
}

void print_node(node_t *node) {
    printf("Hostname: %s\n", node->hostname);
    printf("IP: %s\n", node->ip);
    printf("Port: %s\n", node->port);
    printf("inet_addr: %s\n", inet_ntoa(node->inet_addr));
    printf("host_info: %s\n", node->host_info->h_name);
    printf("sockaddr: %s:%d\n", inet_ntoa(node->sockaddr.sin_addr), ntohs(node->sockaddr.sin_port));
}

int main() {
    int i, num_nodes;
    char input[1024];
    node_t *nodes[100];

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    for (i = 0; i < num_nodes; i++) {
        printf("Enter node %d: ", i + 1);
        scanf("%s", input);
        nodes[i] = create_node(input);
    }

    printf("Topology:\n");
    for (i = 0; i < num_nodes; i++) {
        print_node(nodes[i]);
    }

    return 0;
}