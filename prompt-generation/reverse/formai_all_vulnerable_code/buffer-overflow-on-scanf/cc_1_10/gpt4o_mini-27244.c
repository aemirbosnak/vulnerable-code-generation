//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 30
#define MAX_RECORDS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

typedef struct {
    int player_id;
    int score;
} ScoreRecord;

Player players[MAX_PLAYERS];
ScoreRecord records[MAX_RECORDS];
int player_count = 0;
int record_count = 0;

void add_player(char *name) {
    if (player_count < MAX_PLAYERS) {
        strcpy(players[player_count].name, name);
        players[player_count].score = 0;
        player_count++;
        printf("Player %s added!\n", name);
    } else {
        printf("Cannot add more players. Maximum reached!\n");
    }
}

void update_score(int player_id, int score) {
    if (player_id >= 0 && player_id < player_count) {
        players[player_id].score += score;

        // Log the score in the records
        if (record_count < MAX_RECORDS) {
            records[record_count].player_id = player_id;
            records[record_count].score = players[player_id].score;
            record_count++;
        }

        printf("Score updated for %s. New score: %d\n", players[player_id].name, players[player_id].score);
    } else {
        printf("Invalid player ID!\n");
    }
}

void display_leaderboard() {
    printf("\n--- Leaderboard ---\n");
    for (int i = 0; i < player_count; i++) {
        printf("%d. %s - Score: %d\n", i + 1, players[i].name, players[i].score);
    }
    printf("-------------------\n");
}

void save_score_to_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    for (int i = 0; i < record_count; i++) {
        fprintf(file, "Player ID: %d, Score: %d\n", records[i].player_id, records[i].score);
    }

    fclose(file);
    printf("Scores saved to %s\n", filename);
}

void load_scores_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        int player_id, score;
        sscanf(line, "Player ID: %d, Score: %d", &player_id, &score);
        if (player_id >= 0 && player_id < player_count) {
            players[player_id].score = score;
            if (record_count < MAX_RECORDS) {
                records[record_count].player_id = player_id;
                records[record_count].score = score;
                record_count++;
            }
        }
    }

    fclose(file);
    printf("Scores loaded from %s\n", filename);
}

void menu() {
    int choice, player_id, score;
    char name[MAX_NAME_LENGTH];
    char filename[100];

    while (1) {
        printf("\n--- Multiplayer Data Mining Game Menu ---\n");
        printf("1. Add Player\n");
        printf("2. Update Score\n");
        printf("3. Display Leaderboard\n");
        printf("4. Save Scores to File\n");
        printf("5. Load Scores from File\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter player name: ");
                scanf("%s", name);
                add_player(name);
                break;
            case 2:
                printf("Enter player ID (0 to %d): ", player_count - 1);
                scanf("%d", &player_id);
                printf("Enter score to add: ");
                scanf("%d", &score);
                update_score(player_id, score);
                break;
            case 3:
                display_leaderboard();
                break;
            case 4:
                printf("Enter filename to save: ");
                scanf("%s", filename);
                save_score_to_file(filename);
                break;
            case 5:
                printf("Enter filename to load: ");
                scanf("%s", filename);
                load_scores_from_file(filename);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}