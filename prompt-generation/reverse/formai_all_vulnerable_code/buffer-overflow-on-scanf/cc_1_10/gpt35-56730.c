//FormAI DATASET v1.0 Category: Math exercise ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int num1, num2, choice, ans, response;
    double squareroot;
    
    srand(time(NULL)); //seed the random number generator
    
    do {
        num1 = rand() % 100; //generate a random number between 0 and 99
        num2 = rand() % 100; //generate another random number between 0 and 99
        
        printf("\n");
        printf("Choose an operation: \n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Square root\n");
        printf("6. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1: //addition
                ans = num1 + num2;
                printf("\n");
                printf("%d + %d = %d\n", num1, num2, ans);
                printf("\n");
                break;
                
            case 2: //subtraction
                ans = num1 - num2;
                printf("\n");
                printf("%d - %d = %d\n", num1, num2, ans);
                printf("\n");
                break;
                
            case 3: //multiplication
                ans = num1 * num2;
                printf("\n");
                printf("%d * %d = %d\n", num1, num2, ans);
                printf("\n");
                break;
                
            case 4: //division
                if (num2 == 0) //division by zero error
                {
                    printf("\n");
                    printf("Division by zero error!\n");
                    printf("\n");
                }
                else
                {
                    ans = num1 / num2;
                    printf("\n");
                    printf("%d / %d = %d\n", num1, num2, ans);
                    printf("\n");
                }
                break;
                
            case 5: //square root
                squareroot = sqrt(num1);
                printf("\n");
                printf("The square root of %d is %.2lf \n", num1, squareroot);
                printf("\n");
                break;
                
            case 6: //quit
                printf("\n");
                printf("Exiting program...\n");
                printf("\n");
                return 0;
                
            default: //invalid input
                printf("\n");
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
                printf("\n");
                break;
        }
        
        printf("Would you like to continue? (Enter 1 for Yes or 0 for No): ");
        scanf("%d", &response);
        
    } while (response != 0);
    
    return 0;
}