//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: happy
#include <stdio.h>

int main() {
    printf("Welcome to Happy IDS Program!\n");

    // Declare variables
    int numConnections = 0;
    int numMaliciousConnections = 0;
    int totalTraffic = 0;
    int maliciousTraffic = 0;
    char ipAddr[16];
    char action[10];

    // Start monitoring
    printf("IDS Program is now running...\n");
    printf("To stop monitoring, enter 'stop':\n");
    while (1) {
        printf("Enter IP Address of incoming connection:\n");
        scanf("%s", ipAddr);

        // Check for stopping condition
        if (strcmp(ipAddr, "stop") == 0) {
            printf("IDS Program is now stopping...\n");
            break;
        }

        // Record connection
        numConnections++;
        printf("Connection %d recorded.\n", numConnections);

        // Check for malicious traffic
        printf("Enter action performed (allow/deny):\n");
        scanf("%s", action);
        if (strcmp(action, "deny") == 0) {
            numMaliciousConnections++;
            printf("Malicious traffic detected! Connection %d denied.\n", numConnections);
        }

        // Record traffic
        int traffic;
        printf("Enter amount of traffic (in bytes):\n");
        scanf("%d", &traffic);
        totalTraffic += traffic;
        if (strcmp(action, "deny") == 0) {
            maliciousTraffic += traffic;
        }
        printf("%d bytes of traffic recorded for connection %d.\n", traffic, numConnections);
    }

    // Display results
    printf("IDS Program summary:\n");
    printf("Total connections: %d\n", numConnections);
    printf("Malicious connections: %d\n", numMaliciousConnections);
    printf("Total traffic: %d bytes\n", totalTraffic);
    printf("Malicious traffic: %d bytes\n", maliciousTraffic);

    return 0;
}