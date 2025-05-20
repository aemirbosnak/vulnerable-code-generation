//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_OF_QUESTIONS 10

void generate_question(int *num1, int *num2, char *operator) {
    *num1 = rand() % 100; // Random number between 0 and 99
    *num2 = rand() % 100; // Random number between 0 and 99
    int op_choice = rand() % 3; // Choose operator randomly

    switch (op_choice) {
        case 0:
            *operator = '+';
            break;
        case 1:
            *operator = '-';
            break;
        case 2:
            *operator = '*';
            break;
    }
}

int calculate_answer(int num1, int num2, char operator) {
    switch (operator) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        default:
            return 0; // Unreachable, just for safety
    }
}

void display_result(int score) {
    printf("You answered %d out of %d questions correctly.\n", score, NUMBER_OF_QUESTIONS);
    if (score == NUMBER_OF_QUESTIONS) {
        printf("Perfect score! You're a math genius!\n");
    } else if (score >= NUMBER_OF_QUESTIONS / 2) {
        printf("Well done! Keep practicing to improve even more.\n");
    } else {
        printf("Don't worry! Practice makes perfect. Try again!\n");
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    int score = 0;

    printf("Welcome to the Math Quiz Game!\n");
    printf("You will be asked %d questions. Let's see how well you do!\n\n", NUMBER_OF_QUESTIONS);

    for (int i = 0; i < NUMBER_OF_QUESTIONS; i++) {
        int num1, num2;
        char operator;
        generate_question(&num1, &num2, &operator);

        int correct_answer = calculate_answer(num1, num2, operator);
        int user_answer;

        printf("Question %d: %d %c %d = ?\n", i + 1, num1, operator, num2);
        printf("Your answer: ");
        scanf("%d", &user_answer);

        if (user_answer == correct_answer) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect! The right answer is %d.\n\n", correct_answer);
        }
    }

    display_result(score);
    return 0;
}