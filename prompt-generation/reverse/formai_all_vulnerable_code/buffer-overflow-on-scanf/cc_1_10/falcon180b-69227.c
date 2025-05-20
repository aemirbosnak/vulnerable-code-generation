//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_NUM 1000
#define MIN_NUM -1000

int main()
{
    int num1, num2, result;
    int choice;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate two random numbers
    num1 = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
    num2 = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;

    printf("Two random numbers between %d and %d:\n", MIN_NUM, MAX_NUM);
    printf("Number 1: %d\n", num1);
    printf("Number 2: %d\n", num2);

    printf("\nEnter the arithmetic operation you want to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            result = num1 + num2;
            printf("\nResult: %d", result);
            break;

        case 2:
            result = num1 - num2;
            printf("\nResult: %d", result);
            break;

        case 3:
            result = num1 * num2;
            printf("\nResult: %d", result);
            break;

        case 4:
            if(num2 == 0)
            {
                printf("\nCannot divide by zero!");
            }
            else
            {
                result = num1 / num2;
                printf("\nResult: %d", result);
            }
            break;

        default:
            printf("\nInvalid choice!");
    }

    return 0;
}