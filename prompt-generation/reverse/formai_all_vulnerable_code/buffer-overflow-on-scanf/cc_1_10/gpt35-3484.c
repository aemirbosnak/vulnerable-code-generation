//FormAI DATASET v1.0 Category: Math exercise ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

int main() {
    // Set the seed for the random number generator
    srand(time(NULL));
    int num1, num2, operation, answer, userAnswer;
    int numCorrect = 0;
    
    printf("Welcome to Math Exercise Program!\n\n");
    printf("You will be given 10 math problems to solve.\n\n");
    
    for (int i = 1; i <= 10; i++) {
        // Generate two random numbers
        num1 = generateRandomNumber(1, 100);
        num2 = generateRandomNumber(1, 100);
        
        // Generate a random operation (addition, subtraction, or multiplication)
        operation = generateRandomNumber(1, 3);
        
        // Perform the operation and store the answer
        switch (operation) {
            case 1:
                // Addition
                printf("%d) %d + %d = ", i, num1, num2);
                answer = num1 + num2;
                break;
            case 2:
                // Subtraction
                printf("%d) %d - %d = ", i, num1, num2);
                answer = num1 - num2;
                break;
            case 3:
                // Multiplication
                printf("%d) %d * %d = ", i, num1, num2);
                answer = num1 * num2;
                break;
        }
        
        // Get the user's answer
        scanf("%d", &userAnswer);
        
        // Check if the user's answer is correct
        if (userAnswer == answer) {
            printf("Correct!\n");
            numCorrect++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", answer);
        }
        
        printf("\n");
    }
    
    // Print the user's score
    printf("You got %d out of 10 questions correct.\n", numCorrect);
    
    return 0;
}