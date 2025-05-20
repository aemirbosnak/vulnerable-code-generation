//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_OPERANDS 10

typedef enum {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION
} Operation;

typedef struct {
    int operand1;
    int operand2;
    Operation operation;
} MathQuestion;

void generate_question(MathQuestion *question) {
    question->operand1 = rand() % MAX_OPERANDS;
    question->operand2 = (rand() % MAX_OPERANDS) + 1; // avoid division by zero.

    question->operation = rand() % 4; // Randomly choose an operation
}

void display_question(MathQuestion question) {
    switch (question.operation) {
        case ADDITION:
            printf("%d + %d = ?\n", question.operand1, question.operand2);
            break;
        case SUBTRACTION:
            printf("%d - %d = ?\n", question.operand1, question.operand2);
            break;
        case MULTIPLICATION:
            printf("%d * %d = ?\n", question.operand1, question.operand2);
            break;
        case DIVISION:
            printf("%d / %d = ?\n", question.operand1, question.operand2);
            break;
    }
}

int calculate_answer(MathQuestion question) {
    switch (question.operation) {
        case ADDITION:
            return question.operand1 + question.operand2;
        case SUBTRACTION:
            return question.operand1 - question.operand2;
        case MULTIPLICATION:
            return question.operand1 * question.operand2;
        case DIVISION:
            return question.operand1 / question.operand2;
        default:
            return 0;
    }
}

int main() {
    srand(time(NULL)); // Seed for randomness
    MathQuestion questions[MAX_QUESTIONS];
    int score = 0;

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        generate_question(&questions[i]);
        display_question(questions[i]);

        int user_answer;
        printf("Your answer: ");
        if (scanf("%d", &user_answer) != 1) {
            fprintf(stderr, "Invalid input. Exiting...\n");
            exit(EXIT_FAILURE);
        }

        int correct_answer = calculate_answer(questions[i]);

        if (user_answer == correct_answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", correct_answer);
        }
    }

    printf("You scored %d out of %d.\n", score, MAX_QUESTIONS);
    return 0;
}