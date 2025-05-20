//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>
#define MAX_CONNECTIONS 100
#define MAX_NODES 1000
typedef struct node {
    char name[256];
    char ip[256];
    int port;
    int num_connections;
    struct node* connections[MAX_CONNECTIONS];
} node;
node* nodes[MAX_NODES];
int num_nodes = 0;
pthread_mutex_t lock;
void* handle_connection(void* arg) {
    int sock = (int)arg;
    char buffer[256];
    while (1) {
        if (recv(sock, buffer, sizeof(buffer), 0) <= 0) {
            break;
        }
        pthread_mutex_lock(&lock);
        node* n = malloc(sizeof(node));
        sscanf(buffer, "%s %s %d", n->name, n->ip, &n->port);
        nodes[num_nodes++] = n;
        pthread_mutex_unlock(&lock);
    }
    close(sock);
    return NULL;
}
int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("socket");
        return 1;
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);
    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return 1;
    }
    if (listen(server_sock, 10) == -1) {
        perror("listen");
        return 1;
    }
    pthread_t threads[MAX_CONNECTIONS];
    int num_threads = 0;
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_sock == -1) {
            perror("accept");
            continue;
        }
        pthread_create(&threads[num_threads++], NULL, handle_connection, (void*)client_sock);
    }
    close(server_sock);
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}