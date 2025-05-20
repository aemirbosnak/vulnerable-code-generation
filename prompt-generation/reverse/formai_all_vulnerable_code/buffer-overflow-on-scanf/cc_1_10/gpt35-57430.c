//FormAI DATASET v1.0 Category: Math exercise ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to Math Bootcamp!\n");
    printf("Are you ready to get started? (y/n) ");
    char response;
    scanf("%c", &response);

    if(response != 'y' && response != 'Y') {
        printf("Well too bad, because we're getting started anyway!\n");
    }

    int num1, num2, answer, guess;
    char operator;
    int score = 0;

    srand(time(NULL));

    while(1) {
        num1 = rand() % 11;
        num2 = rand() % 11;

        int index = rand() % 3;
        if(index == 0) {
            operator = '+';
            answer = num1 + num2;
        } else if(index == 1) {
            operator = '-';
            answer = num1 - num2;
        } else {
            operator = '*';
            answer = num1 * num2;
        }

        printf("\nWhat is %d %c %d? ", num1, operator, num2);
        scanf("%d", &guess);

        if(guess == answer) {
            printf("Correct! You are a math genius!\n");
            score++;
        } else {
            printf("Wrong answer, you need to go back to math class.\n");
            printf("The correct answer is %d\n", answer);
        }

        printf("\nYour current score is: %d\n", score);

        printf("Do you want to keep playing? (y/n) ");
        scanf(" %c", &response);
        if(response != 'y' && response != 'Y') {
            printf("Thanks for playing, your final score is: %d\n", score);
            break;
        }
    }

    return 0;
}