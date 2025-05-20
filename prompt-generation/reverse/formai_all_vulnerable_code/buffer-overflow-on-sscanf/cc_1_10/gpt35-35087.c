//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Maximum number of connections

typedef struct {
    char ip[20];
    int port;
    int attempts;
} Connection;

int main() {
    Connection connections[MAX_SIZE]; // Array of connections
    int num_connections = 0; // Number of connections in the array

    // Read connections from a file
    FILE *file = fopen("connections.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char ip[20];
        int port;
        sscanf(line, "%s %d", ip, &port);
        Connection c = {ip, port, 0};
        connections[num_connections++] = c;
    }
    fclose(file);

    // Continuously monitor connections for suspicious activity
    while (true) {
        for (int i = 0; i < num_connections; i++) {
            Connection *c = &connections[i];

            // Simulate incoming traffic
            int traffic = rand() % 100;

            // If traffic is suspicious, increment number of attempts
            if (traffic > 80) {
                c->attempts++;
            }

            // If number of attempts is greater than 5, notify the user and remove the connection
            if (c->attempts > 5) {
                printf("IP %s on port %d has attempted to connect %d times.\n", c->ip, c->port, c->attempts);
                printf("Removing connection from list.\n");
                num_connections--;
                for (int j = i; j < num_connections; j++) {
                    connections[j] = connections[j+1];
                }
            }
        }
    }

    return 0;
}