//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_ACTIONS 5
#define ACTION_TIMEOUT 10

typedef struct {
    char name[30];
    time_t last_action_time;
    int action_count;
} Player;

typedef struct {
    char action[30];
    time_t timestamp;
} PlayerAction;

Player players[MAX_PLAYERS];
int player_count = 0;

void add_player(const char* name) {
    if (player_count < MAX_PLAYERS) {
        strcpy(players[player_count].name, name);
        players[player_count].last_action_time = time(NULL);
        players[player_count].action_count = 0;
        player_count++;
    } else {
        printf("Maximum player limit reached.\n");
    }
}

void log_action(const char* name, const char* action) {
    for (int i = 0; i < player_count; i++) {
        if (strcmp(players[i].name, name) == 0) {
            players[i].last_action_time = time(NULL);
            players[i].action_count++;
            printf("Player '%s' performed action: '%s'\n", name, action);
            return;
        }
    }
    printf("Player '%s' not found.\n", name);
}

void check_for_intrusions() {
    time_t current_time = time(NULL);
    for (int i = 0; i < player_count; i++) {
        if (current_time - players[i].last_action_time > ACTION_TIMEOUT && players[i].action_count > MAX_ACTIONS) {
            printf("Intrusion detected for player '%s'! Possible Cheating!\n", players[i].name);
            players[i].action_count = 0; // Reset count after detection
        }
    }
}

void display_players() {
    printf("\nCurrent Players:\n");
    for (int i = 0; i < player_count; i++) {
        printf("Player: %s, Last Action Time: %ld, Action Count: %d\n",
               players[i].name, (long)players[i].last_action_time, players[i].action_count);
    }
}

int main() {
    add_player("Player1");
    add_player("Player2");
    
    log_action("Player1", "Move");
    sleep(1);
    log_action("Player1", "Jump");
    sleep(2);
    log_action("Player1", "Attack");
    
    log_action("Player2", "Move");
    sleep(1);
    log_action("Player2", "Jump");
    sleep(12); // Simulate time passing for intrusion check

    check_for_intrusions();
    display_players();

    // Simulating more actions
    printf("\nSimulating further actions...\n");
    sleep(5);
    
    log_action("Player1", "Run");
    sleep(1);
    log_action("Player1", "Reposition");
    
    check_for_intrusions();
    display_players();

    return 0;
}