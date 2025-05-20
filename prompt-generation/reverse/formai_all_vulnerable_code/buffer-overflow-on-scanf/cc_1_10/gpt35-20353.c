//FormAI DATASET v1.0 Category: Math exercise ; Style: artistic
// Welcome to our Artistic C Math Exercise Program!
// Here, we will generate a unique set of math problems based on your input.
// Let's get started!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define our functions
int generateRandom(int range);
int chooseOperation();
void generateProblem(int operation);

int main() {
    // Seed the random number generator
    srand(time(0));

    // Welcome message
    printf("Welcome to the Artistic C Math Exercise Program!\n");
    printf("Please enter the number of problems you would like to generate: ");

    // Get user input for number of problems
    int numProblems;
    scanf("%d", &numProblems);

    // Generate problems
    int i;
    for (i = 0; i < numProblems; i++) {
        int operation = chooseOperation();
        generateProblem(operation);
    }

    // End message
    printf("Thank you for using the Artistic C Math Exercise Program!\n");
    return 0;
}

// Function to generate a random number within a given range
int generateRandom(int range) {
    int randNum = (rand() % range) + 1;
    return randNum;
}

// Function to choose a random math operation
int chooseOperation() {
    int operation = generateRandom(4);
    return operation;
}

// Function to generate a math problem based on the chosen operation
void generateProblem(int operation) {
    int num1 = generateRandom(100);
    int num2 = generateRandom(100);
    int answer;

    switch (operation) {
        case 1:
            answer = num1 + num2;
            printf("%d + %d = ?\n", num1, num2);
            break;
        case 2:
            answer = num1 - num2;
            printf("%d - %d = ?\n", num1, num2);
            break;
        case 3:
            answer = num1 * num2;
            printf("%d * %d = ?\n", num1, num2);
            break;
        case 4:
            answer = num1 / num2;
            printf("%d / %d = ?\n", num1, num2);
            break;
        default:
            printf("There was an error generating this problem.\n");
            break;
    }
}