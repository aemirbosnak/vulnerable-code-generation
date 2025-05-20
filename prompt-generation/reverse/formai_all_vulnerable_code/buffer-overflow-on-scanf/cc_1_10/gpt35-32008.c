//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_LENGTH 100

// Struct to hold each player's information
struct Player {
    char name[MAX_LENGTH];
    int pid;
    float cpu_usage;
};

// Function to check the usage of the CPU
float get_cpu_usage(int pid) {
    char cmd[MAX_LENGTH];
    sprintf(cmd, "ps -p %d -o %%cpu | tail -n +2", pid);
    
    FILE* fp = popen(cmd, "r");
    if (!fp) {
        perror("Error in opening pipe");
        exit(1);
    }

    char buffer[MAX_LENGTH];
    if (!fgets(buffer, MAX_LENGTH, fp)) {
        perror("Error in reading pipe");
        exit(1);
    }
    
    pclose(fp);

    return atof(buffer);
}

int main() {
    // Initialize players array
    struct Player players[MAX_PLAYERS];
    int num_players = 0;

    // Keep getting player input until there are no more players or the maximum number of players has been reached
    while (num_players < MAX_PLAYERS) {
        printf("Enter player name (or 'q' to quit): ");
        char name[MAX_LENGTH];
        scanf("%s", name);

        if (strcmp(name, "q") == 0) {
            break;
        }

        printf("Enter player PID: ");
        int pid;
        scanf("%d", &pid);

        // Check if pid already exists for another player
        int pid_exists = 0;
        for (int i = 0; i < num_players; i++) {
            if (players[i].pid == pid) {
                printf("Error: PID already assigned to %s\n", players[i].name);
                pid_exists = 1;
                break;
            }
        }

        if (pid_exists) {
            continue;
        }

        // Add player to array
        struct Player new_player = { .pid = pid };
        strncpy(new_player.name, name, MAX_LENGTH - 1);

        players[num_players++] = new_player;
    }

    // Continuously print out the CPU usage for each player
    while (1) {
        printf("\n-----------------------------------------\n");
        for (int i = 0; i < num_players; i++) {
            // Get the CPU usage for this player
            float cpu_usage = get_cpu_usage(players[i].pid);

            // Update the player's CPU usage
            players[i].cpu_usage = cpu_usage;

            // Print out the player's information
            printf("%s: %.2f%%\n", players[i].name, players[i].cpu_usage);
        }

        // Sleep for 1 second before printing again
        sleep(1);
    }

    return 0;
}