//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_INTERFACES 10
#define MAX_BUFFER_SIZE 256

void displayError(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void listWiFiInterfaces() {
    printf("Available Wi-Fi Interfaces:\n");
    system("iw dev | awk '/Interface/ {print $2}'");
}

int getSignalStrength(const char *interface, int *signalStrength) {
    char command[MAX_BUFFER_SIZE];
    snprintf(command, sizeof(command), "iwconfig %s | grep 'Signal level=' | awk '{print $4}' | sed 's/level=//'", interface);

    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        displayError("Failed to run command");
        return -1; 
    }

    if (fgets(command, sizeof(command), fp) != NULL) {
        *signalStrength = atoi(command);
        pclose(fp);
        return 0; 
    } else {
        pclose(fp);
        return -1; 
    }
}

void monitorSignalStrength(const char *interface) {
    int signalStrength;
    printf("Monitoring signal strength for %s...\n", interface);
    while (1) {
        if (getSignalStrength(interface, &signalStrength) == 0) {
            printf("Current Signal Strength: %d dBm\n", signalStrength);
        } else {
            printf("Could not retrieve signal strength.\n");
        }
        sleep(2);
        printf("\033[F");  // Move cursor up one line
    }
}

void signalHandler(int signum) {
    printf("\nExiting...\n");
    exit(EXIT_SUCCESS);
}

int main() {
    signal(SIGINT, signalHandler);
    
    listWiFiInterfaces();

    char selectedInterface[MAX_BUFFER_SIZE];
    printf("Enter the name of the Wi-Fi interface to monitor: ");
    scanf("%s", selectedInterface);

    int signalStrength;
    if (getSignalStrength(selectedInterface, &signalStrength) == 0) {
        printf("Initial Signal Strength for %s: %d dBm\n", selectedInterface, signalStrength);
    } else {
        printf("Could not retrieve initial signal strength for %s.\n", selectedInterface);
        return EXIT_FAILURE; 
    }

    monitorSignalStrength(selectedInterface);
    return EXIT_SUCCESS;
}