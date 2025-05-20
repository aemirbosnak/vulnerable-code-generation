//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_OF_QUESTIONS 5

void display_welcome_message() {
    printf("=================================================\n");
    printf("        Welcome to the Math Quiz Challenge!      \n");
    printf("=================================================\n");
    printf("Test your basic math skills and have some fun! \n");
    printf("You will be asked %d questions. Let's see how you do!\n", NUMBER_OF_QUESTIONS);
    printf("=================================================\n");
}

int generate_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

char select_random_operator() {
    char operators[] = {'+', '-', '*', '/'};
    return operators[generate_random_number(0, 3)];
}

double perform_operation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (b != 0) ? (a / b) : 0; // Avoid division by zero
        default: return 0;
    }
}

void ask_question(int question_number) {
    double num1 = generate_random_number(1, 20);
    double num2 = generate_random_number(1, 20);
    char operator = select_random_operator();

    double correct_answer = perform_operation(num1, num2, operator);

    printf("Question %d: What is %.2f %c %.2f? ", question_number, num1, operator, num2);
    
    double user_answer;
    scanf("%lf", &user_answer);

    if (user_answer == correct_answer) {
        printf("Correct! 🎉\n\n");
    } else {
        printf("Oops! The correct answer was %.2f. 😢\n\n", correct_answer);
    }
}

void conduct_quiz() {
    for (int i = 1; i <= NUMBER_OF_QUESTIONS; i++) {
        ask_question(i);
    }
}

void display_goodbye_message() {
    printf("=================================================\n");
    printf("          Thanks for playing the Math Quiz!     \n");
    printf("=================================================\n");
    printf("Hope you had fun. Keep practicing and see you next time!\n");
}

int main() {
    srand(time(0)); // Seed the random number generator

    display_welcome_message();
    conduct_quiz();
    display_goodbye_message();

    return 0;
}