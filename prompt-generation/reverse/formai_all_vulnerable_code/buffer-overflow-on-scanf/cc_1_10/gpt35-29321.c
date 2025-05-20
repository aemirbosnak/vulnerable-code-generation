//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Donald Knuth
//---------------------------------------------
//A Greedy Algorithm Example Program in C
//Using Donald Knuth's Style
//By Your Name
//Date: Today's Date
//---------------------------------------------

#include <stdio.h>

int main()
{
    int n, i, j, temp, max_value;
    int weights[50], values[50], selected[50];
    float capacity, total_value = 0;

    //Read in number of items and maximum capacity from user
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%f", &capacity);

    //Read in the weight and value of each item
    printf("Enter the weight and value of each item:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d%d", &weights[i], &values[i]);
        selected[i] = 0; //initialize all items as not selected
    }

    //Sort the items based on their value/weight ratio (in non-increasing order)
    for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
            if(((float)values[i]/weights[i]) < ((float)values[j]/weights[j]))
            {
                temp = values[i];
                values[i] = values[j];
                values[j] = temp;
                temp = weights[i];
                weights[i] = weights[j];
                weights[j] = temp;
            }

    //Select items greedily until the knapsack is full
    for(i=0; i<n; i++)
    {
        if(capacity < weights[i])
            break;
        selected[i] = 1;
        total_value += values[i];
        capacity -= weights[i];
    }

    //If the knapsack is not yet full, add fractional items
    if(i<n)
    {
        selected[i] = capacity/weights[i];
        total_value += selected[i]*values[i];
    }

    //Print out the selected items and their total value
    printf("Selected items:\n");
    for(i=0; i<n; i++)
        if(selected[i])
            printf("%d ", i+1);
    printf("\nTotal value: %.2f\n", total_value);

    return 0;
}