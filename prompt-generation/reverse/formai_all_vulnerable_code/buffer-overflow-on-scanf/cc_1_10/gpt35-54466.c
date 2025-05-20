//FormAI DATASET v1.0 Category: Math exercise ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set random seed
    srand(time(NULL));
    
    int num1, num2;
    char operator;
    int answer;
    int userAnswer;
    int numCorrect = 0;
    int numWrong = 0;
    
    // Loop until user is done
    while (1) {
        // Generate two random numbers between 1 and 9
        num1 = rand() % 9 + 1;
        num2 = rand() % 9 + 1;
        
        // Randomly select an operation
        switch (rand() % 3) {
            case 0:
                operator = '+';
                answer = num1 + num2;
                break;
            case 1:
                operator = '-';
                answer = num1 - num2;
                break;
            case 2:
                operator = '*';
                answer = num1 * num2;
                break;
        }
        
        // Prompt user to solve problem
        printf("What is %d %c %d?\n", num1, operator, num2);
        scanf("%d", &userAnswer);
        
        // Check user's answer
        if (userAnswer == answer) {
            printf("Correct!\n");
            numCorrect++;
        } else {
            printf("Wrong. The correct answer is %d.\n", answer);
            numWrong++;
        }
        
        // Prompt user to continue or quit
        printf("Do you want to continue? (y/n)\n");
        char choice;
        scanf(" %c", &choice);
        
        // End loop if user chooses to quit
        if (choice == 'n') {
            break;
        }
    }
    
    // Print final score
    printf("You got %d correct and %d wrong.\n", numCorrect, numWrong);
    
    return 0;
}