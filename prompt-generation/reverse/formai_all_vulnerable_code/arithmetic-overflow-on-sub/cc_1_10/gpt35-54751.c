//FormAI DATASET v1.0 Category: Math exercise ; Style: realistic
// A program to generate a random math exercise automatically and check the user's input

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, operation, max_num, user_answer, correct_answer;
    char operator_char;
    int score = 0, total_questions = 0;
    int quit = 0;

    // Ask user for maximum number to use in exercises
    printf("Enter the maximum number to use in exercises: ");
    scanf("%d", &max_num);
    printf("\n");

    do {
        // Generate random numbers and operation
        srand(time(NULL));
        num1 = rand() % max_num + 1;
        num2 = rand() % max_num + 1;
        operation = rand() % 4; // 0 = add, 1 = subtract, 2 = multiply, 3 = divide

        // Convert operation to character for display
        switch (operation) {
            case 0:
                operator_char = '+';
                correct_answer = num1 + num2;
                break;
            case 1:
                operator_char = '-';
                correct_answer = num1 - num2;
                break;
            case 2:
                operator_char = '*';
                correct_answer = num1 * num2;
                break;
            case 3:
                operator_char = '/';
                correct_answer = num1 / num2;
                break;
        }

        // Display math exercise and ask user for input
        printf("What is the answer to %d %c %d?\n", num1, operator_char, num2);
        printf("Enter your answer (or -1 to quit): ");
        scanf("%d", &user_answer);
        printf("\n");

        // Check user input and give feedback
        if (user_answer == -1) {
            quit = 1;
        }
        else if (user_answer == correct_answer) {
            printf("Correct!\n");
            score++;
        }
        else {
            printf("Incorrect. The correct answer is %d.\n", correct_answer);
        }

        total_questions++;

    } while (!quit);

    // Display user's score
    printf("You answered %d out of %d questions correctly.\n", score, total_questions);

    return 0;
}