//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void displayWirelessNetworks() {
    printf("Scanning for available wireless networks...\n");
    
    // Command to execute
    const char* command = "nmcli -t -f SSID,SIGNAL dev wifi";
    // Create a buffer to store the output
    char buffer[BUFFER_SIZE];

    // Open the process to run the command
    FILE* fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    // Print header
    printf("%-30s %-6s\n", "SSID", "Signal");
    printf("---------------------------------------\n");

    // Read the output a line at a time - output it.
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        char ssid[BUFFER_SIZE];
        char signal[BUFFER_SIZE];

        // Tokenize the buffer based on ':' delimiter used by nmcli
        sscanf(buffer, "%[^:]:%s", ssid, signal);
        
        // Print the formatted data
        printf("%-30s %-6s\n", ssid, signal);
    }

    // Close the file pointer
    if (pclose(fp) == -1) {
        printf("Error closing command stream\n");
        exit(1);
    }
}

int main() {
    // Introduction
    printf("Welcome to the Wireless Network Scanner!\n");
    printf("This program scans for wireless networks in the vicinity.\n\n");

    // Function call to display networks
    displayWirelessNetworks();
    
    // Ending the program
    printf("\nScan complete. Thank you for using the scanner!\n");
    return 0;
}