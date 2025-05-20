//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

#define MAX_WIFI_NETWORKS 100
#define SSID_LENGTH 32
#define SIGNAL_STRENGTH_LENGTH 32

typedef struct {
    char ssid[SSID_LENGTH];
    int signal_strength;
} WiFiNetwork;

WiFiNetwork networks[MAX_WIFI_NETWORKS];
int network_count = 0;

void cleanup_and_exit() {
    fprintf(stderr, "An error occurred. Exiting...\n");
    exit(EXIT_FAILURE);
}

void sigint_handler(int signum) {
    printf("\nExiting Wi-Fi Signal Strength Analyzer...\n");
    exit(0);
}

void parse_signal_strength(const char *line) {
    char ssid[SSID_LENGTH];
    int strength;

    if (sscanf(line, "cell: SSID: %s Signal: %d", ssid, &strength) == 2) {
        if (network_count < MAX_WIFI_NETWORKS) {
            strncpy(networks[network_count].ssid, ssid, SSID_LENGTH - 1);
            networks[network_count].ssid[SSID_LENGTH - 1] = '\0'; // Ensure null termination
            networks[network_count].signal_strength = strength;
            network_count++;
        } else {
            fprintf(stderr, "Max networks reached. Cannot store more.\n");
        }
    }
}

void execute_command(const char *cmd) {
    FILE *fp;
    char buf[256];

    if ((fp = popen(cmd, "r")) == NULL) {
        perror("popen");
        cleanup_and_exit();
    }

    while (fgets(buf, sizeof(buf), fp) != NULL) {
        parse_signal_strength(buf);
    }

    if (pclose(fp) == -1) {
        perror("pclose");
        cleanup_and_exit();
    }
}

void display_networks() {
    printf("\nWi-Fi Networks Detected:\n");
    printf("%-32s %s\n", "SSID", "Signal Strength (dBm)");
    printf("----------------------------------------------\n");
    for (int i = 0; i < network_count; ++i) {
        printf("%-32s %d\n", networks[i].ssid, networks[i].signal_strength);
    }
}

int main() {
    signal(SIGINT, sigint_handler);

    char command[] = "nmcli -f SSID,SIGNAL dev wifi"; // Command to fetch Wi-Fi networks
    execute_command(command);
    display_networks();

    return 0;
}