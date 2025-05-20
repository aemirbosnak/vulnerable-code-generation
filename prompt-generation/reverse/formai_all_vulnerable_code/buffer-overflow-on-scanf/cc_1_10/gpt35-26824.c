//FormAI DATASET v1.0 Category: Text processing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20

typedef struct player {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

Player players[MAX_PLAYERS];
int num_players;

void add_player() {
    char name[MAX_NAME_LENGTH];
    if (num_players == MAX_PLAYERS) {
        printf("Max number of players reached\n");
        return;
    }
    printf("Enter player name: ");
    scanf("%s", name);
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].name, name) == 0) {
            printf("Player already exists\n");
            return;
        }
    }
    strncpy(players[num_players].name, name, MAX_NAME_LENGTH);
    players[num_players].score = 0;
    printf("Player %s added\n", name);
    num_players++;
}

void show_scoreboard() {
    printf("Player\tScore\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s\t%d\n", players[i].name, players[i].score);
    }
}

void update_score() {
    char name[MAX_NAME_LENGTH];
    int score;
    printf("Enter player name: ");
    scanf("%s", name);
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].name, name) == 0) {
            printf("Enter score: ");
            scanf("%d", &score);
            players[i].score += score;
            printf("Score for %s updated. New score: %d\n", players[i].name, players[i].score);
            return;
        }
    }
    printf("Player not found\n");
}

int main() {
    num_players = 0;
    char choice;
    while (1) {
        printf("\nEnter choice: A) Add player S) Show scoreboard U) Update score Q) Quit\n");
        scanf(" %c", &choice);
        switch (choice) {
            case 'A':
            case 'a':
                add_player();
                break;
            case 'S':
            case 's':
                show_scoreboard();
                break;
            case 'U':
            case 'u':
                update_score();
                break;
            case 'Q':
            case 'q':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter A, S, U, or Q\n");
                break;
        }
    }
    return 0;
}