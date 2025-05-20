//FormAI DATASET v1.0 Category: Math exercise ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seed the random number generator with current time

    printf("Welcome to the Math Exercise Program\n");
    printf("Please choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");

    int operation;
    scanf("%d", &operation);
    if (operation < 1 || operation > 4) {
        printf("Invalid operation selected. Exiting...\n");
        return 0;
    }

    int correct_answers = 0; // keep track of number of correct answers
    int total_questions = 0; // keep track of total number of questions asked

    while (1) { // loop until user chooses to exit
        int num1 = rand() % 100 + 1; // generate random numbers
        int num2 = rand() % 100 + 1;

        int result; // variable to hold correct answer

        char op; // character to hold operator for printing purposes
        switch (operation) {
            case 1:
                result = num1 + num2;
                op = '+';
                break;
            case 2:
                result = num1 - num2;
                op = '-';
                break;
            case 3:
                result = num1 * num2;
                op = '*';
                break;
            case 4:
                if (num2 == 0) { // avoid division by zero
                    continue;
                }
                result = num1 / num2;
                op = '/';
                break;
        }

        printf("What is %d %c %d?\n", num1, op, num2);

        int answer;
        scanf("%d", &answer);

        if (answer == result) {
            correct_answers++;
            printf("Correct!\n");
        } else {
            printf("Wrong. The correct answer is %d\n", result);
        }

        total_questions++;

        printf("Do you want to continue? (y/n)\n");

        char choice;
        scanf(" %c", &choice); // leave a space before %c to skip leading white space

        if (choice == 'n') {
            break;
        }
    }

    float accuracy = (float)correct_answers / total_questions * 100;

    printf("You answered %d questions correctly out of %d, with an accuracy of %.2f%%\n", correct_answers, total_questions, accuracy);

    return 0;
}