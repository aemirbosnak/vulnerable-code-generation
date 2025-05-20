//FormAI DATASET v1.0 Category: Memory management ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Happy Memory Management Program!\n");
    printf("Let's allocate some memory to store happy thoughts!\n");

    int* happy_arr = (int*) malloc(5 * sizeof(int));

    if (happy_arr == NULL)
    {
        printf("Oops! There was an error allocating memory for happy thoughts.\n");
        printf("Please try again later and have a nice day!\n");
        return -1;
    }

    printf("Hooray! We have successfully allocated memory for happy thoughts!\n");

    int i;
    for (i = 0; i < 5; i++)
    {
        printf("Enter a happy thought to store in memory: ");
        scanf("%d", &happy_arr[i]);
    }

    printf("\nHere are the happy thoughts you stored in memory:\n");

    for (i = 0; i < 5; i++)
    {
        printf("%d\n", happy_arr[i]);
    }

    printf("\nLet's reallocate memory to store even more happy thoughts!\n");

    int* more_happy_arr = (int*) realloc(happy_arr, 10 * sizeof(int));

    if (more_happy_arr == NULL)
    {
        printf("Oh no! There was an error reallocating memory for more happy thoughts.\n");
        printf("Don't worry though, you can still cherish the happy thoughts you already stored!\n");
        return -1;
    }

    printf("Yay! We have successfully reallocated memory to store more happy thoughts!\n");

    for (i = 5; i < 10; i++)
    {
        printf("Enter another happy thought to store in memory: ");
        scanf("%d", &more_happy_arr[i]);
    }

    printf("\nHere are all the happy thoughts you stored in memory:\n");

    for (i = 0; i < 10; i++)
    {
        printf("%d\n", more_happy_arr[i]);
    }

    printf("\nLet's free up the memory we allocated so we can spread more happiness in the future!\n");

    free(more_happy_arr);

    printf("Thank you for using the Happy Memory Management Program!\n");
    printf("Remember to always stay positive and keep those happy thoughts flowing!\n");

    return 0;
}