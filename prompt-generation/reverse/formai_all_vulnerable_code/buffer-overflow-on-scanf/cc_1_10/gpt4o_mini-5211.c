//GPT-4o-mini DATASET v1.0 Category: Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 5
#define MAX_ITEMS 3

char maze[SIZE][SIZE] = {
    {'S', ' ', ' ', '#', ' '},
    {'#', '#', ' ', '#', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', '#', '#', '#', ' '},
    {' ', ' ', ' ', 'E', ' '}
};

int playerX = 0, playerY = 0; // Starting position (S)
int items[MAX_ITEMS] = {0}; // Array to hold collected items

void printMaze() {
    system("clear"); // Clear the terminal for better visualization
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == playerX && j == playerY) {
                printf("P "); // Player position
            } else {
                printf("%c ", maze[i][j]);
            }
        }
        printf("\n");
    }
}

int isValidMove(int newX, int newY) {
    return (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE && maze[newX][newY] != '#');
}

void collectItem(int itemIndex) {
    items[itemIndex] = 1; // Mark item as collected
    printf("You've collected an item!\n");
}

int findExit() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i] == 0) {
            return 0; // Return 0 if there's still an item left
        }
    }
    return 1; // All items collected
}

void getInput() {
    char input;
    printf("Enter your move (W/A/S/D): ");
    scanf(" %c", &input);
    if (input == 'W' || input == 'w') {
        if (isValidMove(playerX - 1, playerY)) playerX--;
    } else if (input == 'A' || input == 'a') {
        if (isValidMove(playerX, playerY - 1)) playerY--;
    } else if (input == 'S' || input == 's') {
        if (isValidMove(playerX + 1, playerY)) playerX++;
    } else if (input == 'D' || input == 'd') {
        if (isValidMove(playerX, playerY + 1)) playerY++;
    }
}

void checkForItem() {
    if (maze[playerX][playerY] == ' ') {
        collectItem(0);
        maze[playerX][playerY] = ' '; // Empty the space after collecting
    }
}

int main() {
    printf("Welcome to the Maze Game!\n");
    printf("Your goal is to collect all items and find the exit!\n");
    
    while (1) {
        printMaze();
        getInput();
        
        checkForItem();
        
        if (playerX == 4 && playerY == 3 && findExit()) {
            printMaze();
            printf("Congratulations! You've collected all items and found the exit!\n");
            break;
        }
    }
    
    return 0;
}