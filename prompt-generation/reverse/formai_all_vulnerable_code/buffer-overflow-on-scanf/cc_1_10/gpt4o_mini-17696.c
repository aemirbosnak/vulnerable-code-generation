//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_PLAYERS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

typedef struct {
    Player* players;
    int count;
} PlayerList;

void initializePlayerList(PlayerList* list) {
    list->players = (Player*)malloc(sizeof(Player) * MAX_PLAYERS);
    if (list->players == NULL) {
        fprintf(stderr, "Failed to allocate memory for players.\n");
        exit(EXIT_FAILURE);
    }
    list->count = 0;
}

void addPlayer(PlayerList* list, const char* name, int score) {
    if (list->count >= MAX_PLAYERS) {
        fprintf(stderr, "Cannot add more players. Maximum limit reached.\n");
        return;
    }
    strncpy(list->players[list->count].name, name, MAX_NAME_LENGTH - 1);
    list->players[list->count].name[MAX_NAME_LENGTH - 1] = '\0';  // Ensure null termination
    list->players[list->count].score = score;
    list->count++;
}

void displayPlayers(const PlayerList* list) {
    printf("\n--- Player List ---\n");
    for (int i = 0; i < list->count; i++) {
        printf("Player %d: %s, Score: %d\n", i + 1, list->players[i].name, list->players[i].score);
    }
    printf("-------------------\n");
}

void freePlayerList(PlayerList* list) {
    free(list->players);
    list->players = NULL;  // Avoid dangling pointer
}

int main() {
    PlayerList playerList;
    initializePlayerList(&playerList);

    char buffer[MAX_NAME_LENGTH];
    int score;
    char choice;

    do {
        printf("Enter player name: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0;  // Remove newline character

        printf("Enter player score: ");
        scanf("%d", &score);
        while(getchar() != '\n'); // Clear the input buffer

        addPlayer(&playerList, buffer, score);

        printf("Add another player? (y/n): ");
        choice = getchar();
        while(getchar() != '\n'); // Clear the input buffer

    } while (choice == 'y' || choice == 'Y');

    displayPlayers(&playerList);
    freePlayerList(&playerList);

    return 0;
}