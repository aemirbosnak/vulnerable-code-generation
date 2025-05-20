//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_SSID_LENGTH 30

int main() {
    char command[MAX_LINES];
    char output[MAX_LINES];
    char ssid[MAX_SSID_LENGTH];
    int signal_strength, max_signal_strength = -1000;

    printf("Welcome to Wi-Fi Signal Strength Analyzer.\n");
    printf("Please enter the SSID you want to scan: ");
    scanf("%s", ssid);

    // Store the command to scan for signal strength of desired SSID 
    sprintf(command, "sudo iwlist wlan0 scan | grep -ioE '%s[^\\n]+' | grep -ioE 'signal level=\\w+' | grep -oE '-\\w+'", ssid);

    FILE *fp = popen(command, "r"); // Open the command in read mode

    if (fp == NULL) {
        perror("Failed to execute command");
        exit(EXIT_FAILURE);
    }

    while (fgets(output, MAX_LINES, fp) != NULL) { // Read the output from command line by line
        signal_strength = atoi(output);
        if (signal_strength > max_signal_strength) {
            max_signal_strength = signal_strength; // Track the maximum signal strength for desired SSID
        }
    }

    pclose(fp); // Close the file pointer

    if (max_signal_strength == -1000) { // If signal strength not found
        printf("No signal strength found for SSID %s.\n", ssid);
    } else if (max_signal_strength >= -50) { // If signal strength is too strong
        printf("Caution: Signal strength is extremely strong (%d dBm) for SSID %s.\n", max_signal_strength, ssid);
    } else if (max_signal_strength >= -70) { // If signal strength is good
        printf("Signal strength is good (%d dBm) for SSID %s.\n", max_signal_strength, ssid);
    } else if (max_signal_strength >= -80) { // If signal strength is average
        printf("Signal strength is average (%d dBm) for SSID %s.\n", max_signal_strength, ssid);
    } else if (max_signal_strength >= -90) { // If signal strength is poor
        printf("Signal strength is poor (%d dBm) for SSID %s.\n", max_signal_strength, ssid);
    } else { // If signal strength is too weak
        printf("Caution: Signal strength is extremely weak (%d dBm) for SSID %s.\n", max_signal_strength, ssid);
    }

    return 0;
}