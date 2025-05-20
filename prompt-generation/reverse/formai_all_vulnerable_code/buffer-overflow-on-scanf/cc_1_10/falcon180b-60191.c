//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a function to generate a random number between min and max
double random_number(double min, double max) {
    return (rand() % 1000) / 1000.0 * (max - min) + min;
}

int main() {
    int num_problems = 10; // Number of problems to generate
    int i;

    // Loop through num_problems and generate random math problems
    for (i = 0; i < num_problems; i++) {
        int operation = rand() % 4; // Randomly select an operation (0 = addition, 1 = subtraction, 2 = multiplication, 3 = division)
        double num1 = random_number(1, 10); // Generate a random number between 1 and 10
        double num2 = random_number(1, 10); // Generate another random number between 1 and 10

        switch (operation) {
            case 0: // Addition
                printf("Problem %d: %.1f + %.1f = ", i+1, num1, num2);
                break;
            case 1: // Subtraction
                printf("Problem %d: %.1f - %.1f = ", i+1, num1, num2);
                break;
            case 2: // Multiplication
                printf("Problem %d: %.1f * %.1f = ", i+1, num1, num2);
                break;
            case 3: // Division
                printf("Problem %d: %.1f / %.1f = ", i+1, num1, num2);
                break;
        }

        // Get user's answer and compare with correct answer
        double user_answer;
        scanf("%lf", &user_answer);

        double correct_answer;
        switch (operation) {
            case 0:
                correct_answer = num1 + num2;
                break;
            case 1:
                correct_answer = num1 - num2;
                break;
            case 2:
                correct_answer = num1 * num2;
                break;
            case 3:
                correct_answer = num1 / num2;
                break;
        }

        if (abs(user_answer - correct_answer) <= 0.01) { // Check if user's answer is within 0.01 of correct answer
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %.2f.\n", correct_answer);
        }
    }

    return 0;
}