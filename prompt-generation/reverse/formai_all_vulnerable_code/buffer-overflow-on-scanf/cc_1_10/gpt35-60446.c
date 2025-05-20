//FormAI DATASET v1.0 Category: Graph representation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

int graph[ROWS][COLS] = {{0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0,0}};

void displayGraph() {
    printf("\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(graph[i][j] == 0) {
                printf("| |");
            } else {
                printf("|X|");
            }
        }
        printf("\n");
    }
}

void generateGraph() {
    int numObstacles = rand() % 10 + 1;
    for(int i = 0; i < numObstacles; i++) {
        int randRow = rand() % ROWS;
        int randCol = rand() % COLS;
        if(graph[randRow][randCol] != 1) {
            graph[randRow][randCol] = 1;
        }
    }
}

void playGame() {
    int playerCol = 0;
    int playerRow = 0;
    int destinationCol = COLS - 1;
    int destinationRow = ROWS - 1;
    
    printf("\nYou are being chased by a group of post-apocalyptic raiders. You need to get to the other side of the city to escape them.\n");
    
    while(playerRow != destinationRow || playerCol != destinationCol) {
        printf("\nEnter a direction (w,a,s,d) to move: ");
        char input;
        scanf(" %c", &input);
        if(input == 'w' && playerRow != 0 && graph[playerRow - 1][playerCol] != 1) {
            playerRow--;
        } else if(input == 'a' && playerCol != 0 && graph[playerRow][playerCol - 1] != 1) {
            playerCol--;
        } else if(input == 's' && playerRow != ROWS - 1 && graph[playerRow + 1][playerCol] != 1) {
            playerRow++;
        } else if(input == 'd' && playerCol != COLS - 1 && graph[playerRow][playerCol + 1] != 1) {
            playerCol++;
        } else {
            printf("\nInvalid direction. Try again.\n");
        }
        
        system("clear");
        displayGraph();
        
        if(playerRow == destinationRow && playerCol == destinationCol) {
            printf("\nYou've made it to the other side of the city and managed to escape the raiders!\n");
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    
    generateGraph();
    displayGraph();
    
    playGame();
    
    return 0;
}