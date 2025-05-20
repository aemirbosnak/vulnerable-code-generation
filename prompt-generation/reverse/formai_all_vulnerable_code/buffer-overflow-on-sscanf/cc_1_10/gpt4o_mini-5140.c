//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 256
#define BUFFER_SIZE 1024

void display_wifi_networks() {
    printf("Fetching Wi-Fi networks...\n");
    // Command to list Wi-Fi networks using nmcli
    const char *command = "nmcli -f SSID,SIGNAL dev wifi";

    // Execute the command and open a pipe to read its output
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    printf("%-30s | %-10s\n", "SSID", "Signal Strength (%)");
    printf("-----------------------------------------------\n");

    // Read the output a line at a time - output it.
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        char ssid[50];
        int signal_strength;

        // Parse the line to get SSID and signal strength
        sscanf(buffer, "%49s %d", ssid, &signal_strength);
        
        // Display the network information
        printf("%-30s | %-10d\n", ssid, signal_strength);
    }

    // Close the pipe
    pclose(fp);
}

void display_instructions() {
    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n");
    printf("This program will scan for available Wi-Fi networks and display their signal strengths.\n");
    printf("Make sure you have NetworkManager installed and running on your system.\n\n");
}

int main() {
    // Display instructions to the user
    display_instructions();

    // Calling function to display Wi-Fi networks
    display_wifi_networks();

    printf("\nThank you for using the Wi-Fi Signal Strength Analyzer!\n");

    return 0;
}