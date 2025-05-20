//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_PLAYERS 5
#define BINGO_SIZE 5
#define MAX_NUMBER 75

typedef struct {
    int card[BINGO_SIZE][BINGO_SIZE];
    bool marked[BINGO_SIZE][BINGO_SIZE];
} BingoCard;

typedef struct {
    char name[50];
    BingoCard card;
} Player;

void initializeCard(BingoCard* card) {
    int nums[MAX_NUMBER + 1] = {0};
    srand(time(NULL));

    for (int j = 0; j < BINGO_SIZE; j++) {
        int count = 0;
        for (int i = 0; i < BINGO_SIZE; i++) {
            int num;
            do {
                num = (rand() % (15 * BINGO_SIZE)) + (j * 15) + 1; // Bingo columns spaced by 15
            } while (nums[num] || (i == BINGO_SIZE / 2 && j == BINGO_SIZE / 2)); // Prevent duplicates
            if (j == 2 && i == 2) { // Free space in the center
                card->card[i][j] = 0; 
                card->marked[i][j] = true; 
            } else {
                nums[num] = 1;
                card->card[i][j] = num;
                card->marked[i][j] = false;
            }
        }
    }
}

void printCard(const BingoCard* card) {
    printf("B I N G O\n");
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card->marked[i][j]) {
                printf("[X]\t");
            } else {
                printf("%d\t", card->card[i][j]);
            }
        }
        printf("\n");
    }
}

bool checkBingo(const BingoCard* card) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (card->marked[i][0] && card->marked[i][1] && card->marked[i][2] && card->marked[i][3] && card->marked[i][4]) {
            return true; // Check rows
        }
        if (card->marked[0][i] && card->marked[1][i] && card->marked[2][i] && card->marked[3][i] && card->marked[4][i]) {
            return true; // Check columns
        }
    }

    if (card->marked[0][0] && card->marked[1][1] && card->marked[2][2] && card->marked[3][3] && card->marked[4][4]) {
        return true; // Check diagonal
    }
    if (card->marked[0][4] && card->marked[1][3] && card->marked[2][2] && card->marked[3][1] && card->marked[4][0]) {
        return true; // Check reverse diagonal
    }

    return false;
}

void markNumber(BingoCard* card, int number) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card->card[i][j] == number) {
                card->marked[i][j] = true;
            }
        }
    }
}

void initializePlayers(Player players[], int numberOfPlayers) {
    for (int i = 0; i < numberOfPlayers; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
        initializeCard(&players[i].card);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int numberOfPlayers;

    printf("Enter number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &numberOfPlayers);
    if (numberOfPlayers < 1 || numberOfPlayers > MAX_PLAYERS) {
        printf("Invalid number of players!\n");
        return 1;
    }

    initializePlayers(players, numberOfPlayers);
    int calledNumbers[MAX_NUMBER + 1] = {0};
    bool winnerFound = false;

    printf("Bingo numbers being called!\n");
    while (!winnerFound) {
        int number = (rand() % MAX_NUMBER) + 1;
        while (calledNumbers[number]) {
            number = (rand() % MAX_NUMBER) + 1; // Find a number that's not called
        }
        calledNumbers[number] = 1;
        
        printf("Number called: %d\n", number);
        
        for (int i = 0; i < numberOfPlayers; i++) {
            markNumber(&players[i].card, number);
            if (checkBingo(&players[i].card)) {
                printf("Bingo! %s wins!\n", players[i].name);
                winnerFound = true;
                break;
            }
        }

        for (int i = 0; i < numberOfPlayers; i++) {
            printf("%s's card:\n", players[i].name);
            printCard(&players[i].card);
        }
        printf("\n");
    }

    return 0;
}