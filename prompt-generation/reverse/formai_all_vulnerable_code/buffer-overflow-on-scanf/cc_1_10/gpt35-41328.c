//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: multivariable
#include <stdio.h>
#include <string.h>

// Function to check if the given IP address is valid or not
int isValidIpAddress(char *ipAddress) {
    int num, dots = 0;
    char *ptr = ipAddress;

    if (ipAddress == NULL) return 0;

    // Count number of dots and ensure that there are only 3 dots
    while (*ptr) {
        if (*ptr == '.') {
            dots++;
        }
        ptr++;
    }

    if (dots != 3) return 0;

    // Split the IP address into 4 integers
    char octet[4];
    int i = 0;
    ptr = strtok(ipAddress, ".");
    while (ptr != NULL) {
        num = atoi(ptr);

        if (num < 0 || num > 255) return 0;

        octet[i] = num;
        i++;
        ptr = strtok(NULL, ".");
    }

    // Validate that the first octet is not private or reserved
    if (octet[0] == 10
        || (octet[0] == 172 && octet[1] >= 16 && octet[1] <= 31)
        || (octet[0] == 192 && octet[1] == 168)) {
        return 0;
    }

    // Success
    return 1;
}

int main() {
    char ipAddress[20];
    int attempts = 0;

    printf("Enter the IP address of the system to monitor: ");
    scanf("%s", ipAddress);

    // Loop while we have less than 5 attempts and the IP address is not valid
    while (attempts < 5 && !isValidIpAddress(ipAddress)) {
        printf("Invalid IP address. Please enter a valid IP address: ");
        scanf("%s", ipAddress);
        attempts++;
    }

    if (attempts == 5) {
        printf("Exceeded maximum number of attempts. Exiting program.\n");
        return 1;
    }

    // TODO: Perform intrusion detection checks
    printf("Performing intrusion detection checks for IP address: %s\n", ipAddress);

    return 0;
}