//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    int chips;
} Player;

typedef struct {
    Player players[10];
    int numPlayers;
} Game;

int main() {
    Game game;
    game.numPlayers = 0;

    while (true) {
        char name[50];
        int chips;
        printf("Enter player name (or 0 to exit): ");
        scanf("%s %d", name, &chips);

        if (strcmp(name, "0") == 0) {
            break;
        }

        Player newPlayer;
        strcpy(newPlayer.name, name);
        newPlayer.chips = chips;

        if (game.numPlayers == 10) {
            printf("No more players can join.\n");
            continue;
        }

        game.players[game.numPlayers] = newPlayer;
        game.numPlayers++;

        printf("Player %s joined with %d chips.\n", newPlayer.name, newPlayer.chips);
    }

    int betAmount;
    int winner;
    int pot = 0;

    for (int i = 0; i < game.numPlayers; i++) {
        printf("Player %s's bet: ", game.players[i].name);
        scanf("%d", &betAmount);
        pot += betAmount;
    }

    if (pot == 0) {
        printf("No bets made.\n");
        return 0;
    }

    for (int i = 0; i < game.numPlayers; i++) {
        if (game.players[i].chips < pot) {
            printf("Player %s is all-in.\n", game.players[i].name);
        }
    }

    int highestBid = 0;
    int highestBidder;
    for (int i = 0; i < game.numPlayers; i++) {
        if (game.players[i].chips > highestBid) {
            highestBid = game.players[i].chips;
            highestBidder = i;
        }
    }

    printf("Player %s has the highest bid of %d.\n", game.players[highestBidder].name, highestBid);

    winner = -1;
    for (int i = 0; i < game.numPlayers; i++) {
        if (i == highestBidder) {
            printf("Player %s wins the pot of %d.\n", game.players[i].name, pot);
            winner = i;
        } else {
            printf("Player %s loses.\n", game.players[i].name);
        }
    }

    printf("Player %s is the winner.\n", game.players[winner].name);

    return 0;
}