//FormAI DATASET v1.0 Category: Arithmetic ; Style: curious
#include <stdio.h>

int main() {
    int a, b, result;
    char operator;
    
    printf("Welcome to the Arithmetic Bot! Please enter your first number: ");
    scanf("%d", &a);
    
    printf("Great! Now enter your second number: ");
    scanf("%d", &b);
    
    printf("Please enter your operator (+,-,*,/,%): ");
    scanf(" %c", &operator);
    
    switch(operator) {
        case '+':
            result = a + b;
            break;
            
        case '-':
            result = a - b;
            break;
            
        case '*':
            result = a * b;
            break;
            
        case '/':
            if(b == 0) {
                printf("Invalid input! Division by zero is not defined.\n");
                return 0;
            }
            result = a / b;
            break;
            
        case '%':
            if(b == 0) {
                printf("Invalid input! Division by zero is not defined.\n");
                return 0; 
            }
            result = a % b;
            break;
            
        default:
            printf("Invalid operator! Please enter a valid operator (+,-,*,/,%).\n");
            return 0;
    }
    
    printf("The result of %d %c %d = %d\n", a, operator, b, result);
    
    printf("Thank you for using the Arithmetic Bot! Please come back again soon.\n");
    
    return 0;
}