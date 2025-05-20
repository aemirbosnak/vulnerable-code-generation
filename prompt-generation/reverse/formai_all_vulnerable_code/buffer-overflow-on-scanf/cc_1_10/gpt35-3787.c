//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <regex.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>

#define MAX_STR_LEN 50

void get_wifi_strength(char *interface_name, char *strength) {
    char command[MAX_STR_LEN];
    char output[MAX_STR_LEN];
    FILE *fp;

    // Construct the command
    sprintf(command, "iwconfig %s | grep Signal | awk '{print $4}'", interface_name);

    // Open the command for reading
    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to run command\n" );
        exit(1);
    }

    // Read the output
    fgets(output, sizeof(output), fp);

    // Remove the newline character at the end of the output string
    strtok(output, "\n");

    // Copy the output string to strength
    strcpy(strength, output);

    // Close the stream of the command
    pclose(fp);
}

int main() {
    char interface_name[MAX_STR_LEN];
    char strength[MAX_STR_LEN];
    int choice;

    // Display available network interfaces
    printf("Available network interfaces:\n");
    system("ifconfig | grep -o '^[^ ]*'");

    // Get the name of the network interface
    printf("\nEnter network interface name: ");
    scanf("%s", interface_name);

    // Clear the input buffer
    while ((getchar()) != '\n');

    // Continuously display the Wi-Fi signal strength
    while (1) {
        // Clear the console
        system("clear");

        // Get the Wi-Fi signal strength
        get_wifi_strength(interface_name, strength);

        // Display the Wi-Fi signal strength
        printf("Wi-Fi signal strength: %s dBm\n", strength);

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}