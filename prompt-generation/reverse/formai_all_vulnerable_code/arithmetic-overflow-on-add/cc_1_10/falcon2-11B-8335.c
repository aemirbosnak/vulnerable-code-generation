//Falcon2-11B DATASET v1.0 Category: Searching algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int num, guess, high, low, mid, x, i;
    char answer[10];

    printf("Welcome to the Paranoid Number Guessing Game!\n");
    printf("Think of a number between 1 and 100.\n");
    printf("I will try to guess your number in 10 tries or less.\n");

    printf("Enter the high number: ");
    scanf("%d", &high);

    printf("Enter the low number: ");
    scanf("%d", &low);

    printf("You are a very suspicious person, so I will guess your number like this: \n");
    printf("First, I will guess your number is %d. If you say no, then I will guess your number is %d. \n", (high+low)/2, (high+low)/2);

    while (1) {
        if (low == high) {
            printf("Congratulations, you are correct! Your number was %d!\n", low);
            printf("I am relieved that I didn't have to guess your number 10 times.\n");
            return 0;
        }

        printf("Is my guess correct? (y/n)");
        scanf("%s", answer);

        if (answer[0] == 'y') {
            printf("Congratulations, I guessed your number correctly!\n");
            printf("I am relieved that I didn't have to guess your number 10 times.\n");
            return 0;
        }

        if (answer[0] == 'n') {
            if (low == high) {
                printf("Congratulations, you are correct! Your number was %d!\n", low);
                printf("I am relieved that I didn't have to guess your number 10 times.\n");
                return 0;
            }

            mid = (low + high) / 2;
            if (mid == low) {
                printf("Is your number %d? (y/n) \n", mid);
                scanf("%s", answer);
            } else if (mid == high) {
                printf("Is your number %d? (y/n) \n", mid);
                scanf("%s", answer);
            } else {
                printf("Is your number %d? (y/n) \n", mid);
                scanf("%s", answer);
            }
        }

        if (answer[0] == 'n') {
            if (low == high) {
                printf("Congratulations, you are correct! Your number was %d!\n", low);
                printf("I am relieved that I didn't have to guess your number 10 times.\n");
                return 0;
            }

            high = mid;
            printf("I will guess your number is %d. If you say no, then I will guess your number is %d. \n", high, low);
        } else {
            low = mid;
            printf("I will guess your number is %d. If you say no, then I will guess your number is %d. \n", low, high);
        }
    }
}