//FormAI DATASET v1.0 Category: Recursive ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_NUM 10

void *factorial(void *arg);
int calculateFactorial(int num);

int main()
{
    int input[MAX_NUM];
    pthread_t threads[MAX_NUM];

    /* Get user input for calculation */
    printf("Enter up to %d numbers to calculate factorial: ", MAX_NUM);
    for (int i = 0; i < MAX_NUM; i++)
    {
        scanf("%d", &input[i]);
        /* Break loop if input is negative */
        if (input[i] < 0)
        {
            printf("Invalid input, program will terminate\n");
            exit(1);
        }
    }

    /* Create threads for factorial calculation */
    for (int i = 0; i < MAX_NUM; i++)
    {
        pthread_create(&threads[i], NULL, factorial, &input[i]);
    }

    /* Wait for all threads to finish */
    for (int i = 0; i < MAX_NUM; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("All factorial calculations finished!\n");

    return 0;
}

void *factorial(void *arg)
{
    int num = *((int *)arg);
    printf("Calculating factorial of %d\n", num);

    /* Calculate factorial of input number */
    int result = calculateFactorial(num);

    printf("Factorial of %d is %d\n", num, result);

    pthread_exit(0);
}

int calculateFactorial(int num)
{
    if (num <= 1)
    {
        return 1;
    }
    else
    {
        return num * calculateFactorial(num - 1);
    }
}