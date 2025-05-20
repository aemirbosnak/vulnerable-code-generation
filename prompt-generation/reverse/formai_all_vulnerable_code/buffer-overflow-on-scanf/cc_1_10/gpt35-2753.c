//FormAI DATASET v1.0 Category: Text processing ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 20
#define MAX_MESSAGE_LENGTH 100

typedef struct player {
    char name[MAX_NAME_LENGTH];
    int score;
    char message[MAX_MESSAGE_LENGTH];
} Player;

void print_player(Player p) {
    printf("Name: %s\nScore: %d\nMessage: %s\n", p.name, p.score, p.message);
}

void print_all_players(Player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("Player %d\n", i+1);
        print_player(players[i]);
    }
}

void update_scores(Player players[], int num_players, int points[]) {
    for (int i = 0; i < num_players; i++) {
        players[i].score += points[i];
    }
}

void update_messages(Player players[], int num_players, char messages[][MAX_MESSAGE_LENGTH]) {
    for (int i = 0; i < num_players; i++) {
        strcpy(players[i].message, messages[i]);
    }
}

int main() {
    Player players[MAX_PLAYERS] = {0}; // initialize all fields to 0
    int num_players = 0;
    
    // Get input for number of players and their names
    printf("Enter number of players (up to %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    for (int i = 0; i < num_players; i++) {
        printf("Enter name for player %d: ", i+1);
        scanf("%s", players[i].name);
    }

    int points[MAX_PLAYERS] = {0};
    char messages[MAX_PLAYERS][MAX_MESSAGE_LENGTH];

    // Game loop
    while (1) {
        printf("Enter scores for each player (comma-separated): ");
        for (int i = 0; i < num_players; i++) {
            scanf("%d", &points[i]);
        }
        update_scores(players, num_players, points);
        printf("Scores updated!\n");
        print_all_players(players, num_players);

        printf("Enter messages for each player (one per line):\n");
        for (int i = 0; i < num_players; i++) {
            scanf("%s", messages[i]);
        }
        update_messages(players, num_players, messages);
        printf("Messages updated!\n");
        print_all_players(players, num_players);
    }

    return 0;
}