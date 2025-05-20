//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NETWORKS 10
#define MAX_NAME_LENGTH 20
#define MAX_SIGNAL_STRENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int signal_strength;
} WirelessNetwork;

void delay(int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);
}

void print_separator() {
    printf("\n----------------------------------------------\n\n");
}

void print_header() {
    printf("WIRELESS NETWORK SCANNER\n\n");
}

void scan_networks(WirelessNetwork networks[], int* network_count) {
    printf("Scanning for networks...\n");
    delay(3000);

    printf("%d networks found:\n\n", MAX_NETWORKS);

    for (int i = 0; i < MAX_NETWORKS; i++) {
        strcpy(networks[i].name, "Network");
        networks[i].signal_strength = rand() % (MAX_SIGNAL_STRENGTH + 1);

        printf("%d. %s %d%%\n", i + 1, networks[i].name, networks[i].signal_strength);
    }

    *network_count = MAX_NETWORKS;
    printf("\n");
}

void print_networks(WirelessNetwork networks[], int network_count) {
    print_separator();
    printf("LIST OF AVAILABLE NETWORKS\n\n");

    for (int i = 0; i < network_count; i++) {
        printf("%d. %s %d%%\n", i + 1, networks[i].name, networks[i].signal_strength);
    }

    print_separator();
}

void connect_to_network(WirelessNetwork networks[], int network_count) {
    int selection;

    printf("Enter the number of the network you wish to connect to: ");
    scanf("%d", &selection);

    if (selection >= 1 && selection <= network_count) {
        printf("Connecting to network %s...\n", networks[selection - 1].name);
        delay(1500);
        printf("Connected!\n");
    } else {
        printf("Invalid selection.\n");
    }
}

int main() {
    srand(time(NULL));

    WirelessNetwork networks[MAX_NETWORKS];
    int network_count = 0;

    print_header();

    scan_networks(networks, &network_count);

    print_networks(networks, network_count);

    connect_to_network(networks, network_count);

    printf("\nGoodbye!\n");

    return 0;
}