//FormAI DATASET v1.0 Category: Math exercise ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void) {
    int num1, num2, result, answer, op, count, correct_count = 0;
    char op_symbol;
    srand(time(NULL)); // Initialize random number generator
    
    printf("Welcome to the Math Quiz!\n");
    printf("Enter the number of questions you want to attempt: ");
    scanf("%d", &count);
    
    for (int i = 0; i < count; i++) {
        num1 = rand() % 100;
        num2 = rand() % 100;
        op = rand() % 4;
        
        switch (op) {
            case 0: // Addition
                op_symbol = '+';
                result = num1 + num2;
                break;
            case 1: // Subtraction
                op_symbol = '-';
                result = num1 - num2;
                break;
            case 2: // Multiplication
                op_symbol = '*';
                result = num1 * num2;
                break;
            case 3: // Division
                op_symbol = '/';
                result = num1 / num2;
                break;
            default:
                break;
        }
        
        printf("\n%d. What is %d %c %d? ", i+1, num1, op_symbol, num2);
        scanf("%d", &answer);
        
        if (answer == result) {
            printf("Correct!");
            correct_count++;
        } else {
            printf("Incorrect! The correct answer is %d", result);
        }
    }
    
    double score = (double) correct_count / (double) count * 100.0;
    printf("\n\nYou answered %d out of %d questions correctly.", correct_count, count);
    printf("\nYour score is %.2f%%. Congratulations!", score);
    
    return 0;
}