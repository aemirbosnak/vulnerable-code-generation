//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct WifiNetwork {
    char *ssid;
    int signal_strength;
    struct WifiNetwork *next;
};

void add_network(struct WifiNetwork **head, char *ssid, int signal_strength) {
    struct WifiNetwork *new_network = malloc(sizeof(struct WifiNetwork));
    new_network->ssid = ssid;
    new_network->signal_strength = signal_strength;
    new_network->next = *head;
    *head = new_network;
}

void print_networks(struct WifiNetwork *networks) {
    printf("SSID\tSignal Strength\n");
    while (networks != NULL) {
        printf("%s\t%d\n", networks->ssid, networks->signal_strength);
        networks = networks->next;
    }
}

int main() {
    struct WifiNetwork *networks = NULL;
    int choice;
    while (1) {
        printf("1. Add a network\n2. Print all networks\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                char ssid[100];
                int signal_strength;
                printf("Enter SSID: ");
                scanf("%s", ssid);
                printf("Enter signal strength: ");
                scanf("%d", &signal_strength);
                add_network(&networks, ssid, signal_strength);
                break;
            }
            case 2: {
                print_networks(networks);
                break;
            }
            case 3: {
                exit(0);
                break;
            }
            default: {
                printf("Invalid choice!\n");
                break;
            }
        }
    }
    return 0;
}