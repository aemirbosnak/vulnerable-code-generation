//FormAI DATASET v1.0 Category: Firewall ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Oh my goodness! I can't believe I just created a Firewall program in C!\n");
    printf("My code is going to protect so many networks from malicious activity!\n");
    printf("I can't wait to see the amazed reaction of my colleagues when I show them what I've done!\n");

    int num_ips;
    printf("Enter the number of IPs you want to block: ");
    scanf("%d", &num_ips);

    char** ips = (char**)malloc(num_ips * sizeof(char*));

    for (int i = 0; i < num_ips; i++)
    {
        ips[i] = (char*)malloc(16 * sizeof(char)); // Assume IP addresses are at most 15 characters long
        printf("Enter IP address #%d: ", i + 1);
        scanf("%s", ips[i]);
    }

    printf("Setting up the Firewall...\n");

    // Assume the Firewall is a device that sits in between the internet and a LAN
    // It has two Ethernet ports - one for the internet and one for the LAN
    // It examines every incoming and outgoing packet to determine whether it should be allowed or blocked
    // For simplicity, this program only blocks outgoing packets to the given IPs

    while (1) // Infinite loop - the Firewall is always on
    {
        char packet_dest[16];
        printf("Enter the destination IP address for the outgoing packet: ");
        scanf("%s", packet_dest);

        int is_blocked = 0;
        for (int i = 0; i < num_ips; i++)
        {
            if (strcmp(packet_dest, ips[i]) == 0)
            {
                is_blocked = 1;
                break;
            }
        }

        if (is_blocked)
        {
            printf("Packet blocked by Firewall!\n");
        }
        else
        {
            printf("Packet allowed!\n");
        }
    }

    // Cleanup
    for (int i = 0; i < num_ips; i++)
    {
        free(ips[i]);
    }
    free(ips);

    return 0;
}