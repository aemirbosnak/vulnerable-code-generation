//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define NUM_PLAYERS 2

typedef struct {
    int position;
    char name[20];
} Player;

void initializePlayers(Player players[], int numPlayers);
void displayBoard(Player players[], int numPlayers);
void rollDice(Player *player);
void movePlayer(Player *player);
void challenge(Player *player);
void playGame(Player players[], int numPlayers);

int main() {
    srand(time(NULL)); // Seed the random number generator
    Player players[NUM_PLAYERS];

    initializePlayers(players, NUM_PLAYERS);
    playGame(players, NUM_PLAYERS);

    return 0;
}

// Function to initialize the players
void initializePlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].position = 0; // Starting position
    }
}

// Function to display the game board
void displayBoard(Player players[], int numPlayers) {
    printf("\nGame Board:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        int playerAtPosition = -1;
        for (int j = 0; j < numPlayers; j++) {
            if (players[j].position == i) {
                playerAtPosition = j;
                break;
            }
        }
        if (playerAtPosition >= 0) {
            printf("[ %s ] ", players[playerAtPosition].name);
        } else {
            printf("[   ] ");
        }
    }
    printf("\n");
}

// Function to roll the dice and get a random number between 1 and 6
void rollDice(Player *player) {
    int roll = (rand() % 6) + 1;
    printf("%s rolled a %d.\n", player->name, roll);
    player->position += roll;
    if (player->position >= BOARD_SIZE) {
        player->position = BOARD_SIZE - 1; // Max position
    }
}

// Function to move the player (roll dice and update position)
void movePlayer(Player *player) {
    rollDice(player);
}

// Function to handle the challenge based on the player's position
void challenge(Player *player) {
    if (player->position == 9) {
        printf("%s landed on a challenge space! Complete a math problem!\n", player->name);
        int answer = 0;
        printf("What is 7 + 5? ");
        scanf("%d", &answer);
        if (answer == 12) {
            printf("Correct! You stay on the same spot.\n");
        } else {
            printf("Incorrect! Move back 2 spaces.\n");
            player->position -= 2;
            if (player->position < 0) {
                player->position = 0;
            }
        }
    }
}

// Function to play the game
void playGame(Player players[], int numPlayers) {
    int turn = 0;
    while (1) {
        displayBoard(players, numPlayers);
        Player *currentPlayer = &players[turn % numPlayers];
        printf("\nIt's %s's turn.\n", currentPlayer->name);
        
        movePlayer(currentPlayer);
        challenge(currentPlayer);

        // Check for the winner
        if (currentPlayer->position >= BOARD_SIZE - 1) {
            printf("%s wins the game!\n", currentPlayer->name);
            break;
        }

        turn++;
    }
}