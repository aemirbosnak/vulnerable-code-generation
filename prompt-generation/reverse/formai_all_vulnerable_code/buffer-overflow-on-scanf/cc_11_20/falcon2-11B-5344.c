//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: automated
#include <stdio.h>
#include <math.h>

#define MAX_OPERANDS 10

int main() {
    int num1, num2, operation, result = 0;
    char op[MAX_OPERANDS + 1];
    
    printf("Welcome to the scientific calculator!\n");
    
    while (1) {
        printf("Enter the first number: ");
        scanf("%d", &num1);
        
        printf("Enter the second number: ");
        scanf("%d", &num2);
        
        printf("Enter the operation: (+, -, *, /, %, ^, sqrt, abs)\n");
        scanf("%s", op);
        
        if (strcmp(op, "+") == 0)
            result = num1 + num2;
        else if (strcmp(op, "-") == 0)
            result = num1 - num2;
        else if (strcmp(op, "*") == 0)
            result = num1 * num2;
        else if (strcmp(op, "/") == 0)
            result = num1 / num2;
        else if (strcmp(op, "%") == 0)
            result = num1 % num2;
        else if (strcmp(op, "^") == 0)
            result = pow(num1, num2);
        else if (strcmp(op, "sqrt") == 0)
            result = sqrt(num1);
        else if (strcmp(op, "abs") == 0)
            result = fabs(num1);
        
        printf("%.2f\n", result);
        
        printf("Do you want to continue? (y/n): ");
        char ans;
        scanf("%c", &ans);
        
        if (ans!= 'y')
            break;
    }
    
    printf("Thanks for using the scientific calculator!\n");
    
    return 0;
}