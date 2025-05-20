//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_RANGE 1
#define MAX_RANGE 100

int getRand(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void printMenu() {
    printf("\n*** Guess the Number ***\n\n");
    printf("Choose difficulty level:\n");
    printf("1. Easy (1-50)\n");
    printf("2. Medium (1-100)\n");
    printf("3. Hard (1-200)\n");
    printf("4. Expert (1-1000)\n");
    printf("5. Exit\n");
}

void play(int min, int max) {
    int number = getRand(min, max);
    int guess, attempts = 0;
    while (1) {
        printf("Enter your guess (%d-%d): ", min, max);
        scanf("%d", &guess);
        attempts++;
        if (guess == number) {
            printf("Congratulations! You guessed the number in %d attempts\n", attempts);
            break;
        } else if (guess < number) {
            printf("Too low, try again.\n");
        } else {
            printf("Too high, try again.\n");
        }
    }
}

int main() {
    srand(time(0));
    int choice;
    int min, max;
    do {
        printMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                min = MIN_RANGE;
                max = 50;
                play(min, max);
                break;
            case 2:
                min = MIN_RANGE;
                max = MAX_RANGE;
                play(min, max);
                break;
            case 3:
                min = MIN_RANGE;
                max = 200;
                play(min, max);
                break;
            case 4:
                min = MIN_RANGE;
                max = 1000;
                play(min, max);
                break;
            case 5:
                printf("Good bye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}