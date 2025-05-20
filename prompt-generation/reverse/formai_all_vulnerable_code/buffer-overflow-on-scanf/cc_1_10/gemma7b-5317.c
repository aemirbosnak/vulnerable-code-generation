//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 2

typedef struct Player {
    char name[20];
    int baggage_weight;
    int baggage_claim_number;
} Player;

void handle_baggage(Player *player) {
    printf("Player %s, please enter the weight of your baggage (in kilograms): ", player->name);
    scanf("%d", &player->baggage_weight);

    if (player->baggage_weight > 20) {
        printf("Error: Your baggage weight exceeds the limit of 20 kilograms.\n");
    } else {
        printf("Your baggage weight is %d kilograms.\n", player->baggage_weight);
    }
}

void assign_baggage_claim_number(Player *player) {
    player->baggage_claim_number = rand() % MAX_PLAYERS + 1;
    printf("Your baggage claim number is %d.\n", player->baggage_claim_number);
}

int main() {
    Player players[MAX_PLAYERS];

    // Initialize players
    for (int i = 0; i < MAX_PLAYERS; i++) {
        players[i].name[0] = '\0';
        players[i].baggage_weight = 0;
        players[i].baggage_claim_number = 0;
    }

    // Handle baggage for each player
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter your name: ");
        scanf("%s", players[i].name);
        handle_baggage(&players[i]);
        assign_baggage_claim_number(&players[i]);
    }

    // Print baggage information for all players
    printf("**Baggage Information:**\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Player: %s\n", players[i].name);
        printf("Baggage Weight: %d kilograms\n", players[i].baggage_weight);
        printf("Baggage Claim Number: %d\n", players[i].baggage_claim_number);
        printf("\n");
    }

    return 0;
}