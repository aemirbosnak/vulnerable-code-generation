//FormAI DATASET v1.0 Category: Math exercise ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, op, ans, guess, correct_guesses = 0, total_questions = 0;
    char ch;

    printf("Welcome to the Math Exercise Program!\n\n");
    printf("Enter your name: ");
    scanf("%s", &ch);
    printf("Hello %s, let's begin!\n", &ch);

    while(1) {
        srand(time(NULL));
        num1 = rand() % 100;
        num2 = rand() % 50;
        op = rand() % 3;
        ans = 0;

        switch(op) {
            case 0:
                ans = num1 + num2;
                printf("What is %d + %d?\n", num1, num2);
                break;
            case 1:
                ans = num1 - num2;
                printf("What is %d - %d?\n", num1, num2);
                break;
            case 2:
                ans = num1 * num2;
                printf("What is %d * %d?\n", num1, num2);
                break;
        }

        total_questions++;

        printf("Your answer: ");
        scanf("%d", &guess);

        if(guess == ans) {
            printf("Correct!\n");
            correct_guesses++;
        } else {
            printf("Incorrect! The correct answer is %d.\n", ans);
        }

        printf("You have answered %d out of %d questions correctly.\n\n", correct_guesses, total_questions);

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &ch);

        if(ch == 'n') {
            break;
        } else if(ch != 'y') {
            printf("Invalid response, exiting the program.\n");
            break;
        }
    }

    printf("\nYou answered %d out of %d questions correctly. Thanks for playing!\n", correct_guesses, total_questions);

    return 0;
}