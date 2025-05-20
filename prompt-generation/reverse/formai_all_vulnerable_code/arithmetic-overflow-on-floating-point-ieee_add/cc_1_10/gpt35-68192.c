//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: grateful
#include <stdio.h>
#include <math.h>

int main() {
    char operator;
    double num1, num2, result;
    
    printf("Welcome to the Scientific Calculator!\n\n");
    
    // Prompt user for mathematical operation to perform
    printf("Please enter an operator (+, -, *, /, pow, sqrt): ");
    scanf("%c", &operator);
    
    // Check if operator is pow or sqrt
    if (operator == 'pow' || operator == 'sqrt') {
        printf("Please enter one number: ");
        scanf("%lf", &num1);
        
        // Calculate result
        if (operator == 'pow') {
            result = pow(num1, 2);
            printf("The result of %lf to the power of 2 is %lf\n", num1, result);
        } else {
            result = sqrt(num1);
            printf("%lf's square root is %lf\n", num1, result);
        }
    } else {
        // Otherwise, prompt user for two numbers
        printf("Please enter two numbers: ");
        scanf("%lf %lf", &num1, &num2);
        
        // Calculate result based on operator
        switch(operator) {
            case '+':
                result = num1 + num2;
                printf("%lf + %lf = %lf\n", num1, num2, result);
                break;
            case '-':
                result = num1 - num2;
                printf("%lf - %lf = %lf\n", num1, num2, result);
                break;
            case '*':
                result = num1 * num2;
                printf("%lf * %lf = %lf\n", num1, num2, result);
                break;
            case '/':
                result = num1 / num2;
                printf("%lf / %lf = %lf\n", num1, num2, result);
                break;
            default:
                printf("Invalid operator entered. Please try again.\n");
                break;
        }
    }
    
    return 0;
}