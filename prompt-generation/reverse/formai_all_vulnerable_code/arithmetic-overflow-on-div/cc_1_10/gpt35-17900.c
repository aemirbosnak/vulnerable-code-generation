//FormAI DATASET v1.0 Category: Arithmetic ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, result, choice;
    
    printf("Enter two numbers: \n");
    scanf("%d %d", &num1, &num2);
    
    printf("\nChoose an arithmetic operation: \n");
    printf("1. Addition \n");
    printf("2. Subtraction \n");
    printf("3. Multiplication \n");
    printf("4. Division \n");
    printf("5. Modulus \n");
    
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1: // Addition
            result = num1 + num2;
            printf("\n%d + %d = %d\n", num1, num2, result);
            break;
            
        case 2: // Subtraction
            result = num1 - num2;
            printf("\n%d - %d = %d\n", num1, num2, result);
            break;
            
        case 3: // Multiplication
            result = num1 * num2;
            printf("\n%d * %d = %d\n", num1, num2, result);
            break;
            
        case 4: // Division
            if(num2 == 0)
            {
                printf("\nCan't Divide by Zero!\n");
                exit(0);
            }
            else
            {
                result = num1 / num2;
                printf("\n%d / %d = %d\n", num1, num2, result);
            }
            break;
            
        case 5: // Modulus
            if(num2 == 0)
            {
                printf("\nCan't Divide by Zero!\n");
                exit(0);
            }
            else
            {
                result = num1 % num2;
                printf("\n%d Mod %d = %d\n", num1, num2, result);
            }
            break;
            
        default: // Invalid Choice
            printf("\nInvalid choice. Please choose from the options provided.\n");
    }

    return 0;
}