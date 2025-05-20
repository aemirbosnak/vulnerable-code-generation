//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_INPUT 256
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int translations;
} Player;

void addTranslation(Player players[], int *playerCount, const char *name);
void displayTranslations(const Player players[], int playerCount);
char* translateToCatLanguage(const char *input);
void displayLeaderboard(const Player players[], int playerCount);
int findPlayer(Player players[], int playerCount, const char *name);

int main() {
    Player players[MAX_PLAYERS];
    int playerCount = 0;
    char input[MAX_INPUT];
    char playerName[MAX_NAME_LENGTH];
    int choice;

    printf("Welcome to the Cat Language Translator Multiplayer Game!\n");

    while (1) {
        printf("\n1. Join Game\n2. Submit Translation\n3. View Leaderboard\n4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline character

        switch (choice) {
            case 1:
                printf("Enter your name: ");
                fgets(playerName, MAX_NAME_LENGTH, stdin);
                playerName[strcspn(playerName, "\n")] = 0; // Remove newline

                if (playerCount < MAX_PLAYERS && findPlayer(players, playerCount, playerName) == -1) {
                    strcpy(players[playerCount].name, playerName);
                    players[playerCount].translations = 0;
                    playerCount++;
                    printf("Welcome, %s! You have joined the game.\n", playerName);
                } else {
                    printf("Game full or name already taken. Please try another name.\n");
                }
                break;

            case 2:
                printf("Enter your name: ");
                fgets(playerName, MAX_NAME_LENGTH, stdin);
                playerName[strcspn(playerName, "\n")] = 0; // Remove newline

                int playerIndex = findPlayer(players, playerCount, playerName);
                if (playerIndex != -1) {
                    printf("Enter the phrase to translate: ");
                    fgets(input, MAX_INPUT, stdin);
                    input[strcspn(input, "\n")] = 0; // Remove newline
                    addTranslation(players, &playerCount, playerName);
                    char *translated = translateToCatLanguage(input);
                    printf("Translation to Cat Language: %s\n", translated);
                    free(translated);
                } else {
                    printf("Player not found. Please join the game first.\n");
                }
                break;

            case 3:
                displayLeaderboard(players, playerCount);
                break;

            case 4:
                printf("Thank you for playing! Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void addTranslation(Player players[], int *playerCount, const char *name) {
    int index = findPlayer(players, *playerCount, name);
    if (index != -1) {
        players[index].translations++;
    }
}

void displayLeaderboard(const Player players[], int playerCount) {
    printf("\nLeaderboard:\n");
    for (int i = 0; i < playerCount; i++) {
        printf("%s: %d translations\n", players[i].name, players[i].translations);
    }
}

char* translateToCatLanguage(const char *input) {
    char *translated = (char *)malloc(MAX_INPUT * sizeof(char));
    if (!translated) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (strchr("aeiouAEIOU", input[i])) {
            strcpy(&translated[j], "meow");
            j += 4;
        } else {
            translated[j++] = input[i];
        }
    }
    translated[j] = '\0';
    return translated;
}

int findPlayer(Player players[], int playerCount, const char *name) {
    for (int i = 0; i < playerCount; i++) {
        if (strcmp(players[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}