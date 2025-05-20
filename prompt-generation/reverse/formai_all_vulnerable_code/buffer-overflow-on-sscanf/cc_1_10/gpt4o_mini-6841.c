//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APS 100
#define BUFFER_SIZE 256

// Structure to hold information about an access point
struct AccessPoint {
    char ssid[BUFFER_SIZE];
    char bssid[BUFFER_SIZE];
    char signal_level[BUFFER_SIZE];
};

// Declare an array to store access points
struct AccessPoint aps[MAX_APS];
int ap_count = 0;

// Function to execute a system command and capture its output
void execute_command(const char *command) {
    FILE *fp;
    char buffer[BUFFER_SIZE];

    fp = popen(command, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command\n");
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Process the captured output
        if (strstr(buffer, "SSID") != NULL) {
            // Extract SSID from the line
            sscanf(buffer, "SSID: %s", aps[ap_count].ssid);
        } else if (strstr(buffer, "BSSID") != NULL) {
            // Extract BSSID from the line
            sscanf(buffer, "BSSID: %s", aps[ap_count].bssid);
        } else if (strstr(buffer, "Signal level") != NULL) {
            // Extract signal level from the line
            sscanf(buffer, "Signal level=%s", aps[ap_count].signal_level);
            ap_count++; // Increment access point count
        }
    }

    pclose(fp);
}

// Function to print all scanned access points
void print_access_points() {
    printf("Available Access Points:\n");
    printf("%-30s %-20s %s\n", "SSID", "BSSID", "Signal Level");
    printf("------------------------------------------------------------\n");
    
    for (int i = 0; i < ap_count; i++) {
        printf("%-30s %-20s %s\n", aps[i].ssid, aps[i].bssid, aps[i].signal_level);
    }
}

// Main function
int main() {
    printf("Wireless Network Scanner\n");

    // Command to scan for wireless networks (adjust as necessary for your system)
    char *command = "iwlist wlan0 scanning | grep -E 'Cell|ESSID|Signal' | awk '{print (NF==1)?$0:$2}'";

    execute_command(command);
    print_access_points();

    return 0;
}