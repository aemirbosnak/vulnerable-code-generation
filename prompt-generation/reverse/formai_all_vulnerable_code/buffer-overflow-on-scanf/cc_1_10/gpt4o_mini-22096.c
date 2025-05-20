//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define BOARD_SIZE 10
#define WINNING_SCORE 25

typedef struct {
    char name[50];
    int position;
    int score;
} Player;

void initializePlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].position = 0;
        players[i].score = 0;
    }
}

void displayBoard(Player players[], int numPlayers) {
    printf("\nCurrent Board:\n");
    for (int pos = 0; pos < BOARD_SIZE; pos++) {
        printf("| ");
        for (int i = 0; i < numPlayers; i++) {
            if (players[i].position == pos) {
                printf("%s ", players[i].name);
            }
        }
        printf(" |\n");
    }
    printf("\n");
}

int rollDice() {
    return rand() % 6 + 1; // Returns a number between 1 and 6
}

void updatePlayerPosition(Player *player) {
    int roll = rollDice();
    printf("%s rolled a %d\n", player->name, roll);
    player->position += roll;

    if (player->position >= BOARD_SIZE) {
        player->position = BOARD_SIZE - 1; // Keep within bounds
        player->score += 1; // Increment score for reaching the end
        printf("%s has reached the end and scores a point!\n", player->name);
    }
}

int checkWinningCondition(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        if (players[i].score >= WINNING_SCORE) {
            printf("\nCongratulations, %s wins the game with %d points!\n", players[i].name, players[i].score);
            return 1; // Game over
        }
    }
    return 0; // Continue the game
}

void playGame(Player players[], int numPlayers) {
    int gameWon = 0;
    int turn = 0;

    while (!gameWon) {
        Player *currentPlayer = &players[turn % numPlayers];
        printf("\nIt's %s's turn:\n", currentPlayer->name);
        updatePlayerPosition(currentPlayer);
        displayBoard(players, numPlayers);
        
        gameWon = checkWinningCondition(players, numPlayers);
        turn++;
    }
}

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    int numPlayers;

    printf("Welcome to the Mind-Bending Adventure Board Game!\n");
    do {
        printf("Enter the number of players (2 to %d): ", MAX_PLAYERS);
        scanf("%d", &numPlayers);
    } while (numPlayers < 2 || numPlayers > MAX_PLAYERS);

    initializePlayers(players, numPlayers);
    playGame(players, numPlayers);
    
    return 0;
}