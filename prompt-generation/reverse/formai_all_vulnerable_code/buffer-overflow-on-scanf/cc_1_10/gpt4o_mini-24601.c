//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_FILES 5
#define FILE_NAME_LENGTH 20
#define HINT_LENGTH 100

typedef struct {
    char name[20];
    int score;
} Player;

typedef struct {
    char filename[FILE_NAME_LENGTH];
    char hint[HINT_LENGTH];
    int recovered;
} File;

void displayInstructions() {
    printf("=== Welcome to the Data Recovery Challenge! ===\n");
    printf("The goal is to recover files by providing hints to one another.\n");
    printf("Each player can give hints and recover files, gaining points in the process.\n");
    printf("The game ends when all files are recovered. Good luck!\n\n");
}

void initFiles(File files[]) {
    const char *filenames[MAX_FILES] = {"document.docx", "photo.png", "video.mp4", "spreadsheet.xls", "presentation.pptx"};
    const char *hints[MAX_FILES] = {
        "This is a text document often used for reports.",
        "It's an image of a sunset.",
        "This file contains moving pictures.",
        "You do calculations and graphs with this.",
        "This is used for sharing ideas during a presentation."
    };

    for (int i = 0; i < MAX_FILES; i++) {
        strcpy(files[i].filename, filenames[i]);
        strcpy(files[i].hint, hints[i]);
        files[i].recovered = 0;
    }
}

void displayScores(Player players[], int num_players) {
    printf("\n=== Scores ===\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d points\n", players[i].name, players[i].score);
    }
    printf("\n");
}

int main() {
    Player players[MAX_PLAYERS];
    File files[MAX_FILES];
    int num_players = 0;

    displayInstructions();

    // Setup players
    printf("Enter the number of players (1 to %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    getchar(); // to consume newline

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players!\n");
        return 1;
    }

    for (int i = 0; i < num_players; i++) {
        printf("Enter name for player %d: ", i + 1);
        fgets(players[i].name, sizeof(players[i].name), stdin);
        players[i].name[strcspn(players[i].name, "\n")] = 0; // remove newline
        players[i].score = 0;
    }

    initFiles(files);

    int files_recovered = 0;
    while (files_recovered < MAX_FILES) {
        for (int i = 0; i < num_players; i++) {
            printf("\n--- %s's Turn ---\n", players[i].name);
            printf("Available files to recover:\n");

            for (int j = 0; j < MAX_FILES; j++) {
                if (!files[j].recovered) {
                    printf(" - %s: %s\n", files[j].filename, files[j].hint);
                }
            }

            char action[20];
            printf("Choose 'recover' or 'hint': ");
            scanf("%s", action);

            if (strcmp(action, "recover") == 0) {
                char recovering_file[FILE_NAME_LENGTH];
                printf("Enter the filename to recover: ");
                scanf("%s", recovering_file);

                int found = 0;
                for (int j = 0; j < MAX_FILES; j++) {
                    if (strcmp(files[j].filename, recovering_file) == 0 && !files[j].recovered) {
                        files[j].recovered = 1;
                        players[i].score += 10; // Give points for recovery
                        found = 1;
                        files_recovered++;
                        printf("Congratulations! %s has recovered %s.\n", players[i].name, files[j].filename);
                        break;
                    }
                }

                if (!found) {
                    printf("File not found or already recovered!\n");
                }
            } else if (strcmp(action, "hint") == 0) {
                printf("Available hints:\n");
                for (int j = 0; j < MAX_FILES; j++) {
                    if (!files[j].recovered) {
                        printf(" - %s: %s\n", files[j].filename, files[j].hint);
                    }
                }
            } else {
                printf("Invalid action!\n");
            }

            displayScores(players, num_players);
        }
    }

    printf("=== Game Over! Final Scores ===\n");
    displayScores(players, num_players);
    printf("Thanks for playing!\n");

    return 0;
}