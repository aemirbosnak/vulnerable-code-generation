//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_instructions() {
    printf("Welcome to the Arithmetic Quiz Game!\n");
    printf("You will be presented with a series of arithmetic problems.\n");
    printf("Try to answer as many as you can correctly!\n");
    printf("Let's get started!\n\n");
}

int generate_random_number(int limit) {
    return rand() % limit;
}

char random_operator() {
    char operators[] = {'+', '-', '*', '/'};
    return operators[generate_random_number(4)];
}

int calculate_result(int num1, int num2, char operator) {
    switch(operator) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': 
            if (num2 == 0) {
                printf("Division by zero is not allowed!\n");
                return 0; // Return zero for invalid division to avoid crashing the game
            }
            return num1 / num2;
        default: return 0;
    }
}

void start_quiz(int num_questions) {
    int score = 0;

    for (int i = 1; i <= num_questions; i++) {
        int num1 = generate_random_number(100);
        int num2 = generate_random_number(100);
        char operator = random_operator();

        int correct_answer = calculate_result(num1, num2, operator);

        printf("Question %d: What is %d %c %d?\n", i, num1, operator, num2);
        int user_answer;
        printf("Your answer: ");
        scanf("%d", &user_answer);

        if (user_answer == correct_answer) {
            printf("Correct! 🎉\n");
            score++;
        } else {
            printf("Wrong! The correct answer was %d.\n", correct_answer);
        }
        printf("\n");
    }

    printf("Quiz complete! You scored %d out of %d.\n", score, num_questions);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    display_instructions();

    int num_questions;
    printf("How many questions would you like to answer? ");
    scanf("%d", &num_questions);

    if (num_questions <= 0) {
        printf("Please enter a positive number of questions.\n");
        return 1; // Exit with an error
    }

    start_quiz(num_questions);

    printf("Thank you for playing the Arithmetic Quiz Game! Goodbye! 👋\n");
    return 0;
}