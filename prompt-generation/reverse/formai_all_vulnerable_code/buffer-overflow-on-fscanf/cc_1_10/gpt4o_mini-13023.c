//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define NAME_LENGTH 50
#define SCORE_FILE "scores.txt"

typedef struct {
    char name[NAME_LENGTH];
    int score;
} Player;

void add_score(Player players[], int *player_count);
void display_scores(Player players[], int player_count);
void save_scores(Player players[], int player_count);
void load_scores(Player players[], int *player_count);

int main() {
    Player players[MAX_PLAYERS];
    int player_count = 0;
    int choice;

    load_scores(players, &player_count);

    do {
        printf("\nMultiplayer Score Tracker\n");
        printf("1. Add Player Score\n");
        printf("2. Display Scores\n");
        printf("3. Save Scores to File\n");
        printf("4. Load Scores from File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_score(players, &player_count);
                break;
            case 2:
                display_scores(players, player_count);
                break;
            case 3:
                save_scores(players, player_count);
                break;
            case 4:
                load_scores(players, &player_count);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void add_score(Player players[], int *player_count) {
    if (*player_count >= MAX_PLAYERS) {
        printf("Maximum player limit reached. Cannot add more scores.\n");
        return;
    }

    Player new_player;
    printf("Enter player name: ");
    scanf("%s", new_player.name);
    printf("Enter player score: ");
    scanf("%d", &new_player.score);

    players[*player_count] = new_player;
    (*player_count)++;
    printf("Score added for player: %s\n", new_player.name);
}

void display_scores(Player players[], int player_count) {
    if (player_count == 0) {
        printf("No scores available.\n");
        return;
    }

    printf("\nScores of Players:\n");
    for (int i = 0; i < player_count; i++) {
        printf("Player: %s, Score: %d\n", players[i].name, players[i].score);
    }
}

void save_scores(Player players[], int player_count) {
    FILE *file = fopen(SCORE_FILE, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < player_count; i++) {
        fprintf(file, "%s %d\n", players[i].name, players[i].score);
    }
    fclose(file);
    printf("Scores saved successfully.\n");
}

void load_scores(Player players[], int *player_count) {
    FILE *file = fopen(SCORE_FILE, "r");
    if (file == NULL) {
        printf("No existing score file found. Starting afresh.\n");
        *player_count = 0;
        return;
    }

    *player_count = 0;
    while (fscanf(file, "%s %d", players[*player_count].name, &players[*player_count].score) != EOF) {
        (*player_count)++;
        if (*player_count >= MAX_PLAYERS) {
            break;
        }
    }
    fclose(file);
    printf("Scores loaded successfully. Total players: %d\n", *player_count);
}