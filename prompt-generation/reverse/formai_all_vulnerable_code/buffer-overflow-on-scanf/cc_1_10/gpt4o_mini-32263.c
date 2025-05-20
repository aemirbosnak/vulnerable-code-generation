//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_OPERATIONS 10
#define MAX_N 100

// Function to generate a random operation
char generate_operation() {
    char operations[] = {'+', '-', '*', '/'};
    return operations[rand() % 4];
}

// Function to perform a random arithmetic operation
int perform_operation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b != 0) return a / b;
            else return 0; // Avoid division by zero; return zero
        default: return 0; // Fallback case
    }
}

// Function to print the arithmetic expression
void print_expression(int a, int b, char op) {
    printf("%d %c %d = ?\n", a, op, b);
}

// Function to play the arithmetic game
void play_arithmetic_game() {
    int score = 0;
    int total_questions = 0;

    printf("Welcome to the Mind-Bending Arithmetic Game!\n");
    printf("You will solve %d random arithmetic problems.\n", MAX_OPERATIONS);

    for (int i = 0; i < MAX_OPERATIONS; i++) {
        int a = rand() % MAX_N;
        int b = rand() % MAX_N;
        char op = generate_operation();

        print_expression(a, b, op);

        int correct_answer = perform_operation(a, b, op);
        int user_answer;

        printf("Your answer: ");
        scanf("%d", &user_answer);

        if (user_answer == correct_answer) {
            printf("Correct! 🎉\n");
            score++;
        } else {
            printf("Oops! The correct answer was %d.\n", correct_answer);
        }

        total_questions++;
        printf("Current Score: %d/%d\n", score, total_questions);
        printf("------------------------------\n");
    }

    printf("Game Over! Your final score is: %d/%d\n", score, total_questions);
    float percentage = ((float)score / total_questions) * 100;
    printf("You scored: %.2f%%\n", percentage);
}

// Function to present a challenge
void challenge_user() {
    int a = rand() % MAX_N;
    int b = rand() % MAX_N;
    char op = generate_operation();

    // Challenge the user with a unique statement
    printf("Challenge time! Solve this: ");
    print_expression(a, b, op);
    
    // Store the correct answer
    int correct_answer = perform_operation(a, b, op);
    int user_answer;

    printf("Your answer: ");
    scanf("%d", &user_answer);

    if (user_answer == correct_answer) {
        printf("Splendid! You are a math wizard! 🧙‍♂️\n");
    } else {
        printf("Hmm, not quite! The answer is %d. Keep trying! ✨\n", correct_answer);
    }
}

int main() {
    srand(time(NULL));  // Seed the random number generator

    char choice;
    do {
        printf("\nChoose an option:\n");
        printf("1. Play Arithmetic Game\n");
        printf("2. Take a Challenge\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                play_arithmetic_game();
                break;
            case '2':
                challenge_user();
                break;
            case '3':
                printf("Thank you for playing! Goodbye! 👋\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    } while (choice != '3');

    return 0;
}