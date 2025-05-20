//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Function to sort the items by weight
int comparator(const void *p, const void *q)
{
    int a = *(const int *)p;
    int b = *(const int *)q;
    return b - a;
}

// Function to calculate the maximum amount of loot
float max_loot(int weight[], int value[], int n, int capacity)
{
    float loot = 0; // Set the initial loot as 0
    int current_weight = 0; // Set the current weight as 0

    // Sort the items by weight in decreasing order
    qsort(weight, n, sizeof(int), comparator);

    // Loop through each item until the capacity is full
    for (int i = 0; i < n; i++)
    {
        if (current_weight + weight[i] <= capacity)
        {
            // If there is still capacity for the item, add to the current loot
            current_weight += weight[i];
            loot += value[i];
        }
        else
        {
            // If there is not enough capacity for the item, calculate the fraction of it we can take
            int remaining_capacity = capacity - current_weight;
            float fraction = (float)remaining_capacity / weight[i];
            current_weight += remaining_capacity;
            loot += fraction * value[i];
            break;
        }
    }

    return loot; // Return the maximum amount of loot
}

int main()
{
    int n; // Number of items
    int capacity; // Capacity of the bag

    printf("Welcome to the Greedy Algorithms Program!\n");
    printf("Please enter the number of items you have: ");
    scanf("%d", &n);
    printf("Please enter the capacity of your bag: ");
    scanf("%d", &capacity);

    // Allocate memory for weight and value arrays
    int* weight = (int*)malloc(n * sizeof(int));
    int* value = (int*)malloc(n * sizeof(int));

    // Input the weight and value of each item
    for (int i = 0; i < n; i++)
    {
        printf("Enter the weight and value of item %d: ", i+1);
        scanf("%d %d", &weight[i], &value[i]);
    }

    // Calculate the maximum amount of loot
    float max = max_loot(weight, value, n, capacity);

    printf("The maximum amount of loot you can get is: $%.2f", max);

    // Free the allocated memory
    free(weight);
    free(value);

    return 0;
}