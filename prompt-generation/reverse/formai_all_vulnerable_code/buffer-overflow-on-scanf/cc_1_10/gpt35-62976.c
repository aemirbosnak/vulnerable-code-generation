//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: multivariable
#include<stdio.h>

//define struct for item
struct Item
{
    int value;
    int weight;
}items[20];

//define struct for knapsack
struct Knapsack
{
    int capacity;
    int filled_wt;
    int filled_val;
}knapsack;

//function to sort items based on value/weight ratio
void sort_items(struct Item items[], int n)
{
    int i,j;
    float ratio_i, ratio_j;
    struct Item temp;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            ratio_i = (float)items[i].value/items[i].weight;
            ratio_j = (float)items[j].value/items[j].weight;
            if(ratio_i < ratio_j)
            {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }   
        }
    }
}

//function to implement greedy algorithm
void greedy_algorithm(struct Item items[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(knapsack.filled_wt + items[i].weight <= knapsack.capacity)
        {
            knapsack.filled_wt += items[i].weight;
            knapsack.filled_val += items[i].value;
        }
        else
        {
            break;
        }
    }
    printf("\nTotal value in knapsack: %d", knapsack.filled_val);
}

//main function to demonstrate the program
void main()
{
    int i, n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("\nEnter the items with their values and weights:\n");

    //getting input for items
    for(i=0; i<n; i++)
    {
        printf("Item %d:\n", i+1);
        printf("Value: ");
        scanf("%d", &items[i].value);
        printf("Weight: ");
        scanf("%d", &items[i].weight);
    }

    //getting input for knapsack
    printf("\nEnter the knapsack capacity: ");
    scanf("%d", &knapsack.capacity);

    //sorting items based on value/weight ratio
    sort_items(items, n);

    //implementing greedy algorithm
    greedy_algorithm(items, n);
}