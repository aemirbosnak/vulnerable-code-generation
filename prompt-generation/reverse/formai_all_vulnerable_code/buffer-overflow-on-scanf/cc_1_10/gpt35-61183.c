//FormAI DATASET v1.0 Category: Memory Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getMenuChoice();                              // Function prototypes
void generateBoard(int arr[], int size);
void printBoard(int arr[], int size);
void gamePlay(int arr[], int size, int maxTurns);
void swap(int *x, int *y);

int main()
{
    int menuChoice, boardSize, maxTurns;

    srand(time(NULL));                            // Seed the random number generator with the current time

    do {                                          // Loop through the game menu until the user chooses to quit
        menuChoice = getMenuChoice();              // Get the user's menu choice

        if (menuChoice == 1) {                     // If the user chooses to play the game
            printf("\nEnter the size of the board (must be even and between 2 and 10): ");
            scanf("%d", &boardSize);                // Get the size of the board from the user

            int board[boardSize];                  // Declare the board array

            generateBoard(board, boardSize);       // Set up the board

            printf("\nEnter the maximum number of turns allowed: ");
            scanf("%d", &maxTurns);                 // Get the maximum number of turns from the user

            gamePlay(board, boardSize, maxTurns);   // Start the game
        }
    } while (menuChoice != 2);                      // Exit the loop if the user chooses to quit

    return 0;
}

int getMenuChoice()
{
    int choice;

    printf("\n\nWelcome to the Memory Game!\n");
    printf("1. Play the game\n");
    printf("2. Quit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);                      // Get the user's menu choice
    } while (choice < 1 || choice > 2);             // Loop until the user enters a valid choice

    return choice;
}

void generateBoard(int arr[], int size)
{
    int i, j, temp;

    for (i = 0; i < size; i++) {                  // Initialize the board array with unique values
        arr[i] = i / 2;
    }

    for (i = size - 1; i > 0; i--) {              // Shuffle the board by swapping random pairs of elements
        j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

void printBoard(int arr[], int size)
{
    int i;

    printf("\n");

    for (i = 0; i < size; i++) {                  // Print the contents of the board array
        if (i % 5 == 0 && i != 0) {
            printf("\n");
        }
        printf("%d\t", arr[i]);
    }

    printf("\n\n");
}

void gamePlay(int arr[], int size, int maxTurns)
{
    int i, turn = 0, card1, card2, matchCount = 0;
    int cardIndices[size], cardState[size];

    for (i = 0; i < size; i++) {                  // Initialize the cardIndices and cardState arrays
        cardIndices[i] = i;
        cardState[i] = 0;                        // 0 indicates the card is face down, 1 indicates it is face up
    }

    printBoard(cardIndices, size);                // Print the initial board (all cards face down)

    while (turn < maxTurns && matchCount < size / 2) {      // Loop through turns until the game is won or the maximum number of turns is reached
        printf("\nTurn %d\n", turn + 1);

        printf("Enter the index of the first card (1-%d): ", size);
        scanf("%d", &card1);                                 // Get the first card the user wants to flip

        printf("Enter the index of the second card (1-%d): ", size);
        scanf("%d", &card2);                                 // Get the second card the user wants to flip

        card1--;                                              // Translate from 1-based indexing to 0-based indexing
        card2--;

        if (cardState[card1] == 1 || cardState[card2] == 1) {  // Make sure both cards are face down
            printf("\nBoth cards must be face down!\n");
        }
        else if (arr[card1] == arr[card2]) {                  // If the cards match, update matchCount and cardState array
            printf("\nMatch found!\n");
            matchCount++;
            cardState[card1] = 1;
            cardState[card2] = 1;
        }
        else {                                                // If the cards don't match, print the board and increment the turn counter
            turn++;
            printf("\nSorry, no match found.\n");
        }

        for (i = 0; i < size; i++) {                          // Update the cardIndices array based on the current state of the game board
            if (cardState[i] == 0) {
                cardIndices[i] = i + 1;
            }
            else {
                cardIndices[i] = arr[i] + 11;
            }
        }

        printBoard(cardIndices, size);                        // Print the current board
    }

    if (matchCount == size / 2) {                             // If the game was won, print a congratulatory message
        printf("\nCongratulations, you won in %d turns!\n", turn);
    }
    else {                                                    // If the maximum number of turns was reached, print a game over message
        printf("\nGame over, you ran out of turns!\n");
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}