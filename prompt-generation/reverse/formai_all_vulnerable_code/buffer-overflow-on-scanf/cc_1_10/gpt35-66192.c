//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_SSID_LENGTH 32
#define MAX_MAC_ADDRESS_LENGTH 17

struct wireless_network {
    char ssid[MAX_SSID_LENGTH];
    char mac_address[MAX_MAC_ADDRESS_LENGTH];
    int signal_strength;
};

struct network_list {
    struct wireless_network network;
    struct network_list *next;
};

bool is_valid_mac_address(char *mac_address) {
    int len = strlen(mac_address);
    if (len != 17) {
        return false;
    }
    for (int i = 0; i < len; i++) {
        if (i % 3 != 2 && !isxdigit(mac_address[i])) {
            return false;
        }
        if (i % 3 == 2 && mac_address[i] != ':') {
            return false;
        }
    }
    return true;
}

void print_menu() {
    printf("\nWireless Network Scanner\n");
    printf("<1> Add Network\n");
    printf("<2> View Networks\n");
    printf("<3> Exit\n");
    printf("Enter choice: ");
}

void add_network(struct network_list **head) {
    printf("\nAdd Network\n");
    struct wireless_network network;
    printf("Enter SSID: ");
    scanf("%s", network.ssid);
    printf("Enter MAC address: ");
    scanf("%s", network.mac_address);
    while (!is_valid_mac_address(network.mac_address)) {
        printf("Invalid MAC address. Enter MAC address: ");
        scanf("%s", network.mac_address);
    }
    printf("Enter signal strength: ");
    scanf("%d", &network.signal_strength);
    struct network_list *new_network = malloc(sizeof (struct network_list));
    new_network->network = network;
    new_network->next = NULL;
    if (*head == NULL) {
        *head = new_network;
    } else {
        struct network_list *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_network;
    }
    printf("Network added successfully.\n");
}

void view_networks(struct network_list *head) {
    printf("\nWireless Networks Found\n");
    if (head == NULL) {
        printf("No wireless networks found.\n");
    } else {
        printf("%-20s %-20s %-20s\n", "SSID", "MAC ADDRESS", "SIGNAL STRENGTH");
        while (head != NULL) {
            printf("%-20s %-20s %-20d\n", head->network.ssid, head->network.mac_address, head->network.signal_strength);
            head = head->next;
        }
    }
}

int main() {
    struct network_list *head = NULL;
    int choice;
    do {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_network( & head);
                break;
            case 2:
                view_networks(head);
                break;
            case 3:
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 3);
    return 0;
}