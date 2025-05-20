//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: genious
#include <stdio.h>

// Function to sort array in ascending order
void sort(int arr[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main()
{
    int i, n, maxWeight;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int values[n], weights[n], order[n];

    for (i = 0; i < n; i++) {
        printf("Enter the weight of item %d: ", i + 1);
        scanf("%d", &weights[i]);
        printf("Enter the value of item %d: ", i + 1);
        scanf("%d", &values[i]);
        order[i] = i + 1;
    }

    printf("Enter the maximum weight: ");
    scanf("%d", &maxWeight);

    // Sort items in decreasing order of value/weight ratio
    float ratios[n];
    for (i = 0; i < n; i++)
        ratios[i] = (float) values[i] / weights[i];
    for (i = 0; i < n - 1; i++) {
        int j, max = i;
        for (j = i + 1; j < n; j++)
            if (ratios[max] < ratios[j])
                max = j;
        float tempFloat = ratios[i];
        ratios[i] = ratios[max];
        ratios[max] = tempFloat;

        int tempInt = order[i];
        order[i] = order[max];
        order[max] = tempInt;
    }

    // Greedy algorithm to fill knapsack
    int currentWeight = 0;
    float currentValue = 0;
    for (i = 0; i < n; i++) {
        if (currentWeight + weights[order[i]-1] <= maxWeight) {
            currentWeight += weights[order[i]-1];
            currentValue += values[order[i]-1];
        }
        else {
            int remainingWeight = maxWeight - currentWeight;
            float portionOfValue = (float) remainingWeight / weights[order[i]-1];
            currentValue += portionOfValue * values[order[i]-1];
            break;
        }
    }

    printf("\nThe maximum value that can be obtained is: %f\n", currentValue);

    return 0;
}