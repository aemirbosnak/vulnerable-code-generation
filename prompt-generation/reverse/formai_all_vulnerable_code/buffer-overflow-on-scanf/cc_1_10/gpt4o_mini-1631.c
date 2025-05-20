//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10

void print_welcome_message() {
    printf("****************************************************\n");
    printf("              Welcome to the Math Quiz!            \n");
    printf("****************************************************\n");
    printf("Test your math skills with some exciting questions!\n");
}

void generate_question(int *num1, int *num2, char *operation) {
    *num1 = rand() % 10 + 1; // Random number between 1 and 10
    *num2 = rand() % 10 + 1;
    int op = rand() % 4; // Random number to select operation

    switch (op) {
        case 0:
            *operation = '+';
            break;
        case 1:
            *operation = '-';
            break;
        case 2:
            *operation = '*';
            break;
        case 3:
            *operation = '/';
            if (*num2 == 0) {
                *num2 = 1; // Ensure no division by zero
            }
            break;
    }
}

int calculate_answer(int num1, int num2, char operation) {
    switch (operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
    }
    return 0; // Just to prevent warnings
}

void play_quiz() {
    int num1, num2, user_answer, correct_answer;
    char operation;
    int score = 0;

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        generate_question(&num1, &num2, &operation);

        printf("Question %d: What is %d %c %d? ", i + 1, num1, operation, num2);
        scanf("%d", &user_answer);

        correct_answer = calculate_answer(num1, num2, operation);
        
        if (user_answer == correct_answer) {
            printf("Correct! Well done!\n\n");
            score++;
        } else {
            printf("Oops! The correct answer is %d.\n\n", correct_answer);
        }
    }

    printf("Quiz Finished! Your score is %d out of %d.\n", score, MAX_QUESTIONS);
    
    if (score == MAX_QUESTIONS) {
        printf("Amazing! You're a math genius!\n");
    } else if (score >= MAX_QUESTIONS / 2) {
        printf("Good job! Keep practicing!\n");
    } else {
        printf("Don't give up! Try again!\n");
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    print_welcome_message();
    play_quiz();

    printf("Thank you for playing the Math Quiz! See you next time!\n");
    return 0;
}