//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <unistd.h>

#define MAX_NODE_LENGTH 250
#define MAX_CONN_LENGTH 1000

struct node {
    char name[MAX_NODE_LENGTH];
    char ip[INET_ADDRSTRLEN];
    int port;
};

struct conn {
    char source[MAX_NODE_LENGTH];
    char destination[MAX_NODE_LENGTH];
};

int main(int argc, char **argv) {
    struct node nodes[10];
    struct conn conns[20];
    int num_nodes = 0;
    int num_conns = 0;
    
    struct ifaddrs *ifaddr, *ifa;
    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }
    
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL) continue;
        int family = ifa->ifa_addr->sa_family;
        if (family == AF_INET) {
            struct sockaddr_in *addr = (struct sockaddr_in *)ifa->ifa_addr;
            char *ip = inet_ntoa(addr->sin_addr);
            struct node n;
            strcpy(n.name, ifa->ifa_name);
            strcpy(n.ip, ip);
            n.port = rand() % 1000 + 8000;
            nodes[num_nodes++] = n;
        }
    }
    
    freeifaddrs(ifaddr);
    
    printf("Discovered %d nodes on this network:\n", num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        printf("%s (%s:%d)\n", nodes[i].name, nodes[i].ip, nodes[i].port);
    }
    
    char input[MAX_CONN_LENGTH];
    while (strcmp(input, "quit") != 0) {
        printf("\nEnter a connection in the format <source> <destination> (or 'quit' to exit): ");
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) break;
        char source[MAX_NODE_LENGTH], destination[MAX_NODE_LENGTH];
        sscanf(input, "%s %s", source, destination);
        int found_source = 0, found_dest = 0;
        for (int i = 0; i < num_nodes; i++) {
            if (strcmp(nodes[i].name, source) == 0) {
                found_source = 1;
            }
            if (strcmp(nodes[i].name, destination) == 0) {
                found_dest = 1;
            }
        }
        if (!found_source || !found_dest) {
            printf("One or both of the nodes specified does not exist.\n");
        } else {
            struct conn c;
            strcpy(c.source, source);
            strcpy(c.destination, destination);
            conns[num_conns++] = c;
        }
    }
    
    printf("\nGenerated network topology:\n");
    for (int i = 0; i < num_conns; i++) {
        printf("%s (%s:%d) -> %s (%s:%d)\n", conns[i].source, nodes[rand() % num_nodes].ip, nodes[rand() % num_nodes].port, conns[i].destination, nodes[rand() % num_nodes].ip, nodes[rand() % num_nodes].port);
    }
    
    return 0;
}