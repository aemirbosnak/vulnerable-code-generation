//FormAI DATASET v1.0 Category: Math exercise ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int num1, num2, correct_ans, user_ans, tries = 0;
    char operator;

    srand(time(0));  // seed for randomizing numbers 

    printf("Welcome to the Math Exercise Program!\n\n");
    printf("This program will generate random arithmetic questions\n");
    printf("and ask you to solve them. Ready to begin? (y/n): ");

    char choice;
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y') {
        printf("\nGreat! Let's get started.\n");
        printf("Remember, you only have 3 tries for each question.\n");

        while(tries < 3) {
            num1 = rand() % 10 + 1;
            num2 = rand() % 10 + 1;
            switch(rand() % 4) {
                case 0: 
                    operator = '+';
                    correct_ans = num1 + num2;
                    break;
                case 1: 
                    operator = '-';
                    correct_ans = num1 - num2;
                    break;
                case 2: 
                    operator = '*';
                    correct_ans = num1 * num2;
                    break;
                case 3: 
                    operator = '/';
                    correct_ans = num1 / num2;
                    break;
            }

            printf("\nQuestion %d:\n", tries+1);
            printf("%d %c %d = ?", num1, operator, num2);

            scanf("%d", &user_ans);

            if (user_ans == correct_ans) {
                printf("\nCongratulations! You got it right.\n");
                tries = 0;  // reset tries if user got it right
            } else {
                printf("Incorrect. Please try again.\n");
                tries++;
            }
        }

        printf("\nYou have reached the maximum number of tries for this question.\n");
        printf("The correct answer was: %d\n", correct_ans);
        printf("Better luck on the next question!");
    } else {
        printf("\nMaybe next time. Goodbye!");
    }

    return 0;
}