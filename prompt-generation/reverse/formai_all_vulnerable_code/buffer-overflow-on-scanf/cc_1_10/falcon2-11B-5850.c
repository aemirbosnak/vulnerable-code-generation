//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_PLAYERS 4
#define MAX_GAMES 100
typedef struct {
    char name[50];
    int score;
} Player;
Player players[MAX_PLAYERS];
int num_players;
void add_player(char *name) {
    if (num_players < MAX_PLAYERS) {
        strcpy(players[num_players].name, name);
        players[num_players].score = 0;
        num_players++;
    } else {
        printf("Maximum number of players reached.\n");
    }
}
void remove_player(int index) {
    if (index >= 0 && index < num_players) {
        for (int i = index; i < num_players - 1; i++) {
            players[i] = players[i + 1];
        }
        num_players--;
    } else {
        printf("Invalid player index.\n");
    }
}
void display_scores() {
    printf("Scores:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}
void play_game() {
    int choice = 0;
    do {
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 4) {
            printf("Invalid choice.\n");
        } else {
            switch (choice) {
                case 1:
                    printf("You chose 1.\n");
                    break;
                case 2:
                    printf("You chose 2.\n");
                    break;
                case 3:
                    printf("You chose 3.\n");
                    break;
                case 4:
                    printf("You chose 4.\n");
                    break;
                default:
                    printf("Invalid choice.\n");
            }
        }
    } while (choice < 1 || choice > 4);
}
void start_game() {
    srand(time(NULL));
    int game_number = rand() % MAX_GAMES;
    printf("Game %d\n", game_number + 1);
    play_game();
    printf("Game over.\n");
}
int main() {
    srand(time(NULL));
    num_players = 0;
    while (num_players < MAX_PLAYERS) {
        add_player("Player ");
        num_players++;
    }
    int game_number = 1;
    while (game_number <= MAX_GAMES) {
        start_game();
        game_number++;
    }
    display_scores();
    return 0;
}