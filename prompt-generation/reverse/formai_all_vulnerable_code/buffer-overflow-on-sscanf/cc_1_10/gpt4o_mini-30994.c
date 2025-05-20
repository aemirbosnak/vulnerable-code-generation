//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_BUFFER 1024
#define WIFI_INTERFACE "wlan0"

// Function to execute a shell command and capture its output
char *exec_cmd(const char *cmd) {
    FILE *fp;
    char *output = malloc(MAX_BUFFER);
    if (!output) {
        fprintf(stderr, "Memory allocation failed!\n");
        return NULL;
    }

    fp = popen(cmd, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error executing command: %s\n", cmd);
        free(output);
        return NULL;
    }

    // Read the output a line at a time
    if (fgets(output, MAX_BUFFER, fp) != NULL) {
        // Remove trailing newline character if present
        output[strcspn(output, "\n")] = 0;
    } else {
        fprintf(stderr, "Failed to read command output\n");
        free(output);
        pclose(fp);
        return NULL;
    }

    pclose(fp);
    return output;
}

// Function to get Wi-Fi signal strength
int get_wifi_signal_strength() {
    char cmd[100];
    sprintf(cmd, "iwconfig %s | grep 'Signal level=' | awk '{print $4}' | cut -d'=' -f2", WIFI_INTERFACE);
    char *output = exec_cmd(cmd);

    if (output) {
        int signal_strength;
        if (sscanf(output, "%d", &signal_strength) == 1) {
            free(output);
            return signal_strength;
        } else {
            fprintf(stderr, "Failed to parse signal strength: %s\n", output);
        }
        free(output);
    }
    
    return -1; // Return -1 in case of error
}

// Function to display signal quality
void display_signal_quality(int signal_strength) {
    if (signal_strength == -1) {
        printf("Could not retrieve the signal strength.\n");
        return;
    }
    
    printf("Current Wi-Fi Signal Strength: %d dBm\n", signal_strength);
    
    if (signal_strength >= -50) {
        printf("Signal Quality: Excellent\n");
    } else if (signal_strength >= -60) {
        printf("Signal Quality: Good\n");
    } else if (signal_strength >= -70) {
        printf("Signal Quality: Fair\n");
    } else if (signal_strength >= -80) {
        printf("Signal Quality: Weak\n");
    } else {
        printf("Signal Quality: Very Weak\n");
    }
}

// Main function to run the program
int main() {
    int signal_strength;

    while (1) {
        // Clear screen for better visibility
        printf("\033[H\033[J"); 

        signal_strength = get_wifi_signal_strength();
        display_signal_quality(signal_strength);

        // Wait for a while before checking again
        printf("\nRefreshing in 5 seconds...\n");
        sleep(5);
    }

    return 0;
}