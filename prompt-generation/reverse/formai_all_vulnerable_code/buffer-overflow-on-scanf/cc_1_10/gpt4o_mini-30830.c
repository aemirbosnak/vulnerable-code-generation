//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 5
#define MAX_NUMBERS 20

void sort(int arr[], int n);
void display(int arr[], int n);
void enterNumbers(int playerId, int numbers[], int *numCount);
void collectNumbers(int playerCount);

int main() {
    int playerCount;
    
    printf("Welcome to the Multiplayer Sorting Game!\n");
    printf("Enter the number of players (1 to %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);

    if (playerCount < 1 || playerCount > MAX_PLAYERS) {
        printf("Invalid number of players! Exiting...\n");
        return 1;
    }

    collectNumbers(playerCount);
    return 0;
}

void collectNumbers(int playerCount) {
    int numbers[MAX_PLAYERS][MAX_NUMBERS];
    int numCount[MAX_PLAYERS] = {0};
    char continueInput;

    for (int playerId = 0; playerId < playerCount; playerId++) {
        printf("\nPlayer %d, you can enter up to %d numbers (enter 'q' to finish early):\n", playerId + 1, MAX_NUMBERS);
        
        enterNumbers(playerId + 1, numbers[playerId], &numCount[playerId]);
        
        printf("Player %d has entered:\n", playerId + 1);
        display(numbers[playerId], numCount[playerId]);
    }

    int totalNumbers = 0;
    for (int i = 0; i < playerCount; i++) {
        totalNumbers += numCount[i];
    }

    // Combine all players' numbers into a single array
    int allNumbers[totalNumbers];
    int index = 0;
    for (int i = 0; i < playerCount; i++) {
        for (int j = 0; j < numCount[i]; j++) {
            allNumbers[index++] = numbers[i][j];
        }
    }

    // Sort combined numbers
    sort(allNumbers, totalNumbers);
    
    printf("\nAll players' numbers sorted:\n");
    display(allNumbers, totalNumbers);
}

void enterNumbers(int playerId, int numbers[], int *numCount) {
    char input[10];
    while (*numCount < MAX_NUMBERS) {
        printf("Enter number %d (or 'q' to finish): ", (*numCount) + 1);
        scanf("%s", input);
        
        if (input[0] == 'q') {
            break;
        }

        numbers[*numCount] = atoi(input);
        (*numCount)++;
    }
}

void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}