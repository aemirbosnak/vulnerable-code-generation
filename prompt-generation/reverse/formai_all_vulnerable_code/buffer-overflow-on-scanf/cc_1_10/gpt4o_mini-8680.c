//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 5

void generate_question(int *num1, int *num2, char *operator) {
    *num1 = rand() % 50; // Random number between 0 and 49
    *num2 = rand() % 50; // Random number between 0 and 49
    int op_choice = rand() % 4; // Random choice for operator: 0-3

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
        case 3:
            *operator = '/'; // For simplicity, we will avoid division by zero
            if (*num2 == 0) *num2 = 1; // Ensure that denominator is not zero
            break;
    }
}

int evaluate_expression(int num1, int num2, char operator) {
    switch (operator) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2; // Integer division
        default:
            return 0; // Fallback case
    }
}

void display_feedback(int score) {
    if (score == NUM_QUESTIONS) {
        printf("Excellent work! You got all questions right!\n");
    } else if (score >= NUM_QUESTIONS / 2) {
        printf("Good job! You scored %d out of %d.\n", score, NUM_QUESTIONS);
    } else {
        printf("You scored %d out of %d. Keep practicing!\n", score, NUM_QUESTIONS);
    }
}

int main() {
    int score = 0;
    int num1, num2, user_answer, correct_answer;
    char operator;
    
    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Math Quiz!\n");
    printf("You will be presented with %d math questions. Good luck!\n\n", NUM_QUESTIONS);

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        generate_question(&num1, &num2, &operator);
        correct_answer = evaluate_expression(num1, num2, operator);

        printf("Question %d: What is %d %c %d? ", i + 1, num1, operator, num2);
        scanf("%d", &user_answer);

        if (user_answer == correct_answer) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is %d.\n\n", correct_answer);
        }
    }

    printf("Quiz Over! Your final score: %d out of %d.\n\n", score, NUM_QUESTIONS);
    display_feedback(score);

    return 0;
}