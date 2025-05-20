//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_NETWORKS 10
#define MAX_SSID_LENGTH 32
#define MAX_PASSWORD_LENGTH 64

typedef struct {
    char ssid[MAX_SSID_LENGTH + 1];
    char password[MAX_PASSWORD_LENGTH + 1];
    int signal_strength;
} Network;

Network networks[MAX_NETWORKS];
int num_networks = 0;

void add_network() {
    if (num_networks >= MAX_NETWORKS) {
        printf("Maximum number of networks reached.\n");
        return;
    }

    printf("Enter SSID: ");
    scanf("%s", networks[num_networks].ssid);

    printf("Enter password (leave blank for open network): ");
    scanf("%s", networks[num_networks].password);

    printf("Enter signal strength (0-100): ");
    scanf("%d", &networks[num_networks].signal_strength);

    num_networks++;
}

void remove_network(int index) {
    if (index < 0 || index >= num_networks) {
        printf("Invalid network index.\n");
        return;
    }

    memset(networks[index].ssid, 0, MAX_SSID_LENGTH + 1);
    memset(networks[index].password, 0, MAX_PASSWORD_LENGTH + 1);
    networks[index].signal_strength = 0;

    num_networks--;
}

void list_networks() {
    printf("Networks:\n");
    for (int i = 0; i < num_networks; i++) {
        printf("%d. %s (%d)\n", i + 1, networks[i].ssid, networks[i].signal_strength);
    }
}

int main() {
    printf("Wi-Fi Signal Strength Analyzer\n");

    while (true) {
        printf("\nOptions:\n");
        printf("1. Add network\n");
        printf("2. Remove network\n");
        printf("3. List networks\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_network();
            break;
        case 2:
            printf("Enter network index to remove: ");
            int index;
            scanf("%d", &index);
            remove_network(index - 1);
            break;
        case 3:
            list_networks();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}