//FormAI DATASET v1.0 Category: Firewall ; Style: all-encompassing
/*
 * This is an example of a simple firewall program written in C
 * Author: Your Name
 * Date: MM/DD/YYYY
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct firewall_rule {
    char source_ip[20];
    char dest_ip[20];
    int dest_port;
    char protocol[10];
};

struct firewall_rule rules[10];
int num_rules = 0;

/* Functions for adding and removing rules */
void add_rule(char source_ip[], char dest_ip[], int dest_port, char protocol[]) {
    if (num_rules >= 10) {
        printf("Error: Maximum number of rules exceeded\n");
        return;
    }
    strcpy(rules[num_rules].source_ip, source_ip);
    strcpy(rules[num_rules].dest_ip, dest_ip);
    rules[num_rules].dest_port = dest_port;
    strcpy(rules[num_rules].protocol, protocol);
    num_rules++;
    printf("Rule added successfully\n");
}

void remove_rule(int index) {
    if (index < 0 || index >= num_rules) {
        printf("Error: Invalid rule index\n");
        return;
    }
    for (int i = index; i < num_rules-1; i++) {
        rules[i] = rules[i+1];
    }
    num_rules--;
    printf("Rule removed successfully\n");
}

/* Function for checking if a packet should be allowed */
int check_packet(char source_ip[], char dest_ip[], int dest_port, char protocol[]) {
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].source_ip, source_ip) == 0 && strcmp(rules[i].dest_ip, dest_ip) == 0 &&
            rules[i].dest_port == dest_port && strcmp(rules[i].protocol, protocol) == 0) {
            return 1; // Packet matches rule, allow it
        }
    }
    return 0; // Packet does not match any rule, block it
}

int main() {
    int choice = 0;
    char source_ip[20], dest_ip[20], protocol[10];
    int dest_port;

    while (choice != 4) {
        printf("Firewall program\n");
        printf("1. Add rule\n");
        printf("2. Remove rule\n");
        printf("3. Check packet\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source IP address: ");
                scanf("%s", source_ip);
                printf("Enter destination IP address: ");
                scanf("%s", dest_ip);
                printf("Enter destination port: ");
                scanf("%d", &dest_port);
                printf("Enter protocol (TCP/UDP): ");
                scanf("%s", protocol);
                add_rule(source_ip, dest_ip, dest_port, protocol);
                break;
            case 2:
                printf("Enter rule index to remove: ");
                int index;
                scanf("%d", &index);
                remove_rule(index);
                break;
            case 3:
                printf("Enter source IP address: ");
                scanf("%s", source_ip);
                printf("Enter destination IP address: ");
                scanf("%s", dest_ip);
                printf("Enter destination port: ");
                scanf("%d", &dest_port);
                printf("Enter protocol (TCP/UDP): ");
                scanf("%s", protocol);
                if (check_packet(source_ip, dest_ip, dest_port, protocol)) {
                    printf("Packet allowed\n");
                } else {
                    printf("Packet blocked\n");
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}