//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SERVERS 10
#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    int status; // 0 for down and 1 for up
    time_t last_checked; // last time checked
} server;

server servers[MAX_SERVERS];

int main() {
    int num_servers;
    printf("How many servers you want to monitor? (up to %d): ", MAX_SERVERS);
    scanf("%d", &num_servers);
    if (num_servers > MAX_SERVERS) {
        printf("Too many servers. Exiting...\n");
        return 1;
    }

    // Initialize server names and status
    for (int i = 0; i < num_servers; i++) {
        printf("Enter name for server %d: ", i+1);
        scanf("%s", servers[i].name);
        servers[i].status = 0;
        servers[i].last_checked = time(NULL); // initialize to current time
    }

    printf("Press any key to start monitoring...\n");
    getchar();

    int num_up = 0;
    while (1) {
        printf("\033c"); // Clear screen
        printf("Monitoring %d servers...\n", num_servers);
        printf("----------------------\n");

        num_up = 0;
        for (int i = 0; i < num_servers; i++) {
            if (servers[i].status) {
                printf("\033[1;32m"); // Green
                num_up++;
            } else {
                printf("\033[1;31m"); // Red
            }

            printf("%s\t", servers[i].name);

            if (servers[i].status) {
                printf("UP\t");
            } else {
                printf("DOWN\t");
            }

            printf("Last checked: %s", ctime(&servers[i].last_checked));
            printf("\033[0m"); // Reset color

            // 10% chance of changing status
            int rand_num = rand() % 10 + 1;
            if (rand_num == 1) {
                servers[i].status = !servers[i].status; // Toggle status
                servers[i].last_checked = time(NULL);
            }
        }

        printf("----------------------\n");
        printf("%d servers are up\n", num_up);

        getchar(); // Wait for user to hit enter
    }

    return 0;
}