//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, result, choice, i;
    char op;
    
    printf("Welcome to the Math Exercise Program!\n");
    printf("Please choose an operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    scanf("%d", &choice);
    
    srand(time(NULL));
    num1 = rand() % 100;
    num2 = rand() % 100;
    
    switch(choice) {
        case 1:
            printf("Enter the first number: ");
            scanf("%d", &num1);
            printf("Enter the second number: ");
            scanf("%d", &num2);
            result = num1 + num2;
            printf("The result is %d.\n", result);
            break;
        case 2:
            printf("Enter the first number: ");
            scanf("%d", &num1);
            printf("Enter the second number: ");
            scanf("%d", &num2);
            result = num1 - num2;
            printf("The result is %d.\n", result);
            break;
        case 3:
            printf("Enter the first number: ");
            scanf("%d", &num1);
            printf("Enter the second number: ");
            scanf("%d", &num2);
            result = num1 * num2;
            printf("The result is %d.\n", result);
            break;
        case 4:
            printf("Enter the first number: ");
            scanf("%d", &num1);
            printf("Enter the second number: ");
            scanf("%d", &num2);
            if(num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                result = num1 / num2;
                printf("The result is %d.\n", result);
            }
            break;
        default:
            printf("Invalid choice.\n");
    }
    
    return 0;
}