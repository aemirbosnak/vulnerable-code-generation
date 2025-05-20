//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define MAX_NETWORKS 50

typedef struct {
    char ssid[BUFFER_SIZE];
    int signal_strength;
} WifiNetwork;

void clear_screen() {
    printf("\033[H\033[J");
}

void fetch_wifi_signals(WifiNetwork networks[], int *network_count) {
    FILE *fp;
    char command[] = "nmcli -t -f SSID,SIGNAL dev wifi";
    char buffer[BUFFER_SIZE];

    // Execute the command and open a pipe to read its output
    fp = popen(command, "r");
    if (fp == NULL) {
        perror("popen failed");
        exit(EXIT_FAILURE);
    }

    *network_count = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (*network_count >= MAX_NETWORKS) {
            break; // Prevent buffer overflow
        }
        sscanf(buffer, "%[^:]:%d", networks[*network_count].ssid, &networks[*network_count].signal_strength);
        (*network_count)++;
    }

    // Close the command pipe
    if (pclose(fp) == -1) {
        perror("pclose failed");
        exit(EXIT_FAILURE);
    }
}

void print_networks(WifiNetwork networks[], int network_count) {
    printf("Available Wi-Fi Networks:\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < network_count; i++) {
        printf("%d. SSID: %-30s Signal Strength: %d dBm\n", i + 1, networks[i].ssid, networks[i].signal_strength);
    }
    printf("-------------------------------------\n");
}

void analyze_signal_strength(int signal_strength) {
    if (signal_strength < -90) {
        printf("Signal is extremely weak. You might lose connection!\n");
    } else if (signal_strength < -70) {
        printf("Signal is weak. Consider moving closer to the access point.\n");
    } else if (signal_strength < -50) {
        printf("Signal is fair. Connection is possible but not optimal.\n");
    } else {
        printf("Signal is strong. Enjoy your internet experience!\n");
    }
}

int main() {
    WifiNetwork networks[MAX_NETWORKS];
    int network_count;

    while (1) {
        clear_screen();
        fetch_wifi_signals(networks, &network_count);
        print_networks(networks, network_count);

        int choice;
        printf("Select a network to analyze its signal strength (0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        } else if (choice > 0 && choice <= network_count) {
            analyze_signal_strength(networks[choice - 1].signal_strength);
        } else {
            printf("Invalid choice. Please try again.\n");
        }

        printf("\nPress Enter to refresh or Ctrl+C to exit...\n");
        getchar(); // consume newline
        getchar(); // wait for user input
    }

    return 0;
}