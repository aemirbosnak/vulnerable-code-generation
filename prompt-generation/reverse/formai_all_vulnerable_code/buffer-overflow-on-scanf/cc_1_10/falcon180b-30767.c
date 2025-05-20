//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2;
    char operator;
    int result;
    int choice;
    
    srand(time(NULL));
    num1 = rand() % 100;
    num2 = rand() % 100;
    operator = rand() % 4;
    
    printf("Enter the operation you want to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1:
            result = num1 + num2;
            printf("Result: %d\n", result);
            break;
        case 2:
            result = num1 - num2;
            printf("Result: %d\n", result);
            break;
        case 3:
            result = num1 * num2;
            printf("Result: %d\n", result);
            break;
        case 4:
            if(num2 == 0)
            {
                printf("Error: Division by zero\n");
            }
            else
            {
                result = num1 / num2;
                printf("Result: %.2f\n", (float)result / (float)num2);
            }
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    
    return 0;
}