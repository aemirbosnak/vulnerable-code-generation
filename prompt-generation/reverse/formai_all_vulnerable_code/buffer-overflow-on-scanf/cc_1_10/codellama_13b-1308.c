//Code Llama-13B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: lively
/*
 * Wi-Fi Signal Strength Analyzer
 *
 * Author: [Your Name]
 * Date: [Current Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define MAX_SSID_LENGTH 32
#define MAX_PASSWORD_LENGTH 64
#define MAX_NETWORKS 10

typedef struct {
    char ssid[MAX_SSID_LENGTH + 1];
    char password[MAX_PASSWORD_LENGTH + 1];
    int signal_strength;
} network_t;

void print_networks(network_t networks[], int num_networks) {
    for (int i = 0; i < num_networks; i++) {
        printf("Network %d: %s (%d dBm)\n", i + 1, networks[i].ssid, networks[i].signal_strength);
    }
}

int main(void) {
    network_t networks[MAX_NETWORKS];
    int num_networks = 0;

    while (num_networks < MAX_NETWORKS) {
        printf("Enter SSID: ");
        fgets(networks[num_networks].ssid, MAX_SSID_LENGTH, stdin);
        networks[num_networks].ssid[strcspn(networks[num_networks].ssid, "\n")] = '\0';

        printf("Enter password: ");
        fgets(networks[num_networks].password, MAX_PASSWORD_LENGTH, stdin);
        networks[num_networks].password[strcspn(networks[num_networks].password, "\n")] = '\0';

        printf("Enter signal strength: ");
        scanf("%d", &networks[num_networks].signal_strength);
        getchar();

        num_networks++;
    }

    print_networks(networks, num_networks);

    return 0;
}