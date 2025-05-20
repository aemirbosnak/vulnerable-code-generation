//Falcon-180B DATASET v1.0 Category: Table Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle an array
void shuffleArray(int arr[], int n) {
    int i, j, temp;
    srand(time(NULL));
    for (i = 0; i < n - 1; i++) {
        j = rand() % (n - i) + i;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to play the game
void playGame(int arr[], int n) {
    int i, j, k, player, computer, choice;
    printf("Enter your choice (1 for rock, 2 for paper, 3 for scissors): ");
    scanf("%d", &player);
    shuffleArray(arr, n);
    printf("Computer's choice: ");
    for (i = 0; i < n; i++) {
        if (arr[i] == 1) {
            printf("rock\n");
            break;
        } else if (arr[i] == 2) {
            printf("paper\n");
            break;
        } else if (arr[i] == 3) {
            printf("scissors\n");
            break;
        }
    }
    if (player == arr[rand() % n]) {
        printf("It's a tie!\n");
    } else if ((player == 1 && arr[rand() % n] == 3) ||
               (player == 2 && arr[rand() % n] == 1) ||
               (player == 3 && arr[rand() % n] == 2)) {
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int choice;

    while (1) {
        printf("1. Play game\n2. Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            playGame(arr, n);
        } else if (choice == 2) {
            exit(0);
        }
    }

    return 0;
}