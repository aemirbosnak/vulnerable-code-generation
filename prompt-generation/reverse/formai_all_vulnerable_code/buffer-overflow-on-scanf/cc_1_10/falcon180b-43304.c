//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate a random number between two given numbers
double getRandomNumber(double min, double max) {
    double randNum = (double)rand() / RAND_MAX;
    randNum *= (max - min);
    randNum += min;
    return randNum;
}

int main() {
    int numProblems;
    int correctAnswers = 0;
    int totalProblems = 0;
    int userAnswer;
    double correctAnswer;
    int difficulty;

    // Ask user for number of problems they want to solve
    printf("Enter the number of problems you want to solve: ");
    scanf("%d", &numProblems);

    // Loop through the number of problems
    for (int i = 0; i < numProblems; i++) {
        totalProblems++;

        // Ask user for difficulty level (1-5)
        printf("Enter the difficulty level (1-5): ");
        scanf("%d", &difficulty);

        // Generate random numbers for the problem based on difficulty level
        double num1, num2;
        if (difficulty == 1) {
            num1 = getRandomNumber(1, 10);
            num2 = getRandomNumber(1, 10);
        } else if (difficulty == 2) {
            num1 = getRandomNumber(10, 100);
            num2 = getRandomNumber(10, 100);
        } else if (difficulty == 3) {
            num1 = getRandomNumber(100, 1000);
            num2 = getRandomNumber(100, 1000);
        } else if (difficulty == 4) {
            num1 = getRandomNumber(1000, 10000);
            num2 = getRandomNumber(1000, 10000);
        } else {
            num1 = getRandomNumber(10000, 100000);
            num2 = getRandomNumber(10000, 100000);
        }

        // Ask user for their answer
        printf("Solve the following problem:\n");
        printf("%d + %d = ", num1, num2);
        scanf("%d", &userAnswer);

        // Calculate correct answer
        correctAnswer = num1 + num2;

        // Check if user's answer is correct
        if (userAnswer == correctAnswer) {
            printf("Correct!\n");
            correctAnswers++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", correctAnswer);
        }
    }

    // Print user's score
    printf("You got %d out of %d problems correct.\n", correctAnswers, totalProblems);

    return 0;
}