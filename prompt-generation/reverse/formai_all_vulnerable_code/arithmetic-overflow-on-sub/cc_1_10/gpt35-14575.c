//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: automated
#include<stdio.h>
#include<stdlib.h>

#define MAX_VAL 100

void GreedyAlgorithmMin(int vals[], int size, int targetSum)
{
    int i, j, tempSum = 0, maxPossibleIndex = -1;

    if (vals[0] > targetSum)
    {
        printf("The target sum cannot be achieved with any combination\n");
        return;
    }

    printf("The values chosen are : ");

    while (tempSum != targetSum)
    {
        for (i = maxPossibleIndex + 1; i < size; i++)
        {
            if (tempSum + vals[i] <= targetSum)
                maxPossibleIndex = i;
            else
                break;
        }

        tempSum += vals[maxPossibleIndex];
        printf("%d ", vals[maxPossibleIndex]);
    }
}

void GreedyAlgorithmMax(int vals[], int size, int targetSum)
{
    int i, j, tempSum = 0, maxPossibleIndex = -1;

    if (vals[size - 1] < targetSum)
    {
        printf("The target sum cannot be achieved with any combination\n");
        return;
    }

    printf("The values chosen are : ");

    while (tempSum != targetSum)
    {
        for (i = size - 1 - maxPossibleIndex; i >= 0; i--)
        {
            if (tempSum + vals[i] >= targetSum)
                maxPossibleIndex = size - 1 - i;
            else
                break;
        }

        tempSum += vals[size - 1 - maxPossibleIndex];
        printf("%d ", vals[size - 1 - maxPossibleIndex]);
    }
}

int main()
{
    int i, size, targetSum, vals[MAX_VAL], choice;
    printf("Enter the number of values : ");
    scanf("%d", &size);
    printf("Enter the values : ");
    for (i = 0; i < size; i++)
        scanf("%d", &vals[i]);
    printf("Enter the target sum : ");
    scanf("%d", &targetSum);
    printf("Choose the type of Greedy Algorithm to use:\n");
    printf("1. Minimum values that make up the target sum\n");
    printf("2. Maximum values that make up the target sum\n");
    printf("Enter choice : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        GreedyAlgorithmMin(vals, size, targetSum);
        break;
    case 2:
        GreedyAlgorithmMax(vals, size, targetSum);
        break;
    default:
        printf("Invalid choice\n");
    }

    return 0;
}