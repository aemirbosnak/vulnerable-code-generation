//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORKS 10
#define MAX_STR_LENGTH 20

typedef struct {
    char name[MAX_STR_LENGTH];
    int strength;
} Network;

void sort_networks(Network *networks, int num_networks);
char* get_signal_strength(int strength);

int main() {
    Network networks[MAX_NETWORKS];
    int num_networks = 0;

    printf("Wi-Fi Signal Strength Analyzer\n\n");

    while (num_networks < MAX_NETWORKS) {
        printf("Enter name of network %d: ", num_networks + 1);
        scanf("%s", networks[num_networks].name);

        printf("Enter signal strength of network %d (out of 100): ", num_networks + 1);
        scanf("%d", &networks[num_networks].strength);

        num_networks++;

        char continue_choice;
        printf("Continue entering networks? (y/n): ");
        scanf(" %c", &continue_choice);

        if (continue_choice != 'y' && continue_choice != 'Y') {
            break;
        }
    }

    sort_networks(networks, num_networks);

    printf("\n%-20s %-10s\n", "Network Name", "Strength");

    for (int i = 0; i < num_networks; i++) {
        printf("%-20s %-10d %s\n", networks[i].name, networks[i].strength, get_signal_strength(networks[i].strength));
    }

    return 0;
}

void sort_networks(Network *networks, int num_networks) {
    Network temp_network;

    for (int i = 0; i < num_networks - 1; i++) {
        for (int j = i + 1; j < num_networks; j++) {
            if (networks[j].strength > networks[i].strength) {
                temp_network = networks[i];
                networks[i] = networks[j];
                networks[j] = temp_network;
            }
        }
    }
}

char* get_signal_strength(int strength) {
    if (strength >= 70) {
        return "Excellent";
    } else if (strength >= 50) {
        return "Good";
    } else if (strength >= 30) {
        return "Fair";
    } else {
        return "Poor";
    }
}