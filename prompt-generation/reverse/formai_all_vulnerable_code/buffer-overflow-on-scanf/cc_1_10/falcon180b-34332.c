//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int num1, num2, choice;
    float result;
    char playAgain;

    srand(time(0)); // seed the random number generator with current time

    do {
        printf("Welcome to the Math Game!\n");
        printf("Please choose a difficulty level:\n");
        printf("1. Easy\n2. Medium\n3. Hard\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("You chose Easy mode.\n");
                num1 = rand() % 10 + 1; // generate a random number between 1 and 10
                num2 = rand() % 10 + 1; // generate another random number between 1 and 10
                break;
            case 2:
                printf("You chose Medium mode.\n");
                num1 = rand() % 50 + 1; // generate a random number between 1 and 50
                num2 = rand() % 50 + 1; // generate another random number between 1 and 50
                break;
            case 3:
                printf("You chose Hard mode.\n");
                num1 = rand() % 100 + 1; // generate a random number between 1 and 100
                num2 = rand() % 100 + 1; // generate another random number between 1 and 100
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                return 0;
        }

        printf("Solve the following problem:\n");
        printf("%d + %d = ", num1, num2);
        scanf("%f", &result);

        if(result == num1 + num2) {
            printf("Correct! Great job!\n");
        } else {
            printf("Incorrect. The correct answer is %d.\n", num1 + num2);
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while(playAgain == 'y' || playAgain == 'Y');

    return 0;
}