//FormAI DATASET v1.0 Category: Memory Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the game board
void printBoard(int gameBoard[]) {
    printf("\n");
    for(int i = 0; i < 10; i++) {
        printf("%d ", gameBoard[i]);    
    } 
}

int main() {
    // Initializing variables
    int gameOver = 0, num1, num2, count = 0;
    int gameBoard[10] = {0,0,0,0,0,0,0,0,0,0};
    srand(time(0)); // Seed for generating random number
    printf("Memory Game!\n\n");
    
    // Generating two random numbers
    num1 = rand()%5 + 1;
    num2 = rand()%5 + 1;

    // Placing the numbers on the game board
    gameBoard[num1] = 1;
    gameBoard[num2] = 1;
    printBoard(gameBoard);

    // Game loop
    while(!gameOver) {
        int guess1, guess2;
        
        // Asking user to input the first guess
        printf("\nEnter your first guess: ");
        scanf("%d", &guess1);
        
        // If guess is out of range
        if(guess1 < 0 || guess1 > 9) {
            printf("\nInvalid input! Enter any number from 0-9.");
            continue; // continue with the loop
        }
        
        // If guess is already matched or incorrect
        if(gameBoard[guess1] == -1 || gameBoard[guess1] == 2) {
            printf("\nThis number has been already matched or incorrect. Try again!");
            continue; // continue with the loop
        }
        
        // Updating the game board with the first guess
        if(gameBoard[guess1] == 1) {
            gameBoard[guess1] = -1; // -1 indicates a match
            printBoard(gameBoard);
            count++;
            if(count == 2) { // If both numbers are matched
                printf("\nYou have successfully matched both the numbers!");
                gameOver = 1;
                break; // Exit the game loop
            }
        } else { // If guess is incorrect
            printf("\nSorry! This was an incorrect guess.");
            gameBoard[guess1] = 2; // 2 indicates an incorrect guess
            printBoard(gameBoard);
        }
        
        // Asking user to input the second guess
        printf("\nEnter your second guess: ");
        scanf("%d", &guess2);
        
        // If guess is out of range
        if(guess2 < 0 || guess2 > 9) {
            printf("\nInvalid input! Enter any number from 0-9.");
            continue; // continue with the loop
        }
        
        // If guess is already matched or incorrect
        if(gameBoard[guess2] == -1 || gameBoard[guess2] == 2) {
            printf("\nThis number has been already matched or incorrect. Try again!");
            continue; // continue with the loop
        }
        
        // Updating the game board with the second guess
        if(gameBoard[guess2] == 1) {
            gameBoard[guess2] = -1; // -1 indicates a match
            printBoard(gameBoard);
            count++;
            if(count == 2) { // If both numbers are matched
                printf("\nYou have successfully matched both the numbers!");
                gameOver = 1;
                break; // Exit the game loop
            }
        } else { // If guess is incorrect
            printf("\nSorry! This was an incorrect guess.");
            gameBoard[guess2] = 2; // 2 indicates an incorrect guess
            printBoard(gameBoard);
        }
    }

    return 0;
}