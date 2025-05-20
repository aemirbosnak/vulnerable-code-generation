//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SSID_LENGTH 256

int main()
{
    char command[256] = "";
    char output[1024] = "";
    int signalStrength;
    char ssid[MAX_SSID_LENGTH] = "";
    int numNetworks = 0, totalSignalStrength = 0, maxSignalStrength = -100;
    double averageSignalStrength;

    printf("Scanning for wireless networks...\n");

    sprintf(command, "iwlist wlan0 scan | grep 'ESSID' | sed 's/\"//g' | cut -d : -f 2");
    FILE* pipe = popen(command, "r");

    if (!pipe)
    {
        printf("Error: Failed to execute command\n");
        return 1;
    }

    while (fgets(ssid, MAX_SSID_LENGTH, pipe))
    {
        // Remove newline character from SSID string
        ssid[strcspn(ssid, "\n")] = 0;

        // Ignore empty SSIDs
        if (strlen(ssid) == 0) continue;

        // Get signal strength for current SSID
        sprintf(command, "iwconfig wlan0 | grep '%s' -A 1 | grep 'Signal level' | cut -d '=' -f 3 | cut -d ' ' -f 1", ssid);

        FILE* signalPipe = popen(command, "r");
        if (!signalPipe)
        {
            printf("Error: Failed to execute command for signal strength of SSID: %s\n", ssid);
        }
        else
        {
            fscanf(signalPipe, "%d", &signalStrength);
            pclose(signalPipe);

            // Increment network count and total signal strength for current SSID
            numNetworks++;
            totalSignalStrength += signalStrength;

            // Update max signal strength if current SSID's signal strength is greater
            if (signalStrength > maxSignalStrength) maxSignalStrength = signalStrength;

            // Concatenate current network's SSID and signal strength to output string
            sprintf(output + strlen(output), "%s: %d dBm\n", ssid, signalStrength);
        }
    }

    pclose(pipe);

    // Calculate average signal strength
    if (numNetworks > 0) averageSignalStrength = (double) totalSignalStrength / numNetworks;
    else averageSignalStrength = 0;

    // Print summary statistics
    printf("\n%d wireless networks found:\n%s\n", numNetworks, output);
    printf("Maximum signal strength: %d dBm\n", maxSignalStrength);
    printf("Average signal strength: %0.2f dBm\n", averageSignalStrength);

    return 0;
}