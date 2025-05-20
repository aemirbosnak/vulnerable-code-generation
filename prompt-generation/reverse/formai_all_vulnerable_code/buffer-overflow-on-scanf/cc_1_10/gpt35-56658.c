//FormAI DATASET v1.0 Category: QR code generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GRID_SIZE 20
#define MAX_NUM_PLAYERS 4
#define MAX_RAND_NUM 100

// Struct to represent a player
typedef struct {
    int id;
    char name[50];
    int score;
} Player;

// Function to generate a random number
int generateRandomNum() {
    srand(time(NULL));
    int num = rand() % MAX_RAND_NUM + 1;
    return num;
}

// Function to create a QR code grid
void createQRCodeGrid(int grid[MAX_GRID_SIZE][MAX_GRID_SIZE], int gridSize) {
    for(int i=0; i<gridSize; i++) {
        for(int j=0; j<gridSize; j++) {
            grid[i][j] = generateRandomNum();
        }
    }
}

// Function to display QR code grid
void displayQRCodeGrid(int grid[MAX_GRID_SIZE][MAX_GRID_SIZE], int gridSize) {
    printf("\nQR CODE GRID:\n\n");
    for(int i=0; i<gridSize; i++) {
        for(int j=0; j<gridSize; j++) {
            printf("%d\t", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to create a new player
Player createPlayer(int playerId) {
    Player player;
    player.id = playerId;
    printf("Enter name for Player %d: ", playerId + 1);
    scanf("%s", player.name);
    player.score = 0;
    printf("Player %d created!\n\n", playerId + 1);
    return player;
}

// Function to display player details
void displayPlayerDetails(Player* players, int numPlayers) {
    printf("\nPLAYER DETAILS:\n\n");
    for(int i=0; i<numPlayers; i++) {
        printf("Player %d Name: %s\n", players[i].id + 1, players[i].name);
        printf("Player %d Score: %d\n\n", players[i].id + 1, players[i].score);
    }
}

// Function to get player move
void getPlayerMove(Player* player, int grid[MAX_GRID_SIZE][MAX_GRID_SIZE], int gridSize) {
    int row, col;
    printf("%s, enter row and column coordinates to select a number: ", player->name);
    scanf("%d %d", &row, &col);
    if(row >= 1 && row <= gridSize && col >= 1 && col <= gridSize) {
        int selectedNum = grid[row-1][col-1];
        printf("\nSelected number: %d\n", selectedNum);
        player->score += selectedNum;
    }
    else {
        printf("Invalid coordinates entered, try again.\n\n");
        getPlayerMove(player, grid, gridSize);
    }
}

int main() {
    int gridSize, numPlayers;

    // Get grid size from user
    printf("Enter QR code grid size (max %d): ", MAX_GRID_SIZE);
    scanf("%d", &gridSize);
    if(gridSize < 1 || gridSize > MAX_GRID_SIZE) {
        printf("Invalid grid size entered, must be between 1 and %d, exiting program.\n", MAX_GRID_SIZE);
        return 0;
    }

    // Get number of players from user
    printf("Enter number of players (max %d): ", MAX_NUM_PLAYERS);
    scanf("%d", &numPlayers);
    if(numPlayers < 1 || numPlayers > MAX_NUM_PLAYERS) {
        printf("Invalid number of players entered, must be between 1 and %d, exiting program.\n", MAX_NUM_PLAYERS);
        return 0;
    }

    // Create QR code grid
    int qrCodeGrid[MAX_GRID_SIZE][MAX_GRID_SIZE];
    createQRCodeGrid(qrCodeGrid, gridSize);

    // Display QR code grid
    displayQRCodeGrid(qrCodeGrid, gridSize);

    // Create players
    Player players[numPlayers];
    for(int i=0; i<numPlayers; i++) {
        players[i] = createPlayer(i);
    }

    // Start game
    int roundNum = 1;
    while(roundNum <= gridSize) {
        printf("ROUND %d:\n\n", roundNum);

        // Get moves for each player
        for(int i=0; i<numPlayers; i++) {
            getPlayerMove(&players[i], qrCodeGrid, gridSize);
        }

        // Display player details
        displayPlayerDetails(players, numPlayers);

        roundNum++;
    }

    // Determine winner
    int highestScore = 0;
    int winnerIndex = 0;
    for(int i=0; i<numPlayers; i++) {
        if(players[i].score > highestScore) {
            highestScore = players[i].score;
            winnerIndex = i;
        }
    }
    printf("WINNER: %s with a score of %d!\n\n", players[winnerIndex].name, highestScore);

    return 0;
}