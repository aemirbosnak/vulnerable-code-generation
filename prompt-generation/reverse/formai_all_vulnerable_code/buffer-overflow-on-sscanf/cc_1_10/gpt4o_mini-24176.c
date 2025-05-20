//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to execute the command and capture its output
void executeCommand(const char* command, char* result, size_t size) {
    FILE* pipe = popen(command, "r");
    if (pipe == NULL) {
        fprintf(stderr, "[ERROR] Failed to run command\n");
        exit(1);
    }
    fgets(result, size, pipe);
    pclose(pipe);
}

// Function to display the signal strength
void displaySignalStrength() {
    char command[] = "nmcli -t -f ssid,signal dev wifi"; // Command to list Wi-Fi networks and their signal strengths
    char buffer[1024];

    printf("\n=== Wi-Fi Signal Strength Analyzer ===\n");
    printf("Scanning for available networks...\n\n");

    // Execute the command and store the output
    executeCommand(command, buffer, sizeof(buffer));

    printf("%-30s | %s\n", "SSID", "Signal Strength (%)");
    printf("------------------------------------------\n");

    char* line = strtok(buffer, "\n");
    // Loop through each available network
    while (line != NULL) {
        char ssid[64];
        char signal[8];

        // Split SSID and signal strength
        sscanf(line, "%[^:]:%s", ssid, signal);

        // Display the result
        printf("%-30s | %s%%\n", ssid, signal);
        line = strtok(NULL, "\n");
    }

    printf("\n=== End of Scan ===\n");
}

int main() {
    printf("Welcome to the Amazing Wi-Fi Signal Strength Analyzer! 🎉\n");
    printf("Get ready to discover your wireless networks!\n\n");

    // Invoke the function to display signal strengths
    displaySignalStrength();

    // Ending message
    printf("Thanks for using the analyzer! Happy surfing! 🚀\n");
    return 0;
}