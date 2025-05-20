//FormAI DATASET v1.0 Category: Math exercise ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, num3, num4, num5, sum, count;
    float average;
    srand(time(NULL));

    printf("Welcome to the Math Exercise Program!\n\n");
    printf("This program will generate five random numbers and ask you to find their sum and average.\n\n");
    
    for (count = 1; count <= 5; count++)
    {
        printf("Please enter a positive integer between 1 and 100: ");
        scanf("%d", &num1);
        while (num1 < 1 || num1 > 100)
        {
            printf("Invalid input! Please enter a positive integer between 1 and 100: ");
            scanf("%d", &num1);
        }
        
        switch (count)
        {
            case 1:
                num1 = rand() % 100 + 1;
                printf("The 1st number is: %d\n", num1);
                break;
            case 2:
                num2 = rand() % 100 + 1;
                printf("The 2nd number is: %d\n", num2);
                break;
            case 3:
                num3 = rand() % 100 + 1;
                printf("The 3rd number is: %d\n", num3);
                break;
            case 4:
                num4 = rand() % 100 + 1;
                printf("The 4th number is: %d\n", num4);
                break;
            case 5:
                num5 = rand() % 100 + 1;
                printf("The 5th number is: %d\n", num5);
                break;
        }
    }

    sum = num1 + num2 + num3 + num4 + num5;
    average = (float)sum / 5;

    printf("\nThe sum of the five numbers is: %d\n", sum);
    printf("The average of the five numbers is: %.2f\n", average);
    printf("\nThank you for using the Math Exercise Program!\n");

    return 0;
}