//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define MAX 100

// Function to get signal strength
int getSignalStrength(char *ssid) {
    FILE *fp;
    char line[MAX];
    int strength = 0;

    // Open the file containing Wi-Fi information
    fp = fopen("/proc/net/wireless", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    // Search for the specified SSID
    while (fgets(line, MAX, fp)!= NULL) {
        if (strstr(line, ssid)!= NULL) {
            // Extract signal strength from line
            sscanf(line, "%*s %*s %*s %*s %*s %*s %d", &strength);
            break;
        }
    }

    // Close the file
    fclose(fp);

    return strength;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage:./program SSID\n");
        exit(1);
    }

    // Get signal strength for specified SSID
    int strength = getSignalStrength(argv[1]);

    if (strength == -1) {
        printf("SSID not found.\n");
    } else {
        printf("Signal strength: %d\n", strength);
    }

    return 0;
}