//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int order[9] = {0};
    int correctOrder[9] = {0};
    int i, j;
    int num;
    int userInput;
    int count = 0;

    srand(time(NULL));

    for (i = 0; i < 9; i++) {
        correctOrder[i] = rand() % 9 + 1;
        order[i] = correctOrder[i];
    }

    printf("Enter the order of numbers you want to guess: ");
    for (i = 0; i < 9; i++) {
        scanf("%d", &order[i]);
    }

    printf("\n");

    while (count < 9) {
        printf("Enter your guess: ");
        scanf("%d", &num);

        for (i = 0; i < 9; i++) {
            if (num == correctOrder[i]) {
                order[count] = num;
                count++;
            }
        }

        if (count == 9) {
            printf("\nCongratulations! You guessed the correct order of numbers.\n");
            for (i = 0; i < 9; i++) {
                printf("%d ", order[i]);
            }
            printf("\n");
            break;
        }

        printf("\nSorry, your guess is incorrect. Try again.\n");
    }

    if (count == 0) {
        printf("\nYou gave up. Better luck next time!\n");
    }

    return 0;
}