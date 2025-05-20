//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to check if a given IP address is malicious
int isMaliciousIP(char *ipAddress) {
    // implementation of a set of known malicious IP addresses
    char *maliciousIPs[] = {"10.0.0.1", "192.168.0.1", "172.16.0.1"};
    int numberOfMaliciousIPs = sizeof(maliciousIPs) / sizeof(maliciousIPs[0]);
    for (int i = 0; i < numberOfMaliciousIPs; i++) {
        if (strcmp(ipAddress, maliciousIPs[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    // Variables to store the user input
    char ipAddress[16];
    char protocol[10];
    int port, isMalicious;

    // Capture user input
    printf("Enter the IP address: ");
    scanf("%s", &ipAddress);
    printf("Enter the protocol (UDP/TCP): ");
    scanf("%s", &protocol);
    printf("Enter the port number: ");
    scanf("%d", &port);

    // Check if the IP address is malicious
    isMalicious = isMaliciousIP(ipAddress);
    if (isMalicious) {
        printf("WARNING: The entered IP address %s is known to be malicious.\n", ipAddress);
    }

    // Check if the protocol is not TCP or UDP
    if (strcmp(protocol, "TCP") != 0 && strcmp(protocol, "UDP") != 0) {
        printf("ERROR: Invalid protocol entered. Please enter TCP or UDP.\n");
        return 1;
    }

    // Check if the port number is less than 1 or greater than 65535
    if (port < 1 || port > 65535) {
        printf("ERROR: Invalid port number entered. Please enter a value between 1 and 65535.\n");
        return 1;
    }

    // If all checks pass, print a success message
    printf("SUCCESS: The entered IP address %s, protocol %s and port %d are valid.\n", ipAddress, protocol, port);

    // Exit the program with exit code 0
    return 0;
}