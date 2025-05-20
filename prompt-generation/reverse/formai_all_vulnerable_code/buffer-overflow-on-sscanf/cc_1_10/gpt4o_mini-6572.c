//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BINGO_SIZE 5
#define MAX_PLAYERS 10
#define MAX_NUM 75

typedef struct {
    int card[BINGO_SIZE][BINGO_SIZE];
    int marked[BINGO_SIZE][BINGO_SIZE];
    char playerName[50];
} Player;

void initialize_card(Player *player) {
    int cols = 0;
    int numbers[MAX_NUM] = {0};
    srand(time(NULL));

    for (int col = 0; col < BINGO_SIZE; col++) {
        for (int row = 0; row < BINGO_SIZE; row++) {
            int number;
            if (col == 0) {
                number = rand() % 15 + 1; // B = 1-15
            } else if (col == 1) {
                number = rand() % 15 + 16; // I = 16-30
            } else if (col == 2) {
                number = rand() % 15 + 31; // N = 31-45, center free space
                if (row == 2) { number = 0; } // free space
            } else if (col == 3) {
                number = rand() % 15 + 46; // G = 46-60
            } else if (col == 4) {
                number = rand() % 15 + 61; // O = 61-75
            }

            if (col == 2 && row == 2) {
                player->card[row][col] = 0; // Center free space
                player->marked[row][col] = 1; // Mark it as marked
            } else {
                while (numbers[number - 1] == 1) { // Ensure unique numbers
                    number = (col == 0) ? (rand() % 15 + 1) :
                             (col == 1) ? (rand() % 15 + 16) :
                             (col == 2) ? (rand() % 15 + 31) :
                             (col == 3) ? (rand() % 15 + 46) :
                                          (rand() % 15 + 61);
                }
                numbers[number - 1] = 1; // Mark number as used
                player->card[row][col] = number;
                player->marked[row][col] = 0; // Not marked
            }
        }
    }
}

void print_card(Player *player) {
    printf("Bingo Card for %s:\n", player->playerName);
    printf(" B   I   N   G   O\n");
    for (int row = 0; row < BINGO_SIZE; row++) {
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (player->marked[row][col]) {
                printf("[%2d] ", player->card[row][col]);
            } else {
                printf(" %2d  ", player->card[row][col]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int mark_number(Player *player, int number) {
    for (int row = 0; row < BINGO_SIZE; row++) {
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (player->card[row][col] == number) {
                player->marked[row][col] = 1; // Mark as found
                return 1;
            }
        }
    }
    return 0; // Number not found
}

int check_bingo(Player *player) {
    // Check Rows
    for (int row = 0; row < BINGO_SIZE; row++) {
        int bingo = 1;
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (!player->marked[row][col]) {
                bingo = 0;
                break;
            }
        }
        if (bingo) return 1;
    }
    
    // Check Columns
    for (int col = 0; col < BINGO_SIZE; col++) {
        int bingo = 1;
        for (int row = 0; row < BINGO_SIZE; row++) {
            if (!player->marked[row][col]) {
                bingo = 0;
                break;
            }
        }
        if (bingo) return 1;
    }
    
    // Check Diagonals
    int bingoA = 1, bingoB = 1;
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (!player->marked[i][i]) bingoA = 0; // Top-left to bottom-right
        if (!player->marked[i][BINGO_SIZE - i - 1]) bingoB = 0; // Top-right to bottom-left
    }
    
    return bingoA || bingoB;
}

int main() {
    Player players[MAX_PLAYERS];
    int playerCount = 0;
    char input[50];

    printf("Welcome to Bingo Simulator!\n");
    printf("Enter number of players (up to %d): ", MAX_PLAYERS);
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &playerCount);

    if (playerCount > MAX_PLAYERS || playerCount < 1) {
        printf("Invalid number of players!\n");
        return 1;
    }

    // Initialize Players and their Cards
    for (int i = 0; i < playerCount; i++) {
        printf("Enter name for Player %d: ", i + 1);
        fgets(players[i].playerName, sizeof(players[i].playerName), stdin);
        players[i].playerName[strcspn(players[i].playerName, "\n")] = 0; // Remove newline
        initialize_card(&players[i]);
        print_card(&players[i]);
    }

    // Start the Bingo game
    int number;
    while (1) {
        printf("Enter a number called (1-75, 0 to quit): ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d", &number);
        
        if (number == 0) break;
        if (number < 1 || number > 75) {
            printf("Invalid input. Enter numbers between 1 and 75.\n");
            continue;
        }

        printf("Called number: %d\n", number);
        for (int i = 0; i < playerCount; i++) {
            if (mark_number(&players[i], number)) {
                printf("%s marked %d!\n", players[i].playerName, number);
                if (check_bingo(&players[i])) {
                    printf("%s shouts BINGO!\n", players[i].playerName);
                    return 0; // End game on Bingo
                }
            }
        }
    }

    printf("Thanks for playing!\n");
    return 0;
}