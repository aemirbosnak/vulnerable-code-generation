//FormAI DATASET v1.0 Category: Math exercise ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define MAX_NUMS 100
#define ITERATION_DELAY 500

typedef struct {
    double num1;
    double num2;
    double result;
    bool is_calculated;
} MathProblem;

void print_problem(MathProblem* problem) {
    printf("Problem: %.2f + %.2f = ", problem->num1, problem->num2);
}

void solve_math_problem(MathProblem* problem) {
    problem->result = problem->num1 + problem->num2;
    problem->is_calculated = true;
}

int main() {
    MathProblem problems[MAX_NUMS];
    int num_problems;
    
    srand(time(NULL)); // Seed random number generator
    
    printf("How many math problems do you want to solve? ");
    scanf("%d", &num_problems);
    
    // Generate math problems
    for (int i = 0; i < num_problems; i++) {
        double num1 = (double) rand() / RAND_MAX * 50; // Generate random number between 0 and 50
        double num2 = (double) rand() / RAND_MAX * 50;
        problems[i].num1 = num1;
        problems[i].num2 = num2;
        problems[i].is_calculated = false;
    }
    
    // Print problems and ask for user input
    for (int i = 0; i < num_problems; i++) {
        print_problem(&problems[i]);
        double user_input;
        scanf("%lf", &user_input);
        
        // Check if user input is correct
        if (fabs(user_input - problems[i].result) < 0.01) { // Allow for small rounding errors
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %.2f\n", problems[i].result);
        }
        
        // Solve problem asynchronously
        solve_math_problem(&problems[i]);
        printf("Solving problem %d...\n", i+1);
        usleep(ITERATION_DELAY * 1000);
        
    }
    
    // Print summary of results
    int num_correct = 0;
    for (int i = 0; i < num_problems; i++) {
        if (problems[i].is_calculated && fabs(problems[i].result - (problems[i].num1 + problems[i].num2)) < 0.01) {
            num_correct++;
        }
    }
    printf("You got %d out of %d problems correct!\n", num_correct, num_problems);
    
    return 0;
}