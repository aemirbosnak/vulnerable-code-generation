//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: configurable
#include <stdio.h>
#include <stdint.h>

// Function to check if the input IP address is valid
int isValidIP(char *ipAddr)
{
    // Counting the number of blocks in the IP address
    int blocks = 0;
    for (int i = 0; ipAddr[i]; i++)
    {
        if (ipAddr[i] == '.')
            blocks++;
    }
    if (blocks != 3)
        return 0;

    // Converting input IP address to individual blocks
    uint8_t ipBlocks[4] = {0};
    int pos = 0;
    for (int i = 0; ipAddr[i]; i++)
    {
        if (ipAddr[i] == '.')
        {
            ipAddr[i] = '\0';
            ipBlocks[pos++] = atoi(ipAddr);
            ipAddr += (i - pos + 1);
        }
    }
    ipBlocks[pos] = atoi(ipAddr);

    // Checking if each block is within the valid range (0-255)
    for (int i = 0; i < 4; i++)
    {
        if (ipBlocks[i] < 0 || ipBlocks[i] > 255)
            return 0;
    }

    return 1;
}

// Function to calculate the subnet mask
uint32_t getSubnetMask(int prefixLength)
{
    uint32_t subnetMask = 0xFFFFFFFF;
    subnetMask <<= (32 - prefixLength);
    return subnetMask;
}

// Main function
int main()
{
    char ipAddr[16] = {0};
    int prefixLength;

    // Taking input IP address and prefix length from user
    printf("Enter IP address in dotted decimal format: ");
    scanf("%15s", ipAddr);
    printf("Enter prefix length: ");
    scanf("%d", &prefixLength);

    // Validating IP address
    if (!isValidIP(ipAddr))
    {
        printf("Invalid IP address! Exiting...");
        return 1;
    }

    // Validating prefix length
    if (prefixLength < 0 || prefixLength > 32)
    {
        printf("Invalid prefix length! Exiting...");
        return 1;
    }

    // Converting IP address into 32 bit integer
    uint32_t ipInt = 0;
    char *ipOctets = strtok(ipAddr, ".");
    while (ipOctets != NULL)
    {
        ipInt = (ipInt << 8) | atoi(ipOctets);
        ipOctets = strtok(NULL, ".");
    }

    // Calculating subnet mask
    uint32_t subnetMask = getSubnetMask(prefixLength);

    // Calculating network ID, broadcast and usable hosts range
    uint32_t netID = ipInt & subnetMask;
    uint32_t broadcastID = netID | ~subnetMask;
    uint32_t usableRangeStart = netID + 1;
    uint32_t usableRangeEnd = broadcastID - 1;

    // Converting network ID, broadcast and usable hosts range back to IP address format
    char netIDStr[16] = {0};
    sprintf(netIDStr, "%u.%u.%u.%u", (netID >> 24), ((netID >> 16) & 0xFF), ((netID >> 8) & 0xFF), (netID & 0xFF));
    char broadcastIDStr[16] = {0};
    sprintf(broadcastIDStr, "%u.%u.%u.%u", (broadcastID >> 24), ((broadcastID >> 16) & 0xFF), ((broadcastID >> 8) & 0xFF), (broadcastID & 0xFF));
    char usableRangeStartStr[16] = {0};
    sprintf(usableRangeStartStr, "%u.%u.%u.%u", (usableRangeStart >> 24), ((usableRangeStart >> 16) & 0xFF), ((usableRangeStart >> 8) & 0xFF), (usableRangeStart & 0xFF));
    char usableRangeEndStr[16] = {0};
    sprintf(usableRangeEndStr, "%u.%u.%u.%u", (usableRangeEnd >> 24), ((usableRangeEnd >> 16) & 0xFF), ((usableRangeEnd >> 8) & 0xFF), (usableRangeEnd & 0xFF));

    // Printing calculated values
    printf("\nResults:\n");
    printf("IP address: %s\n", ipAddr);
    printf("Subnet mask: %u.%u.%u.%u\n", ((subnetMask >> 24) & 0xFF), ((subnetMask >> 16) & 0xFF), ((subnetMask >> 8) & 0xFF), (subnetMask & 0xFF));
    printf("Network ID: %s\n", netIDStr);
    printf("Broadcast ID: %s\n", broadcastIDStr);
    printf("Usable hosts range: %s - %s\n", usableRangeStartStr, usableRangeEndStr);

    return 0;
}