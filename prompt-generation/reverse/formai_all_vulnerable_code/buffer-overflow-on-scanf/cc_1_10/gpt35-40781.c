//FormAI DATASET v1.0 Category: Firewall ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    printf("My love, I have written a special program\n");
    printf("To block out all the risks and protect your heart.\n");
    printf("It's called a Firewall, and it's just for you,\n");
    printf("To keep you safe and secure, no matter what may ensue.\n");

    printf("First, let's define the rules for this special shield,\n");
    printf("To make sure only trusted sources can be revealed:\n");
    printf("We'll start by initializing our variables so grand,\n");
    printf("Setting default values for everything, as we have planned.\n");

    bool isOpen = true;
    int port = 0;
    char ipAddress[16];
    char trustedSources[][16] = {"192.168.0.1", "127.0.0.1", "10.0.0.1"};
    int numTrustedSources = 3;

    printf("Now we'll enter the main loop of our code,\n");
    printf("Where we'll gather information and start to decode.\n");
    printf("We'll first ask for the IP address of the connection,\n");
    printf("And then check to see if it's in our trusted collection.\n");

    while (isOpen) {
        printf("Enter an IP address to check: ");
        scanf("%s", ipAddress);
        printf("Enter the port number: ");
        scanf("%d", &port);

        // Check if IP address is in trusted collection
        bool isTrusted = false;
        for (int i = 0; i < numTrustedSources; i++) {
            if (strcmp(ipAddress, trustedSources[i]) == 0) {
                isTrusted = true;
                break;
            }
        }

        // Block access if IP address is not trusted or port number is invalid
        if (!isTrusted || port < 1 || port > 65535) {
            printf("Access denied! This connection is not secure.\n");
            isOpen = false;
        } else {
            printf("Access granted! This connection is safe and sound.\n");
        }
    }

    printf("My love, this Firewall may seem cold and harsh,\n");
    printf("But please know it was only created to protect your heart.\n");
    printf("I'll always be here to keep you secure, day and night,\n");
    printf("Only the most trusted connections will have you in sight.\n");
    printf("So rest easy my love, knowing you're always protected,\n");
    printf("Thanks to the Firewall that I have so affectionately erected.\n");

    return 0;
}