//FormAI DATASET v1.0 Category: Math exercise ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int n, i, j, temp, choice;
    float result = 0;

    srand(time(0));
    printf("How many numbers do you want to generate?\n");
    scanf("%d", &n);
    int arr[n];

    printf("Choose the type of math operation: \n");
    printf("1. Addition \n2. Subtraction \n3. Multiplication \n4. Division \n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            for(i=0; i<n; i++)
            {
                arr[i] = rand() % 100;
                result += arr[i];   
            }
            printf("The sum of %d numbers is %0.2f", n, result);
            break;

        case 2:
            for(i=0; i<n; i++)
            {
                arr[i] = rand() % 100;
                if(i == 0)
                    result = arr[i];
                else
                    result -= arr[i];
            }
            printf("The difference of %d numbers is %0.2f", n, result);
            break;

        case 3:
            for(i=0; i<n; i++)
            {
                arr[i] = rand() % 10;
                if(i == 0)
                    result = arr[i];
                else
                    result *= arr[i];
            }
            printf("The product of %d numbers is %0.2f", n, result);
            break;

        case 4:
            for(i=0; i<n; i++)
            {
                arr[i] = rand() % 100 + 1;
                if(i == 0)
                    result = arr[i];
                else
                    result /= arr[i];
            }
            printf("The quotient of %d numbers is %0.2f", n, result);
            break;

        default:
            printf("Invalid choice! Please choose again.");
    }

    return 0;
}