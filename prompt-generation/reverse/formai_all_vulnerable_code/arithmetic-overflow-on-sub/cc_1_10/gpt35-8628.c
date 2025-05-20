//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESS_NAME_LENGTH 20
#define MAX_NUM_PROCESSES 20
#define MAX_NUM_PLAYERS 4

struct Process {
    char name[MAX_PROCESS_NAME_LENGTH];
    int process_id;
    double cpu_usage;
};

struct Player {
    char name[20];
    int player_id;
    int num_processes;
    struct Process processes[MAX_NUM_PROCESSES];
};

void add_process(struct Player* player) {
    if (player->num_processes >= MAX_NUM_PROCESSES) {
        printf("Max process limit reached.\n");
        return;
    }

    struct Process new_process;
    printf("Enter process name: ");
    scanf("%s", new_process.name);
    printf("Enter process ID: ");
    scanf("%d", &new_process.process_id);
    printf("Enter cpu usage: ");
    scanf("%lf", &new_process.cpu_usage);

    player->processes[player->num_processes++] = new_process;
}

void print_processes(struct Player player) {
    printf("------------------------\n");
    printf("Player: %s\n", player.name);
    printf("ID: %d\n", player.player_id);
    printf("Number of processes: %d\n", player.num_processes);
    printf("------------------------\n");

    for (int i = 0; i < player.num_processes; i++) {
        printf("Name: %s | PID: %d | CPU Usage: %f\n", 
            player.processes[i].name, 
            player.processes[i].process_id, 
            player.processes[i].cpu_usage);
    }
}

int main() {
    struct Player players[MAX_NUM_PLAYERS];
    int num_players;

    printf("Enter number of players: ");
    scanf("%d", &num_players);
    getchar(); //clears the newline left by scanf

    for (int i = 0; i < num_players; i++) {
        struct Player new_player;
        printf("Enter player %d name: ", i+1);
        fgets(new_player.name, sizeof(new_player.name), stdin);
        new_player.name[strcspn(new_player.name, "\n")] = 0;
        new_player.player_id = i+1;
        new_player.num_processes = 0;

        players[i] = new_player;
    }

    int option, player_id;
    while (1) {
        printf("Enter option:\n1. Add Process\n2. Print Processes\n3. Exit\n");
        scanf("%d", &option);
        getchar(); //clears the newline left by scanf

        switch (option) {
            case 1: 
                printf("Enter player ID to add process: ");
                scanf("%d", &player_id);
                getchar();
                add_process(&players[player_id-1]);
                break;
            case 2:
                for (int i = 0; i < num_players; i++) {
                    print_processes(players[i]);
                }
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option selected.\n");
        }
    }

    return 0;
}