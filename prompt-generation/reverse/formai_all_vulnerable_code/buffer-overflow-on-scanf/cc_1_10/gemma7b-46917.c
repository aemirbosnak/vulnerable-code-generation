//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void greedy_algorithm()
{
    int i, j, n, current_size = 0, maximum_size = 0, arr[MAX], bag[MAX];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weights of each item: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the capacities of each bag: ");
    for (i = 0; i < MAX; i++)
    {
        bag[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (current_size + arr[i] <= bag[j])
            {
                current_size += arr[i];
                bag[j]++;
                break;
            }
        }
    }

    printf("The maximum size of each bag is: ");
    for (i = 0; i < MAX; i++)
    {
        printf("%d ", bag[i]);
    }

    printf("\n");
}

int main()
{
    greedy_algorithm();

    return 0;
}