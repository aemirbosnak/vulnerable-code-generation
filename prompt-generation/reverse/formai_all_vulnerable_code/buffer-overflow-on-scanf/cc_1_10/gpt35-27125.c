//FormAI DATASET v1.0 Category: Math exercise ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int random_number(int max);
void print_question(int num1, int num2, char operator);
int get_answer();
int calculate_answer(int num1, int num2, char operator);

int main() {
    int num_correct = 0;
    int num_questions = 5;

    srand(time(0));  // Seed random number generator with current time

    printf("Welcome to the math quiz!\n");
    printf("-------------------------\n");

    for (int i = 0; i < num_questions; i++) {
        // Generate random numbers and operator
        int num1 = random_number(10);
        int num2 = random_number(10);
        char operator = "+-*"[random_number(3)];

        // Print question and get user's answer
        print_question(num1, num2, operator);
        int answer = get_answer();

        // Check if user's answer is correct
        int correct_answer = calculate_answer(num1, num2, operator);
        if (answer == correct_answer) {
            printf("Correct!\n");
            num_correct++;
        } else {
            printf("Incorrect! The correct answer is %d\n", correct_answer);
        }
    }

    // Print user's score
    printf("-------------------------\n");
    printf("You got %d out of %d questions correct!\n", num_correct, num_questions);

    return 0;
}

// Helper function to generate a random number between 0 and max-1
int random_number(int max) {
    return rand() % max;
}

// Helper function to print the math question (e.g. "4 + 2 = ?")
void print_question(int num1, int num2, char operator) {
    printf("%d %c %d = ?\n", num1, operator, num2);
}

// Helper function to get the user's answer
int get_answer() {
    int answer;
    printf("Enter your answer: ");
    scanf("%d", &answer);
    return answer;
}

// Helper function to calculate the correct answer for a given math problem
int calculate_answer(int num1, int num2, char operator) {
    int answer;
    switch (operator) {
        case '+':
            answer = num1 + num2;
            break;
        case '-':
            answer = num1 - num2;
            break;
        case '*':
            answer = num1 * num2;
            break;
    }
    return answer;
}