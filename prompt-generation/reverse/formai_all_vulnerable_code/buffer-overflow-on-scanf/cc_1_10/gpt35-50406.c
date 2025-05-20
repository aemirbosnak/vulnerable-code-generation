//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// function to sort the looted items by their value
void sort(int *values, int *weights, int n)
{
    int i, j, temp;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (((float)values[j]/weights[j]) < ((float)values[j+1]/weights[j+1]))
            {
                temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
                temp = weights[j];
                weights[j] = weights[j+1];
                weights[j+1] = temp;
            }
        }
    }
}

int main()
{
    int n, capacity, i;
    printf("You are a survivor in a post-apocalyptic world, searching for valuable items to survive.\n");
    printf("Enter the number of items you have looted: ");
    scanf("%d", &n);
    int values[n], weights[n];
    printf("Enter the value and weight of each looted item: \n");
    for (i = 0; i < n; i++)
    {
        printf("Item %d: ", i+1);
        scanf("%d %d", &values[i], &weights[i]);
    }
    printf("Enter the maximum weight you can carry: ");
    scanf("%d", &capacity);
    sort(values, weights, n);

    int total_value = 0, current_weight = 0;
    for (i = 0; i < n; i++)
    {
        if (current_weight + weights[i] <= capacity)
        {
            current_weight += weights[i];
            total_value += values[i];
        }
        else
        {
            int remaining_capacity = capacity - current_weight;
            total_value += remaining_capacity * ((float)values[i]/weights[i]);
            break;
        }
    }
    printf("You have looted items worth %d coins.\n", total_value);
    return 0;
}