//FormAI DATASET v1.0 Category: Math exercise ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seed random number generator

    int operand1 = rand() % 100; // generate random number between 0 and 99
    int operand2 = rand() % 10 + 1; // generate random number between 1 and 10
    char operator = rand() % 3 == 0 ? '+' : rand() % 2 == 0 ? '-' : '*'; // randomize operator

    printf("Welcome to the Math Exercise Program!\n\n");
    printf("In this program, you will be presented with a math exercise in the form of:\n");
    printf("   operand1 operator operand2 = ?\n");
    printf("Your task is to solve the exercise by entering the correct answer.\n\n");
    printf("Let's get started!\n\n");

    int answer;
    int correctAnswer;
    char response[10];

    while (1) { // repeat until user quits
        printf("Exercise: %d %c %d = ?\n", operand1, operator, operand2);
        printf("Enter your answer: ");
        scanf("%d", &answer);

        // calculate correct answer based on operator
        switch(operator) {
            case '+':
                correctAnswer = operand1 + operand2;
                break;
            case '-':
                correctAnswer = operand1 - operand2;
                break;
            case '*':
                correctAnswer = operand1 * operand2;
                break;
        }

        // check user's answer
        if (answer == correctAnswer) {
            printf("Congratulations! Your answer is correct.\n");
        } else {
            printf("Sorry, your answer is incorrect. The correct answer is: %d\n", correctAnswer);
        }

        // ask user if they want to continue or quit
        printf("Do you want to continue (y/n)? ");
        scanf("%s", response);

        if (response[0] == 'n' || response[0] == 'N') {
            break;
        }

        // generate new exercise
        operand1 = rand() % 100;
        operand2 = rand() % 10 + 1;
        operator = rand() % 3 == 0 ? '+' : rand() % 2 == 0 ? '-' : '*';
    }

    printf("Thank you for using the Math Exercise Program!\n");

    return 0;
}