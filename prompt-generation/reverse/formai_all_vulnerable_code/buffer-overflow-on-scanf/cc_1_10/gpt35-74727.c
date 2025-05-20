//FormAI DATASET v1.0 Category: Firewall ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct iptables {
    char ip_address[20];
    char port_number[5];
    char protocol[10];
    char status[10];
} iptables;

void add_rule(iptables *ipt);
void print_rules(iptables *ipt, int n);
void block_port(iptables *ipt, int n);

int main() {
    int choice, n = 0;
    iptables ipt[20];

    do {
        printf("\n------- WELCOME TO FIREWALL -------\n\n");
        printf("1. Add rule\n");
        printf("2. View rules\n");
        printf("3. Block port\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_rule(&ipt[n]);
                n++;
                break;

            case 2:
                print_rules(ipt, n);
                break;

            case 3:
                block_port(ipt, n);
                break;

            case 4:
                printf("\nThank you for using Firewall!\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while(choice != 4);

    return 0;
}

void add_rule(iptables *ipt) {
    printf("Enter IP address: ");
    scanf("%s", ipt->ip_address);
    printf("Enter port number: ");
    scanf("%s", ipt->port_number);
    printf("Enter protocol: ");
    scanf("%s", ipt->protocol);
    strcpy(ipt->status, "ALLOW");
    printf("\nRule added successfully!\n");
}

void print_rules(iptables *ipt, int n) {
    printf("\n------- RULES LIST -------\n\n");
    printf("IP Address\tPort Number\tProtocol\tStatus\n");
    for(int i=0; i<n; i++) {
        printf("%s\t%s\t\t%s\t\t%s\n", ipt[i].ip_address, ipt[i].port_number, ipt[i].protocol, ipt[i].status);
    }
}

void block_port(iptables *ipt, int n) {
    char port[5];
    printf("Enter port number to block: ");
    scanf("%s", port);
    for(int i=0; i<n; i++) {
        if(strcmp(ipt[i].port_number, port) == 0) {
            strcpy(ipt[i].status, "BLOCK");
        }
    }
    printf("\nPort number %s blocked successfully!\n", port);
}