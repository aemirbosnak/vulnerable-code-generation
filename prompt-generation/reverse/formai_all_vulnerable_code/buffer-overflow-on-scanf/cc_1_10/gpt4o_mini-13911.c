//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYERS 4
#define MAX_NUMBERS 100

void displayMenu();
void playerInput(int playerID, int numbers[], int *count);
void sortNumbers(int numbers[], int count);
void displayNumbers(int numbers[], int count);

int main() {
    int numbers[MAX_NUMBERS];
    int count = 0;
    int currentPlayer = 0;
    int players[MAX_PLAYERS] = {0};

    printf("Welcome to the Multiplayer Sorting Game!\n");
    displayMenu();

    while (currentPlayer < MAX_PLAYERS) {
        printf("\nPlayer %d, it's your turn!\n", currentPlayer + 1);
        playerInput(currentPlayer + 1, numbers, &count);
        players[currentPlayer] = count;
        currentPlayer++;
    }

    // All players have entered their numbers
    printf("\nAll players have entered their numbers!\n");
    sortNumbers(numbers, count);
    displayNumbers(numbers, count);

    return 0;
}

void displayMenu() {
    printf("Menu:\n");
    printf("1. Enter numbers for sorting\n");
    printf("2. See sorted results\n");
    printf("Note: Up to %d players can enter numbers.\n", MAX_PLAYERS);
}

void playerInput(int playerID, int numbers[], int *count) {
    int input;
    printf("Enter numbers (type -1 to end input for this player):\n");
    
    while (*count < MAX_NUMBERS) {
        printf("Player %d, enter a number: ", playerID);
        scanf("%d", &input);

        if (input == -1) {
            break;
        }
        
        numbers[(*count)++] = input;
    }
    printf("Player %d finished entering numbers.\n", playerID);
}

void sortNumbers(int numbers[], int count) {
    int temp, i, j;
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                // Swap numbers[j] and numbers[j + 1]
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    printf("Numbers have been sorted!\n");
}

void displayNumbers(int numbers[], int count) {
    printf("\nSorted Numbers:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}