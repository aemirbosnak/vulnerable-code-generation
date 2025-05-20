//FormAI DATASET v1.0 Category: File handling ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LEN 50

typedef struct Player {
    char name[MAX_NAME_LEN];
    int score;
} Player;

void display_leaderboard(Player players[], int num_players);
void update_score(Player players[], int num_players, char name[], int score);

int main() {
    Player players[MAX_PLAYERS];
    int num_players = 0;
    char response[MAX_NAME_LEN];
    int score;
    int num_rounds = 0;

    printf("Welcome to the Multiplayer Scoreboard!\n");

    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Display Leaderboard\n");
        printf("2. Update Score\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        fgets(response, MAX_NAME_LEN, stdin);
        response[strlen(response) - 1] = '\0';

        if(strcmp(response, "1") == 0) {
            display_leaderboard(players, num_players);
        }
        else if(strcmp(response, "2") == 0) {
            char name[MAX_NAME_LEN];
            printf("\nEnter player name: ");
            fgets(name, MAX_NAME_LEN, stdin);
            name[strlen(name) - 1] = '\0';

            printf("Enter score: ");
            scanf("%d", &score);
            getchar();

            update_score(players, num_players, name, score);
            num_rounds++;
        }
        else if(strcmp(response, "3") == 0) {
            printf("Thanks for playing! Final Scores:\n");
            display_leaderboard(players, num_players);
            printf("Total number of rounds played: %d\n", num_rounds);
            break;
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void display_leaderboard(Player players[], int num_players) {
    if(num_players == 0) {
        printf("No players yet!\n");
    }
    else {
        printf("Player\tScore\n");
        printf("------\t-----\n");
        for(int i = 0; i < num_players; i++) {
            printf("%s\t%d\n", players[i].name, players[i].score);
        }
    }
}

void update_score(Player players[], int num_players, char name[], int score) {
    int player_index = -1;
    for(int i = 0; i < num_players; i++) {
        if(strcmp(players[i].name, name) == 0) {
            player_index = i;
            break;
        }
    }

    if(player_index == -1) {
        if(num_players >= MAX_PLAYERS) {
            printf("Maximum number of players reached!\n");
            return;
        }

        strncpy(players[num_players].name, name, MAX_NAME_LEN);
        players[num_players].score = score;
        num_players++;
    }
    else {
        players[player_index].score += score;
    }

    printf("%s's score updated.\n", name);
}