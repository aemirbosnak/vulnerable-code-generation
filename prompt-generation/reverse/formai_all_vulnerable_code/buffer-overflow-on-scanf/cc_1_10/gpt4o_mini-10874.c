//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 100
#define NAME_LENGTH 50
#define FILENAME "scores.txt"

typedef struct {
    char name[NAME_LENGTH];
    int score;
} Player;

void addScore();
void viewScores();
void clearScores();
void displayMenu();
void handleInvalidOption();

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left in the buffer
        
        switch (choice) {
            case 1:
                addScore();
                break;
            case 2:
                viewScores();
                break;
            case 3:
                clearScores();
                break;
            case 4:
                printf("Exiting the game. Goodbye!\n");
                break;
            default:
                handleInvalidOption();
                break;
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\nMultiplayer Game Score Management:\n");
    printf("1. Add Score\n");
    printf("2. View Scores\n");
    printf("3. Clear All Scores\n");
    printf("4. Exit\n");
}

void addScore() {
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    Player newPlayer;
    printf("Enter player name: ");
    fgets(newPlayer.name, NAME_LENGTH, stdin);
    newPlayer.name[strcspn(newPlayer.name, "\n")] = 0; // Remove newline character
    printf("Enter player score: ");
    scanf("%d", &newPlayer.score);
    getchar(); // Consume newline character
    
    fprintf(file, "%s %d\n", newPlayer.name, newPlayer.score);
    fclose(file);
    printf("Score added successfully!\n");
}

void viewScores() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    Player existingPlayer;
    printf("\nCurrent Scores:\n");
    while (fscanf(file, "%s %d", existingPlayer.name, &existingPlayer.score) != EOF) {
        printf("Player: %s, Score: %d\n", existingPlayer.name, existingPlayer.score);
    }
    fclose(file);
}

void clearScores() {
    if (remove(FILENAME) == 0) {
        printf("All scores cleared successfully!\n");
    } else {
        perror("Unable to clear scores");
    }
}

void handleInvalidOption() {
    printf("Invalid option! Please enter a valid choice (1-4).\n");
}