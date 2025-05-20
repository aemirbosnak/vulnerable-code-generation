//FormAI DATASET v1.0 Category: Math exercise ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int num1, num2, answer, user_answer;
    char operator;
    int i, correct_count = 0, total_count = 0;
    float percentage;

    srand(time(NULL));

    printf("Welcome to the Math Exercise Program!\n");
    printf("You will be given 10 random math exercises to solve.\n");
    printf("Please type in your answers and press Enter.\n\n");
    
    for (i = 0; i < 10; i++) {
        num1 = rand() % 101; // Generate a random integer between 0 and 100
        num2 = rand() % 101;
        operator = rand() % 4; // Generate a random integer between 0 and 3
        
        switch (operator) {
            case 0: // Addition
                answer = num1 + num2;
                printf("Question %d: What is %d + %d?\n", i+1, num1, num2);
                break;
            case 1: // Subtraction
                answer = num1 - num2;
                printf("Question %d: What is %d - %d?\n", i+1, num1, num2);
                break;
            case 2: // Multiplication
                answer = num1 * num2;
                printf("Question %d: What is %d x %d?\n", i+1, num1, num2);
                break;
            case 3: // Division
                while (num2 == 0) { // Ensure that num2 is not zero
                    num2 = rand() % 101;
                }
                answer = num1 / num2;
                printf("Question %d: What is %d / %d (rounded down to the nearest integer)?\n", i+1, num1, num2);
                break;
        }
        
        total_count++; // Increment total_count
        
        scanf("%d", &user_answer);
        if (user_answer == answer) {
            printf("Correct!\n\n");
            correct_count++; // Increment correct_count
        } else {
            printf("Incorrect. The correct answer is %d.\n\n", answer);
        }
    }
    
    percentage = ((float) correct_count / (float) total_count) * 100;
    printf("You got %d out of %d questions correct, which is %0.2f%%.\n", correct_count, total_count, percentage);
    
    if (percentage >= 80) {
        printf("Great job! You scored above 80%%.\n");
    } else {
        printf("You did not score above 80%%. Try again sometime!\n");
    }
    
    return 0;
}