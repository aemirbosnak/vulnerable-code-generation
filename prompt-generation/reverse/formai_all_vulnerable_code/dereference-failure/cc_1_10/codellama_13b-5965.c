//Code Llama-13B DATASET v1.0 Category: Network Topology Mapper ; Style: Cyberpunk
/*
 * Cyberpunk-style Network Topology Mapper
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 3000
#define MAX_BUF 1024

struct node {
    char name[MAX_BUF];
    struct node* next;
};

struct node* add_node(struct node* list, char* name) {
    struct node* new_node = malloc(sizeof(struct node));
    strcpy(new_node->name, name);
    new_node->next = list;
    return new_node;
}

void print_node(struct node* node) {
    printf("%s\n", node->name);
    if (node->next != NULL) {
        print_node(node->next);
    }
}

void handle_connection(int sockfd) {
    char buf[MAX_BUF];
    struct node* list = NULL;
    while (1) {
        int n = read(sockfd, buf, MAX_BUF);
        if (n == 0) {
            break;
        }
        buf[n] = '\0';
        list = add_node(list, buf);
    }
    print_node(list);
}

int main(int argc, char* argv[]) {
    int sockfd, new_sockfd, portno;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    while (1) {
        new_sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (new_sockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        handle_connection(new_sockfd);

        close(new_sockfd);
    }

    return 0;
}