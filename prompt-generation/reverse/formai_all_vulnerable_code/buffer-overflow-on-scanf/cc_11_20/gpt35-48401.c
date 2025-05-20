//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: enthusiastic
// Welcome to the exciting world of Greedy Algorithms in C!

#include <stdio.h>

int main()
{
    int numItems, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &numItems);
    printf("Enter the maximum capacity: ");
    scanf("%d", &capacity);

    int weights[numItems], values[numItems];
    for(int i = 0; i < numItems; i++)
    {
        printf("Enter the weight for item %d: ", i+1);
        scanf("%d", &weights[i]);
        printf("Enter the value for item %d: ", i+1);
        scanf("%d", &values[i]);
    }

    // Implementing the Knapsack Problem using Greedy Algorithm
    float unitValues[numItems];
    for(int i = 0; i < numItems; i++)
    {
        unitValues[i] = (float)values[i] / (float)weights[i];
    }

    int sortedIndexes[numItems];
    for(int i = 0;i < numItems; i++)
    {
        sortedIndexes[i] = i;
    }
    for(int i = 0; i < numItems-1; i++)
    {
        for(int j = i+1; j < numItems; j++)
        {
            if(unitValues[i] < unitValues[j])
            {
                float tempValue = unitValues[i];
                unitValues[i] = unitValues[j];
                unitValues[j] = tempValue;

                int tempIndex = sortedIndexes[i];
                sortedIndexes[i] = sortedIndexes[j];
                sortedIndexes[j] = tempIndex;
            }
        }
    }

    int selectedItems[numItems+1], s = 0;
    for(int i = 0; i < numItems; i++)
    {
        if(capacity >= weights[sortedIndexes[i]])
        {
            selectedItems[s] = sortedIndexes[i];
            s++;
            capacity -= weights[sortedIndexes[i]];
        }
    }

    // Displaying the items selected
    if(s == 0)
    {
        printf("\nSorry, cannot select any items!\n");
    }
    else
    {
        printf("\nItems Selected: ");
        int totalValue = 0;
        for(int i = 0; i < s; i++)
        {
            printf("%d ", selectedItems[i]+1);
            totalValue += values[selectedItems[i]];
        }
        printf("\nTotal Value: %d\n", totalValue);
    }

    return 0;
}