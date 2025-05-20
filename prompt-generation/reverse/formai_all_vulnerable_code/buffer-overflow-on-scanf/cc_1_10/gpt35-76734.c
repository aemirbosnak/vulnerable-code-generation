//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONNECTIONS 10
#define MAX_IP_LENGTH 16

struct connection {
    char ip[MAX_IP_LENGTH];
    int port;
    int active;
    time_t last_seen;
};

int main() {
    struct connection connections[MAX_CONNECTIONS];
    int num_connections = 0;
    time_t current_time;
    char new_ip[MAX_IP_LENGTH];

    while (1) {
        printf("Enter new connection IP (or 'q' to quit): ");
        scanf("%s", new_ip);

        if (strcmp(new_ip, "q") == 0) {
            break;
        }

        printf("Enter new connection port: ");
        int new_port;
        scanf("%d", &new_port);

        time(&current_time);

        int found = 0;
        for (int i = 0; i < num_connections; i++) {
            if (strcmp(connections[i].ip, new_ip) == 0) {
                found = 1;
                if (connections[i].active) {
                    printf("Detected potential intrusion from existing IP: %s\n", new_ip);
                    connections[i].last_seen = current_time;
                } else {
                    printf("Reactivating inactive connection from IP: %s\n", new_ip);
                    connections[i].active = 1;
                    connections[i].last_seen = current_time;
                }
                break;
            }
        }

        if (!found) {
            if (num_connections >= MAX_CONNECTIONS) {
                printf("Max connections exceeded, ignoring new connection from IP: %s\n", new_ip);
            } else {
                printf("Adding new connection from IP: %s\n", new_ip);
                struct connection new_connection;
                strcpy(new_connection.ip, new_ip);
                new_connection.port = new_port;
                new_connection.active = 1;
                new_connection.last_seen = current_time;
                connections[num_connections++] = new_connection;
            }
        }
    }

    printf("Summary of active connections:\n");
    for (int i = 0; i < num_connections; i++) {
        if (connections[i].active) {
            printf("%s:%d (last seen: %s)", connections[i].ip, connections[i].port, ctime(&connections[i].last_seen));
        }
    }

    return 0;
}