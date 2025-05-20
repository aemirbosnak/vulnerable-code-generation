//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_Players 4

typedef struct Player {
    char name[20];
    int score;
    struct Player* next;
} Player;

void JoinGame(Player** head) {
    Player* newPlayer = (Player*)malloc(sizeof(Player));
    printf("Enter your name: ");
    scanf("%s", newPlayer->name);
    newPlayer->score = 0;
    newPlayer->next = NULL;

    if (*head == NULL) {
        *head = newPlayer;
    } else {
        (*head)->next = newPlayer;
    }
}

void PrintScoreboard(Player* head) {
    printf("Scoreboard:\n");
    while (head) {
        printf("%s: %d\n", head->name, head->score);
        head = head->next;
    }
}

int main() {
    Player* head = NULL;
    int numPlayers = 0;

    printf("Welcome to the C Metadata Extractor!\n");
    printf("How many players want to join? (Maximum %d): ", MAX_Players);
    scanf("%d", &numPlayers);

    for (int i = 0; i < numPlayers; i++) {
        JoinGame(&head);
    }

    PrintScoreboard(head);

    return 0;
}