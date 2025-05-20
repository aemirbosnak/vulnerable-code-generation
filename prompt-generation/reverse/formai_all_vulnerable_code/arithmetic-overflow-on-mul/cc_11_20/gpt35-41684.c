//FormAI DATASET v1.0 Category: Math exercise ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Choose the range of numbers to use
    int min, max;
    printf("Enter the minimum value: ");
    scanf("%d", &min);
    printf("Enter the maximum value: ");
    scanf("%d", &max);
    
    // Choose the operation to perform
    char op;
    do {
        printf("Enter the operation (+, -, *, /): ");
        scanf(" %c", &op);
    } while (op != '+' && op != '-' && op != '*' && op != '/');
    
    // Generate two random numbers
    int num1 = rand() % (max - min + 1) + min;
    int num2 = rand() % (max - min + 1) + min;
    
    // Calculate the answer
    double ans;
    switch (op) {
        case '+':
            ans = num1 + num2;
            break;
        case '-':
            ans = num1 - num2;
            break;
        case '*':
            ans = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("Cannot divide by zero!\n");
                return 1;
            }
            ans = (double) num1 / num2;
            break;
    }
    
    // Ask the user for the answer
    double guess;
    printf("What is %d %c %d?\n", num1, op, num2);
    scanf("%lf", &guess);
    
    // Check the answer
    if (guess == ans) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The answer was %f.\n", ans);
    }
    
    return 0;
}