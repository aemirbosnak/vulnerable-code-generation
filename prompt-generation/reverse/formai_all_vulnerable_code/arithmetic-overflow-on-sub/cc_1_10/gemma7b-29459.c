//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int items[n];
    printf("Enter the weights of each item: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &items[i]);
    }

    int total_weight = 0;
    for (int i = 0; i < n; i++)
    {
        total_weight += items[i];
    }

    int bag_size = 0;
    printf("Enter the size of the bag: ");
    scanf("%d", &bag_size);

    int capacity = bag_size;

    int bags[n];
    for (int i = 0; i < n; i++)
    {
        bags[i] = 0;
    }

    int i = 0;
    while (total_weight - bags[i] >= capacity && i < n)
    {
        bags[i]++;
        total_weight -= items[i];
        i++;
    }

    int total_value = 0;
    for (int i = 0; i < n; i++)
    {
        total_value += items[i] * bags[i];
    }

    printf("The total value of the items is: %d", total_value);
}