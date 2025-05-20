//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <sys/types.h>
#include <sys/socket.h>

#define TIMEOUT 1
#define BUFFER_SIZE 256

struct Node {
    char ip[INET_ADDRSTRLEN];
    struct Node *next;
};

void append(struct Node **head_ref, const char *new_ip) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    strcpy(new_node->ip, new_ip);
    new_node->next = NULL;
    
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

void printTopology(struct Node *node) {
    printf("~ Network Topology ~\n");
    printf("---------------------\n");
    while (node != NULL) {
        printf("Node: %s\n", node->ip);
        node = node->next;
    }
    printf("---------------------\n");
}

int ping(const char *ip) {
    int sockfd;
    struct sockaddr_in addr;
    char cmd[BUFFER_SIZE];

    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    inet_pton(AF_INET, ip, &addr.sin_addr);
    
    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket creation failed");
        return 0;
    }
    
    snprintf(cmd, sizeof(cmd), "ping -c 1 -W %d %s > /dev/null", TIMEOUT, ip);
    
    int status = system(cmd);
    close(sockfd);
    
    return status == 0;
}

void scanNetwork(const char *base_ip, int start, int end, struct Node **nodes) {
    char ip[INET_ADDRSTRLEN];
    for (int i = start; i <= end; i++) {
        snprintf(ip, sizeof(ip), "%s.%d", base_ip, i);
        if (ping(ip)) {
            printf("~ Connected: %s ~\n", ip);
            append(nodes, ip);
        } else {
            printf("X Not Reachable: %s\n", ip);
        }
    }
}

int main() {
    struct Node *network = NULL;
    char base_ip[INET_ADDRSTRLEN];
    
    printf("Enter base IP (e.g., 192.168.1): ");
    scanf("%s", base_ip);
    
    printf("Scanning from %s.1 to %s.254...\n", base_ip, base_ip);
    scanNetwork(base_ip, 1, 254, &network);
    printTopology(network);
    
    return 0;
}