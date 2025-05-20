//FormAI DATASET v1.0 Category: Math exercise ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate two random integers between lower and upper limits (inclusive)
void generateRandomNumbers(int lower, int upper, int *num1, int *num2)
{
    // Set seed for random number generator
    srand(time(NULL));
    
    // Generate random numbers
    *num1 = (rand() % (upper - lower + 1)) + lower;
    *num2 = (rand() % (upper - lower + 1)) + lower;
}

// Function to generate a random operation ('+', '-', '*', '/')
char generateRandomOperation()
{
    // Set seed for random number generator
    srand(time(NULL));
    
    // Generate a random number between 1 and 4
    int opIndex = rand() % 4 + 1;
    
    // Return the corresponding operation
    switch (opIndex)
    {
        case 1:
            return '+';
        case 2:
            return '-';
        case 3:
            return '*';
        case 4:
            return '/';
    }
}

int main()
{
    int lowerLimit, upperLimit, num1, num2, answer, userAnswer;
    char operation;
    int score = 0;
    int attempt = 0;
    float accuracy;
    
    // Get input from user for lower and upper limits
    printf("Enter the lower limit: ");
    scanf("%d", &lowerLimit);
    printf("Enter the upper limit: ");
    scanf("%d", &upperLimit);
    
    // Loop for 10 questions
    for (int i = 1; i <= 10; i++)
    {
        // Generate random numbers and operation
        generateRandomNumbers(lowerLimit, upperLimit, &num1, &num2);
        operation = generateRandomOperation();
        
        // Print the question
        printf("\nQuestion %d: What is %d %c %d?\n", i, num1, operation, num2);
        
        // Calculate the answer
        switch (operation)
        {
            case '+':
                answer = num1 + num2;
                break;
            case '-':
                answer = num1 - num2;
                break;
            case '*':
                answer = num1 * num2;
                break;
            case '/':
                answer = num1 / num2;
                break;
        }
        
        // Get the user's answer and check if correct
        printf("Enter your answer: ");
        scanf("%d", &userAnswer);
        attempt++;
        if (userAnswer == answer)
        {
            score++;
            printf("Correct!\n");
        }
        else
        {
            printf("Incorrect. The correct answer is %d.\n", answer);
        }
    }
    
    // Calculate the accuracy
    accuracy = (float) score / attempt * 100;
    
    // Print the final score and accuracy
    printf("\nFinal Score: %d/10\n", score);
    printf("Accuracy: %.2f%%\n", accuracy);
    
    return 0;
}