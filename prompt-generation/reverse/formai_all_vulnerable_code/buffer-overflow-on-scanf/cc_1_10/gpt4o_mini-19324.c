//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ifaddrs.h>

#define MAX_NODES 100
#define BUFFER_SIZE 1024

typedef struct Node {
    char ip[INET_ADDRSTRLEN];
    char name[50];
    struct Node* next;
} Node;

Node* head = NULL;

void add_node(const char* ip, const char* name) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strncpy(new_node->ip, ip, INET_ADDRSTRLEN);
    strncpy(new_node->name, name, 50);
    new_node->next = head;
    head = new_node;
}

void display_nodes() {
    Node* current = head;
    printf("Network Topology:\n");
    printf("----------------------------\n");
    while (current) {
        printf("Node: %s, IP: %s\n", current->name, current->ip);
        current = current->next;
    }
    printf("----------------------------\n");
}

void free_nodes() {
    Node* current = head;
    Node* next;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}

void get_network_info() {
    struct ifaddrs* ifaddr, *ifa;
    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        return;
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET) {
            char ip[INET_ADDRSTRLEN];
            char hostname[50];
            getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), ip, sizeof(ip), NULL, 0, 0);
            strncpy(hostname, ifa->ifa_name, 50);
            add_node(ip, hostname);
        }
    }

    freeifaddrs(ifaddr);
}

void show_menu() {
    printf("Welcome to the Network Topology Mapper!\n");
    printf("=========================================\n");
    printf("1. Display Network Topology\n");
    printf("2. Exit\n");
    printf("=========================================\n");
}

int main() {
    get_network_info();
    int choice;
    
    while (1) {
        show_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_nodes();
                break;
            case 2:
                printf("Exiting the program...\n");
                free_nodes();
                exit(0);
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    free_nodes();
    return 0;
}