//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: visionary
// Symphony of Wires: A Tapestry of Network Topology

#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Nodes dance amidst the ethereal realm, forming a ballet of connections
typedef struct node {
    char hostname[256];
    struct node *next;
} node_t;

// The map unfurls, revealing the secret paths of the network
typedef struct map {
    node_t *head;
    int size;
} map_t;

// An orchestra of threads weave the tapestry of connections
void *ping(void *args) {
    struct sockaddr_in addr;
    int sockfd, ping;

    node_t *node = (node_t *)args;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(node->hostname);
    addr.sin_port = htons(80);

    ping = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (ping == -1) {
        node->next = NULL;
    } else {
        printf("Pinged %s\n", node->hostname);
    }

    close(sockfd);

    return NULL;
}

// The symphony begins, each note a connection discovered
int main(int argc, char **argv) {
    map_t map;
    pthread_t threads[argc - 1];

    // String of whispers echo across the network
    for (int i = 1; i < argc; i++) {
        node_t *node = malloc(sizeof(node_t));
        strcpy(node->hostname, argv[i]);
        node->next = map.head;
        map.head = node;
        map.size++;
    }

    // Threads unfurl, their dance creating the tapestry
    for (int i = 0; i < map.size; i++) {
        pthread_create(&threads[i], NULL, ping, map.head);
        map.head = map.head->next;
    }

    // The music fades, the tapestry complete
    for (int i = 0; i < map.size; i++) {
        pthread_join(threads[i], NULL);
    }

    // The map whispers its secrets to the console
    for (node_t *node = map.head; node != NULL; node = node->next) {
        if (node->next == NULL) {
            printf("%s\n", node->hostname);
        } else {
            printf("%s -> ", node->hostname);
        }
    }

    // The curtain falls, the performance ends
    return EXIT_SUCCESS;
}