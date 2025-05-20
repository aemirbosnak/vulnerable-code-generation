//FormAI DATASET v1.0 Category: Math exercise ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    printf("Welcome to the Math Exercise Program!\n\n");

    // Generate two random numbers between 1 and 50
    srand(time(NULL));
    int num1 = rand() % 50 + 1;
    int num2 = rand() % 50 + 1;

    // Let the user choose the operation type
    printf("Please select an operation type: \n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division (rounded to the nearest integer)\n");

    int choice;
    printf("Your choice: ");
    scanf("%d",&choice);

    // Compute the result based on the user's choice
    int result;
    switch(choice) {
        case 1:
            result = num1 + num2;
            printf("%d + %d = ", num1, num2);
            break;
        case 2:
            result = num1 - num2;
            printf("%d - %d = ", num1, num2);
            break;
        case 3:
            result = num1 * num2;
            printf("%d * %d = ", num1, num2);
            break;
        case 4:
            result = round((double)num1 / (double)num2);
            printf("%d / %d = (rounded to nearest integer) ", num1, num2);
            break;
        default:
            printf("Invalid choice! Please run the program again.\n");
            return 0;
    }

    // Let the user enter their answer
    int user_answer;
    scanf("%d",&user_answer);

    // Check if the user's answer is correct
    if(user_answer == result) {
        printf("Congratulations! Your answer is correct.\n");
    } else {
        printf("Sorry, your answer is incorrect. The correct answer is %d.\n", result);
    }

    return 0;
}