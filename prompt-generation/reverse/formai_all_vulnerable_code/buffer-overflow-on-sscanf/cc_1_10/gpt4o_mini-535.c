//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_PROBLEMS 5
#define MAX_NUM 50
#define BUFFER_SIZE 20

// Function to generate a random arithmetic problem
void generate_problem(int *num1, int *num2, char *operator) {
    *num1 = rand() % MAX_NUM;
    *num2 = rand() % MAX_NUM;

    // Randomly select an operator: +, -, *, /
    switch (rand() % 4) {
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
            *operator = '/'; 
            *num2 = (*num2 == 0) ? 1 : *num2; // Avoid division by zero
            break;
    }
}

// Function to evaluate the problem based on the operator
int evaluate_problem(int num1, int num2, char operator) {
    switch (operator) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2;
    }
    return 0; // Default return case (should not be reached)
}

// Function to display results
void display_results(float time_taken, int correct, int total) {
    printf("\n--- Results ---\n");
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Correct answers: %d/%d\n", correct, total);
    printf("Typing speed: %.2f problems/second\n", (float)total / time_taken);
}

// Main function to run the typing speed test
int main() {
    srand(time(NULL)); // Seed for random number generation
    int num1, num2, answer, correct = 0;
    char operator;
    char input[BUFFER_SIZE];
    clock_t start_time, end_time;

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given %d simple arithmetic problems.\n", NUM_PROBLEMS);
    printf("Type your answers quickly and accurately!\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for user input to start

    start_time = clock(); // Start timing

    for (int i = 0; i < NUM_PROBLEMS; i++) {
        generate_problem(&num1, &num2, &operator);

        printf("Problem %d: %d %c %d = ? ", i + 1, num1, operator, num2);
        fgets(input, BUFFER_SIZE, stdin); // Get user input
        sscanf(input, "%d", &answer); // Parse input to integer

        int correct_answer = evaluate_problem(num1, num2, operator);

        if (answer == correct_answer) {
            printf("Correct!\n");
            correct++;
        } else {
            printf("Incorrect! The correct answer was %d.\n", correct_answer);
        }
    }

    end_time = clock(); // End timing

    float time_taken = (float)(end_time - start_time) / CLOCKS_PER_SEC; // Calculate time taken
    display_results(time_taken, correct, NUM_PROBLEMS); // Display results

    return 0; // Exit program
}