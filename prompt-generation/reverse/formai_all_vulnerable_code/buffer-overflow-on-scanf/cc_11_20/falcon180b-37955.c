//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, k;
    int arr[10][10];
    int count = 0;
    int temp;
    int sum = 0;
    int max = 0;
    int min = 100;
    int avg;
    char ch;
    int x, y;
    int choice;
    int flag = 0;
    int count2 = 0;

    srand(time(NULL));

    printf("Welcome to the Medieval Weather Simulation!\n");
    printf("Enter 1 to generate random weather or 2 to input your own weather data.\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                temp = rand() % 31 + 1;
                arr[i][j] = temp;
                sum += temp;
            }
        }
        avg = sum / 100;
        printf("The average temperature for the kingdom is %d degrees.\n", avg);
    }
    else if (choice == 2)
    {
        printf("Enter the weather data (1-31) for each day:\n");
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                scanf("%d", &arr[i][j]);
                sum += arr[i][j];
            }
        }
        avg = sum / 100;
        printf("The average temperature for the kingdom is %d degrees.\n", avg);
    }

    printf("Would you like to see the weather forecast? (y/n)\n");
    scanf(" %c", &ch);

    if (ch == 'y' || ch == 'Y')
    {
        printf("Day 1: ");
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                if (arr[i][j] == max)
                {
                    printf("*");
                }
                else if (arr[i][j] == min)
                {
                    printf("#");
                }
                else
                {
                    printf("%d", arr[i][j]);
                }
            }
            printf("\n");
        }
    }

    return 0;
}