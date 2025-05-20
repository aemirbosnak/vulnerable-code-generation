//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_NODES 100
#define BUFFER_SIZE 1024
#define PORT 8080

typedef struct {
    char ip[INET_ADDRSTRLEN];
    int active;
} Node;

Node nodes[MAX_NODES];
int node_count = 0;

void add_node(const char *ip) {
    if (node_count < MAX_NODES) {
        strcpy(nodes[node_count].ip, ip);
        nodes[node_count].active = 1;
        node_count++;
    } else {
        fprintf(stderr, "Max nodes limit reached!\n");
    }
}

void print_active_nodes() {
    printf("Active Nodes in Network:\n");
    for (int i = 0; i < node_count; i++) {
        if (nodes[i].active) {
            printf("Node %d: %s\n", i + 1, nodes[i].ip);
        }
    }
}

int ping(const char *ip) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "ping -c 1 %s > /dev/null 2>&1", ip);
    return system(command);
}

void scan_network() {
    for (int i = 0; i < node_count; i++) {
        if (ping(nodes[i].ip) == 0) {
            printf("%s is active.\n", nodes[i].ip);
        } else {
            printf("%s is inactive.\n", nodes[i].ip);
            nodes[i].active = 0;
        }
    }
}

void read_configuration(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open configuration file");
        return;
    }

    char line[BUFFER_SIZE];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0; // Remove newline character
        add_node(line);
    }
    fclose(file);
}

void display_menu() {
    printf("\n*** Network Topology Mapper ***\n");
    printf("1. Scan Network\n");
    printf("2. Display Active Nodes\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <config_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_configuration(argv[1]);

    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scan_network();
                break;
            case 2:
                print_active_nodes();
                break;
            case 3:
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return EXIT_SUCCESS;
}