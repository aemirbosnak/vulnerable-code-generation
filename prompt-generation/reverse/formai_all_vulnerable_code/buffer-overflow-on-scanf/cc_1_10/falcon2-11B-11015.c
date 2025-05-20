//Falcon2-11B DATASET v1.0 Category: Wireless Network Scanner ; Style: inquisitive
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Function to print the network details
void printNetworkDetails(char* interfaceName, char* bssid, char* essid, char* channel, char* rate)
{
    printf("Interface Name: %s\n", interfaceName);
    printf("BSSID: %s\n", bssid);
    printf("ESSID: %s\n", essid);
    printf("Channel: %s\n", channel);
    printf("Rate: %s\n", rate);
}

// Function to get the network details
void getNetworkDetails(char* interfaceName, char* bssid, char* essid, char* channel, char* rate)
{
    char command[1000];
    char buffer[1000];
    sprintf(command, "ifconfig %s | grep -A1 'inet'| tail -n 1 | awk '{print $2}'", interfaceName);
    sprintf(command, "iwconfig %s | grep 'BSSID' | awk '{print $2}'", interfaceName);
    sprintf(command, "iwconfig %s | grep 'ESSID' | awk '{print $2}'", interfaceName);
    sprintf(command, "iwconfig %s | grep 'Channel' | awk '{print $2}'", interfaceName);
    sprintf(command, "iwconfig %s | grep 'Rate' | awk '{print $2}'", interfaceName);

    // Execute the command and get the output
    FILE* pipe = popen(command, "r");
    if (pipe == NULL) {
        printf("Error executing command\n");
        exit(1);
    }
    fgets(buffer, sizeof(buffer), pipe);
    pclose(pipe);

    // Parse the output and store the details in the variables
    sscanf(buffer, "%s %s %s %s %s", bssid, essid, channel, rate, interfaceName);
}

// Main function
int main()
{
    char interfaceName[100];
    printf("Enter the wireless network interface name: ");
    scanf("%s", interfaceName);

    char bssid[100];
    char essid[100];
    char channel[100];
    char rate[100];
    getNetworkDetails(interfaceName, bssid, essid, channel, rate);

    printNetworkDetails(interfaceName, bssid, essid, channel, rate);

    return 0;
}