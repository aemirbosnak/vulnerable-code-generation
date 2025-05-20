//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>

// function to compare the two values and sort in descending order
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

int main() {
    int n, i, j;
    printf("Enter the number of items:");
    scanf("%d", &n);
    int values[n], weights[n], knapsack[n], capacity;

    // taking the input from the user
    printf("Enter the value and weight of each item:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d:\n", i+1);
        printf("  Value: ");
        scanf("%d", &values[i]);
        printf("  Weight: ");
        scanf("%d", &weights[i]);
    }

    // taking the input of capacity of knapsack
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);

    // sorting the items based on their value per unit weight
    double val_per_wt[n];
    for(i=0; i<n; i++) {
        val_per_wt[i] = (double)values[i] / (double)weights[i];     // finding the value per unit weight
        knapsack[i] = 0;                                            // initializing the knapsack array with 0
    }
    qsort(val_per_wt, n, sizeof(double), cmpfunc);                 // sorting the items

    // filling the knapsack with the items in the order of their value per unit weight
    double net_value = 0;
    for(i=0; i<n; i++) {
        int item_index = -1;
        for(j=0; j<n; j++) {                                        // finding the index of the item in the original array
            if(val_per_wt[i] == (double)values[j]/(double)weights[j]) {
                item_index = j;
                break;
            }
        }
        if(item_index != -1 && knapsack[item_index] == 0 && (capacity-weights[item_index])>=0) {    // checking if the item is not already added and there is enough capacity in the knapsack
            capacity -= weights[item_index];
            knapsack[item_index] = 1;
            net_value += values[item_index];
        }
    }

    // printing the result
    printf("\nItems in the knapsack are:\n");
    for(i=0; i<n; i++) {
        if(knapsack[i] == 1) {
            printf("Item %d (value=%d, weight=%d)\n", i+1, values[i], weights[i]);
        }
    }
    printf("\nThe maximum net value of items in the knapsack is: %0.2lf", net_value);

    return 0;
}