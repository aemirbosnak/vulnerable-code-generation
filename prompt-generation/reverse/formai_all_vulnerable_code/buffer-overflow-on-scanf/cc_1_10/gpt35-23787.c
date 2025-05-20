//FormAI DATASET v1.0 Category: Memory Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

void shuffle(int arr[], int size);
void printBoard(int arr1[], int size1, int arr2[], int size2);
int reveal(int arr1[], int size1, int arr2[], int size2, int index);
int checkMatch(int arr[], int size, int index1, int index2);

int main()
{
    int gameBoard[MAX_SIZE * 2];
    int size = MAX_SIZE * 2;
    int playerBoard[MAX_SIZE * 2];
    int playerScore = 0;
    int attempts = 0;
    int i;

    // Fill gameBoard with random numbers from 0 to 9
    srand(time(0));
    for (i = 0; i < size; i++)
    {
        gameBoard[i] = rand() % 10;
    }

    // Shuffle gameBoard
    shuffle(gameBoard, size);

    // Fill playerBoard with -1 to represent unrevealed cards
    for (i = 0; i < size; i++)
    {
        playerBoard[i] = -1;
    }

    // Main game loop
    while (playerScore < MAX_SIZE)
    {
        printBoard(playerBoard, size, gameBoard, size);

        int index1, index2;

        // Get player's choices
        printf("Enter two indices to reveal (0 - %d): ", size - 1);
        scanf("%d %d", &index1, &index2);

        // Check if chosen indices are valid and unrevealed
        if ((index1 < 0 || index1 >= size || index2 < 0 || index2 >= size) ||
            (playerBoard[index1] != -1 || playerBoard[index2] != -1))
        {
            printf("Invalid input! Try again.\n");
            continue;
        }

        // Reveal the chosen indices and check for a match
        int match = checkMatch(gameBoard, size, index1, index2);
        printf("Revealed: %d %d\n", gameBoard[index1], gameBoard[index2]);
        playerBoard[index1] = gameBoard[index1];
        playerBoard[index2] = gameBoard[index2];

        // If there was a match, increment playerScore
        if (match)
        {
            playerScore++;
            printf("Match found!\n");
        }
        else
        {
            printf("No match.\n");
        }

        attempts++;
    }

    printf("You won in %d attempts!\n", attempts);

    return 0;
}

// Shuffles an array using Fisher-Yates algorithm
void shuffle(int arr[], int size)
{
    int i;
    for (i = size - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Prints the game board (playerBoard) and hides unrevealed cards
void printBoard(int arr1[], int size1, int arr2[], int size2)
{
    printf("Game Board:\n");
    int i;
    for (i = 0; i < size1; i++)
    {
        if (arr1[i] == -1)
        {
            printf("? ");
        }
        else
        {
            printf("%d ", arr1[i]);
        }
    }
    printf("\n");
}

// Reveals a card on the game board and returns its value
int reveal(int arr1[], int size1, int arr2[], int size2, int index)
{
    arr1[index] = arr2[index];
    return arr2[index];
}

// Checks if two indices on the game board (arr) contain the same value
int checkMatch(int arr[], int size, int index1, int index2)
{
    return arr[index1] == arr[index2];
}