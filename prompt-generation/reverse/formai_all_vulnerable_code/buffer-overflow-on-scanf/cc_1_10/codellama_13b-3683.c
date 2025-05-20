//Code Llama-13B DATASET v1.0 Category: Math exercise ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a struct to hold the problem and its solution
struct Problem {
    int num1;
    int num2;
    int solution;
};

// Define a function to generate a random problem
void generate_problem(struct Problem* problem) {
    problem->num1 = rand() % 10;
    problem->num2 = rand() % 10;
    problem->solution = problem->num1 + problem->num2;
}

// Define a function to display the problem and solution
void display_problem(struct Problem* problem) {
    printf("%d + %d = ", problem->num1, problem->num2);
    printf("%d\n", problem->solution);
}

// Define a function to check if the user's answer is correct
int check_answer(struct Problem* problem, int answer) {
    if (answer == problem->solution) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Initialize a struct to hold the problem and its solution
    struct Problem problem;

    // Generate a random problem
    generate_problem(&problem);

    // Display the problem and solution
    display_problem(&problem);

    // Get the user's answer
    int answer;
    scanf("%d", &answer);

    // Check if the user's answer is correct
    int correct = check_answer(&problem, answer);

    // Display the result
    if (correct) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is %d.\n", problem.solution);
    }

    return 0;
}