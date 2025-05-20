//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_NETWORKS 50
#define MAX_SSID_LEN 32

// Structure to hold Wi-Fi network information
typedef struct {
    char ssid[MAX_SSID_LEN];
    int signal_strength;
} WifiNetwork;

// Function to execute a system command and store the output
void exec_command(const char *cmd, char *output, size_t size) {
    FILE *fp;
    fp = popen(cmd, "r");
    if (fp == NULL) {
        perror("Failed to run command");
        exit(1);
    }
    fgets(output, size, fp);
    pclose(fp);
}

// Function to parse the command output and fill network list
int parse_wifi_scan(WifiNetwork *networks) {
    char buffer[256];
    char command[] = "nmcli -t -f ssid,signal dev wifi";
    
    exec_command(command, buffer, sizeof(buffer));
    
    char *line = strtok(buffer, "\n");
    int count = 0;

    while (line != NULL && count < MAX_NETWORKS) {
        sscanf(line, "%[^:]:%d", networks[count].ssid, &networks[count].signal_strength);
        line = strtok(NULL, "\n");
        count++;
    }

    return count;
}

// Function to print the network table
void print_network_table(WifiNetwork *networks, int count) {
    printf("\nAvailable Wi-Fi Networks:\n");
    printf("+-------------------------------------+------------------+\n");
    printf("| SSID                               | Signal Strength   |\n");
    printf("+-------------------------------------+------------------+\n");

    for (int i = 0; i < count; i++) {
        printf("| %-35s | %-16d |\n", networks[i].ssid, networks[i].signal_strength);
    }

    printf("+-------------------------------------+------------------+\n");
}

// Function to provide feedback based on signal strength
void feedback_on_signal(WifiNetwork *networks, int count) {
    for (int i = 0; i < count; i++) {
        if (networks[i].signal_strength >= 75) {
            printf("The signal for '%s' is excellent! You’re all set!\n", networks[i].ssid);
        } else if (networks[i].signal_strength >= 50) {
            printf("The signal for '%s' is good. You might want to stay close!\n", networks[i].ssid);
        } else if (networks[i].signal_strength >= 25) {
            printf("The signal for '%s' is weak. Consider moving closer.\n", networks[i].ssid);
        } else {
            printf("The signal for '%s' is poor. Time to rethink your Wi-Fi strategy!\n", networks[i].ssid);
        }
    }
}

// Entry point of the program
int main() {
    WifiNetwork networks[MAX_NETWORKS];
    int network_count;

    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n");
    sleep(1); // Adding a dramatic pause 

    network_count = parse_wifi_scan(networks);
    print_network_table(networks, network_count);
    feedback_on_signal(networks, network_count);

    printf("\nThank you for using the analyzer! Keep your Wi-Fi strong!\n");
    return 0;
}