//FormAI DATASET v1.0 Category: Math exercise ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    int num1, num2, answer, userInput, correct = 0, incorrect = 0, totalQuestions;
    char operation;
    srand(time(0));

    printf("Welcome to the Math Exercise Program!\n");
    printf("How many questions would you like to answer? ");
    scanf("%d", &totalQuestions);

    for(int i = 0; i < totalQuestions; i++) {
        num1 = generateRandomNumber(1, 10);
        num2 = generateRandomNumber(1, 10);
        int operationType = generateRandomNumber(1, 4);
        switch(operationType) {
            case 1:
                operation = '+';
                answer = num1 + num2;
                break;
            case 2:
                operation = '-';
                answer = num1 - num2;
                break;
            case 3:
                operation = '*';
                answer = num1 * num2;
                break;
            case 4:
                operation = '/';
                answer = num1 / num2;
                break;
        }

        printf("%d %c %d = ", num1, operation, num2);
        scanf("%d", &userInput);
        
        if(userInput == answer) {
            printf("Correct!\n");
            correct++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", answer);
            incorrect++;
        }
    }

    printf("Results: %d correct, %d incorrect, %.2f%%\n", correct, incorrect, (float) correct / totalQuestions * 100);
    printf("Thank you for using the Math Exercise Program!\n");

    return 0;
}