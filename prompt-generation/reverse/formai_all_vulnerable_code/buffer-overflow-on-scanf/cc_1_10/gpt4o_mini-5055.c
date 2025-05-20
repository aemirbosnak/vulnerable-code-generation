//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_RULES 100
#define BUF_SIZE 1024

typedef struct {
    char rule[50];
} FirewallRule;

FirewallRule rules[MAX_RULES];
int rule_count = 0;

void print_welcome() {
    printf("*************************************\n");
    printf("       WELCOME TO MY C FIREWALL!    \n");
    printf("*************************************\n");
    printf("This program will help you set up rules to filter incoming packets!\n");
}

void add_rule() {
    if (rule_count < MAX_RULES) {
        printf("Enter the rule to add (e.g., BLOCK 192.168.1.1): ");
        scanf("%s", rules[rule_count].rule);
        rule_count++;
        printf("Successfully added rule: %s\n", rules[rule_count - 1].rule);
    } else {
        printf("Max rule limit reached! Can't add more rules.\n");
    }
}

void show_rules() {
    printf("Current Firewall Rules:\n");
    for (int i = 0; i < rule_count; i++) {
        printf("%d: %s\n", i + 1, rules[i].rule);
    }
}

int check_packet(const char *packet) {
    for (int i = 0; i < rule_count; i++) {
        if (strstr(packet, rules[i].rule)) {
            printf("Packet rejected by rule: %s\n", rules[i].rule);
            return 0; // Block the packet
        }
    }
    return 1; // Allow the packet
}

void simulate_packet_capture() {
    char buffer[BUF_SIZE];

    // Simulate incoming packets
    const char *packets[] = {
        "Packet from 192.168.1.1",
        "Packet from 192.168.1.2",
        "Packet from 10.0.0.1",
        "Packet from 192.168.1.1: This is a test",
        "Packet from 172.16.0.1"
    };

    printf("Simulating packet capture...\n");
    for (int i = 0; i < 5; i++) {
        strncpy(buffer, packets[i], BUF_SIZE);
        printf("Received: %s\n", buffer);
        
        // Check the packet against rules
        if (check_packet(buffer)) {
            printf("Packet allowed!\n");
        } else {
            printf("Packet blocked!\n");
        }
    }
}

int main() {
    print_welcome();

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add Firewall Rule\n");
        printf("2. Show Current Rules\n");
        printf("3. Simulate Packet Capture\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_rule();
                break;
            case 2:
                show_rules();
                break;
            case 3:
                simulate_packet_capture();
                break;
            case 4:
                printf("Exiting the program. Stay Safe!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 4);

    return 0;
}