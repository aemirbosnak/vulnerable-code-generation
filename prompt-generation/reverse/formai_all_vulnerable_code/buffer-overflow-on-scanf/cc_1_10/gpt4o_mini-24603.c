//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number
int generateRandomNumber(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

// Function to perform arithmetic operations
void performArithmetic(int a, int b) {
    printf("Performing arithmetic operations on %d and %d:\n", a, b);
    printf("Addition: %d + %d = %d\n", a, b, a + b);
    printf("Subtraction: %d - %d = %d\n", a, b, a - b);
    printf("Multiplication: %d * %d = %d\n", a, b, a * b);
    if (b != 0) {
        printf("Division: %d / %d = %.2f\n", a, b, (float)a / b);
    } else {
        printf("Division: Division by zero is undefined!\n");
    }
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    int num1, num2;
    
    printf("Welcome to the Puzzling Arithmetic Program!\n");
    printf("Generating two random numbers between 1 and 100...\n");

    // Generate two random numbers
    num1 = generateRandomNumber(1, 100);
    num2 = generateRandomNumber(1, 100);
    
    // Display the generated numbers
    printf("Randomly generated numbers are: %d and %d\n", num1, num2);
    
    // Create a puzzle by asking user to guess a number
    int guess, sum = num1 + num2;
    printf("Puzzle: What is the sum of %d and %d? (Hint: it's between %d and %d)\n", num1, num2, sum - 10, sum + 10);
    printf("Enter your guess: ");
    scanf("%d", &guess);
    
    // Check the user's guess
    if (guess == sum) {
        printf("Congratulations! You guessed it right!\n");
    } else {
        printf("Wrong guess! The correct answer is %d.\n", sum);
    }
    
    // Now execute arithmetic operations
    performArithmetic(num1, num2);
    
    // Additional arithmetic puzzle
    int randomChoices[5] = {num1, num2, sum, generateRandomNumber(1, 50), generateRandomNumber(51, 100)};
    int chosenIndex = generateRandomNumber(0, 4);
    
    printf("Choose two numbers from the following:\n");
    for (int i = 0; i < 5; i++) {
        printf("Option %d: %d\n", i + 1, randomChoices[i]);
    }
    
    int chosenNum1, chosenNum2;
    printf("Enter the index of your first choice (1-5): ");
    scanf("%d", &chosenNum1);
    printf("Enter the index of your second choice (1-5): ");
    scanf("%d", &chosenNum2);
    
    // Validate user selections
    if (chosenNum1 < 1 || chosenNum1 > 5 || chosenNum2 < 1 || chosenNum2 > 5 || chosenNum1 == chosenNum2) {
        printf("Invalid selection. Please ensure you pick different numbers between 1 and 5.\n");
        return 1;
    }
    
    int selectedNum1 = randomChoices[chosenNum1 - 1];
    int selectedNum2 = randomChoices[chosenNum2 - 1];
    
    // Perform arithmetic on the user-selected numbers
    printf("Performing additional arithmetic on %d and %d:\n", selectedNum1, selectedNum2);
    performArithmetic(selectedNum1, selectedNum2);
    
    // End of the puzzling program
    printf("Thank you for participating in the Puzzling Arithmetic Program!\n");
    
    return 0;
}