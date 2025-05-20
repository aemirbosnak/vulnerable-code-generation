//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define NUMBER_OF_CARDS 10
#define MAX_ROUNDS 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int points;
    int card;
} Player;

void initializeDeck(int deck[NUMBER_OF_CARDS]) {
    for (int i = 0; i < NUMBER_OF_CARDS; i++) {
        deck[i] = i + 1; // Cards numbered from 1 to 10
    }
}

void shuffleDeck(int deck[NUMBER_OF_CARDS]) {
    for (int i = 0; i < NUMBER_OF_CARDS; i++) {
        int j = rand() % NUMBER_OF_CARDS;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void drawCards(Player *player, int deck[NUMBER_OF_CARDS]) {
    player->card = deck[rand() % NUMBER_OF_CARDS];
}

void getPlayerDetails(Player *player) {
    printf("Enter your name: ");
    fgets(player->name, MAX_NAME_LENGTH, stdin);
    player->name[strcspn(player->name, "\n")] = 0; // Remove newline
    player->points = 0;
}

void makeGuess(Player *guesser, Player *opponent) {
    int guess;
    printf("%s, make your guess about %s's card (1-10): ", guesser->name, opponent->name);
    scanf("%d", &guess);
    if (guesser->card == guess) {
        printf("You guessed right, %s! You get a point!\n", guesser->name);
        guesser->points++;
    } else {
        printf("Wrong guess, %s! Your paranoia got the better of you...\n", guesser->name);
    }
}

void displayScores(Player players[], int numPlayers) {
    printf("\nScores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d points\n", players[i].name, players[i].points);
    }
}

int main() {
    srand(time(NULL));
    
    Player players[2];
    int deck[NUMBER_OF_CARDS];
    
    initializeDeck(deck);
    shuffleDeck(deck);
    
    // Get player details
    for (int i = 0; i < 2; i++) {
        getPlayerDetails(&players[i]);
        drawCards(&players[i], deck);
    }
    
    // Game play for a number of rounds
    for (int round = 1; round <= MAX_ROUNDS; round++) {
        printf("\n--- Round %d ---\n", round);
        for (int i = 0; i < 2; i++) {
            int opponentIndex = (i + 1) % 2; // Get the opponent's index
            makeGuess(&players[i], &players[opponentIndex]);
        }
        
        displayScores(players, 2);
    }

    // Determine and display the winner
    if (players[0].points > players[1].points) {
        printf("\nWinner: %s!\n", players[0].name);
    } else if (players[0].points < players[1].points) {
        printf("\nWinner: %s!\n", players[1].name);
    } else {
        printf("\nIt's a tie!\n");
    }

    return 0;
}