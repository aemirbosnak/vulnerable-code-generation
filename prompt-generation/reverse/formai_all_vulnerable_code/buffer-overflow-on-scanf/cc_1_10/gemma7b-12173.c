//Gemma-7B DATASET v1.0 Category: Table Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Players 4

typedef struct Player {
    char name[20];
    int score;
    struct Player* next;
} Player;

void createPlayer(char* name) {
    Player* newPlayer = malloc(sizeof(Player));
    strcpy(newPlayer->name, name);
    newPlayer->score = 0;
    newPlayer->next = NULL;
}

void addPlayer(Player* head, char* name) {
    Player* newPlayer = malloc(sizeof(Player));
    strcpy(newPlayer->name, name);
    newPlayer->score = 0;
    newPlayer->next = NULL;

    if (head == NULL) {
        head = newPlayer;
    } else {
        head->next = newPlayer;
    }
}

void playGame() {
    Player* head = NULL;
    char name[20];

    printf("Enter the name of the first player: ");
    scanf("%s", name);
    createPlayer(name);
    addPlayer(head, name);

    for (int i = 1; i < MAX_Players; i++) {
        printf("Enter the name of the next player: ");
        scanf("%s", name);
        createPlayer(name);
        addPlayer(head, name);
    }

    // Game logic
    // ...
}

int main() {
    playGame();

    return 0;
}