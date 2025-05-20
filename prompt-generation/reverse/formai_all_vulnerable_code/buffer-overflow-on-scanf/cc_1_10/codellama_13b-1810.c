//Code Llama-13B DATASET v1.0 Category: Math exercise ; Style: Linus Torvalds
// A simple C Math exercise program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define a struct to store the exercise data
struct exercise {
    char name[100];
    int num_questions;
    int correct_answers;
};

// Function to generate a random number
int rand_num(int min, int max) {
    return min + (int)(((double)rand() / RAND_MAX) * (max - min + 1));
}

// Function to generate a random equation
void generate_equation(int *op1, int *op2, char *op) {
    // Generate two random numbers
    *op1 = rand_num(1, 10);
    *op2 = rand_num(1, 10);

    // Generate a random operator
    switch (rand_num(0, 2)) {
    case 0:
        *op = '+';
        break;
    case 1:
        *op = '-';
        break;
    case 2:
        *op = '*';
        break;
    }
}

// Function to check if the answer is correct
int check_answer(int op1, int op2, char op, int answer) {
    int correct = 0;
    switch (op) {
    case '+':
        correct = op1 + op2;
        break;
    case '-':
        correct = op1 - op2;
        break;
    case '*':
        correct = op1 * op2;
        break;
    }
    return correct == answer;
}

int main() {
    // Initialize the exercise struct
    struct exercise ex;
    ex.num_questions = 10;
    ex.correct_answers = 0;

    // Generate the exercise questions
    for (int i = 0; i < ex.num_questions; i++) {
        // Generate a random equation
        int op1, op2;
        char op;
        generate_equation(&op1, &op2, &op);

        // Print the question
        printf("%d %c %d = ", op1, op, op2);

        // Read the answer
        int answer;
        scanf("%d", &answer);

        // Check if the answer is correct
        if (check_answer(op1, op2, op, answer)) {
            ex.correct_answers++;
        }
    }

    // Print the results
    printf("Correct answers: %d/%d\n", ex.correct_answers, ex.num_questions);

    return 0;
}