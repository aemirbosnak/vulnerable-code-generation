//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_BAGGAGE 100
#define MAX_WEIGHT 50

int main()
{
    int bags[MAX_BAGGAGE], num_bags, i, total_weight = 0;
    
    // Get number of bags from user
    printf("How many bags need handling? ");
    scanf("%d", &num_bags);
    
    // Get weight of each bag from user
    for(i = 0; i < num_bags; i++)
    {
        printf("Enter weight of bag #%d: ", i+1);
        scanf("%d", &bags[i]);
        
        // Check if bag weight exceeds maximum weight limit
        if(bags[i] > MAX_WEIGHT)
        {
            printf("Bag weight exceeds maximum weight limit. Please remove the excess weight.\n");
            exit(0);
        }
        
        // Update total weight
        total_weight += bags[i];
    }
    
    // Check if total weight exceeds maximum weight limit
    if(total_weight > (MAX_WEIGHT * MAX_BAGGAGE))
    {
        printf("Total weight of bags exceeds maximum weight limit. Please remove some bags.\n");
        exit(0);
    }
    
    // Sort bags in ascending order of weight using bubble sort algorithm
    int j, temp;
    for(i = 0; i < num_bags - 1; i++)
    {
        for(j = 0; j < num_bags - i - 1; j++)
        {
            if(bags[j] > bags[j+1])
            {
                temp = bags[j];
                bags[j] = bags[j+1];
                bags[j+1] = temp;
            }
        }
    }
    
    // Print details of bags and their weights in sorted order
    printf("\nDetails of bags and their weights in sorted order:\n");
    for(i = 0; i < num_bags; i++)
    {
        printf("Bag #%d - weight: %d kg\n", i+1, bags[i]);
    }
    
    return 0;
}