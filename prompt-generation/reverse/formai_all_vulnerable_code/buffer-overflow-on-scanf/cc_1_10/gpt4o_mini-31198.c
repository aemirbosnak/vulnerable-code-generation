//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_PLAYERS 5
#define BINGO_SIZE 25 // 5x5 Bingo

// Structure to represent each player
typedef struct {
    char name[50];
    bool card[BINGO_SIZE];
    int numbers[25];
} Player;

// Function Prototypes
void initializeCard(Player *player);
void printCard(Player *player);
void drawNumber(Player *player, int number);
bool checkBingo(Player *player);
void announceWinner(Player *player);

int main() {
    Player players[MAX_PLAYERS];
    int playerCount = 0;
    int drawnNumbers[75] = {0}; 

    printf("Enter the name of fair players (up to %d):\n", MAX_PLAYERS);

    while (playerCount < MAX_PLAYERS) {
        printf("Player %d: ", playerCount + 1);
        scanf("%s", players[playerCount].name);
        initializeCard(&players[playerCount]);
        playerCount++;

        if (playerCount >= MAX_PLAYERS) break;
        printf("Add another player? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'n') break;
    }

    srand((unsigned int) time(NULL));
    
    printf("\nThe game of Bingo begins! The fates do intertwine...\n");

    while (true) {
        int drawnNumber;
        do {
            drawnNumber = rand() % 75 + 1;
        } while (drawnNumbers[drawnNumber - 1] == 1);

        drawnNumbers[drawnNumber - 1] = 1;
        printf("Number drawn: %d\n", drawnNumber);

        for (int i = 0; i < playerCount; i++) {
            drawNumber(&players[i], drawnNumber);
            if (checkBingo(&players[i])) {
                announceWinner(&players[i]);
                return 0;
            }
        }
    }
}

void initializeCard(Player *player) {
    int numbers[75], index = 0;

    // Fill the array with numbers from 1 to 75
    for (int i = 1; i <= 75; i++) {
        numbers[index++] = i;
    }
    
    // Shuffle the numbers
    for (int i = 0; i < 75; i++) {
        int j = rand() % 75;
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp; 
    }

    // Assign first 25 shuffled numbers to player's card
    for (int i = 0; i < BINGO_SIZE; i++) {
        player->numbers[i] = numbers[i];
        player->card[i] = false; // Initially, no numbers are marked
    }

    printf("Welcome, noble %s! Thy Bingo card is prepared:\n", player->name);
    printCard(player);
}

void printCard(Player *player) {
    printf("B   I   N   G   O\n");
    for (int i = 0; i < 25; i++) {
        if (i % 5 == 0 && i != 0) {
            printf("\n");
        }
        printf("%2d ", player->numbers[i]);
    }
    printf("\n\n");
}

void drawNumber(Player *player, int number) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (player->numbers[i] == number) {
            player->card[i] = true;
            printf("%s hath marked the number %d!\n", player->name, number);
        }
    }
}

bool checkBingo(Player *player) {
    // Check rows and columns for Bingo
    for (int i = 0; i < 5; i++) {
        if ((player->card[i*5] && player->card[i*5 + 1] && player->card[i*5 + 2] && player->card[i*5 + 3] && player->card[i*5 + 4]) ||
            (player->card[i] && player->card[i + 5] && player->card[i + 10] && player->card[i + 15] && player->card[i + 20])) {
                return true;
        }
    }

    // Check diagonals.
    if ((player->card[0] && player->card[6] && player->card[12] && player->card[18] && player->card[24]) ||
        (player->card[4] && player->card[8] && player->card[12] && player->card[16] && player->card[20])) {
            return true;
    }
    
    return false;
}

void announceWinner(Player *player) {
    printf("Aha! %s has achieved Bingo! The stars align in their favor!\n", player->name);
}