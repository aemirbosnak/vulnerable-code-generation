//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 100
#define NAME_LENGTH 50
#define SCORE_FILE "scores.dat"

typedef struct {
    char name[NAME_LENGTH];
    int score;
} Player;

void addPlayerScore();
void viewScores();
void searchScore();
void clearInputBuffer();

int main() {
    int choice;

    do {
        printf("\n--- Multiplayer Database Indexing System ---\n");
        printf("1. Add Player Score\n");
        printf("2. View All Scores\n");
        printf("3. Search Player Score\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer(); // To handle leftover newline

        switch(choice) {
            case 1:
                addPlayerScore();
                break;
            case 2:
                viewScores();
                break;
            case 3:
                searchScore();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addPlayerScore() {
    Player player;
    FILE *file = fopen(SCORE_FILE, "a");
    if (file == NULL) {
        perror("Unable to open score file");
        return;
    }

    printf("Enter player name: ");
    fgets(player.name, NAME_LENGTH, stdin);
    player.name[strcspn(player.name, "\n")] = '\0'; // Remove newline character

    printf("Enter player score: ");
    scanf("%d", &player.score);
    clearInputBuffer();

    fwrite(&player, sizeof(Player), 1, file);
    fclose(file);

    printf("Score of %s (Score: %d) added successfully!\n", player.name, player.score);
}

void viewScores() {
    Player player;
    FILE *file = fopen(SCORE_FILE, "r");
    if (file == NULL) {
        perror("Unable to open score file");
        return;
    }

    printf("\n--- Player Scores ---\n");
    while (fread(&player, sizeof(Player), 1, file)) {
        printf("Player: %s, Score: %d\n", player.name, player.score);
    }

    fclose(file);
}

void searchScore() {
    char searchName[NAME_LENGTH];
    Player player;
    int found = 0;

    printf("Enter player name to search: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Remove newline character

    FILE *file = fopen(SCORE_FILE, "r");
    if (file == NULL) {
        perror("Unable to open score file");
        return;
    }

    while (fread(&player, sizeof(Player), 1, file)) {
        if (strcmp(player.name, searchName) == 0) {
            printf("Found: Player: %s, Score: %d\n", player.name, player.score);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Player %s not found.\n", searchName);
    }

    fclose(file);
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Clear the input buffer
}