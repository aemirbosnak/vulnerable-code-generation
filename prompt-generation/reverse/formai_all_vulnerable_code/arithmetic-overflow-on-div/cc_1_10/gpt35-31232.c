//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: introspective
#include <stdio.h>

int main() {
    int n, i, j, temp, sum = 0;
    int weights[100], values[100], ratios[100];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weight and value of each item: \n");
    for(i=0; i<n; i++) {
        printf("Item %d - Weight: ", i+1);
        scanf("%d", &weights[i]);
        printf("Item %d - Value: ", i+1);
        scanf("%d", &values[i]);
        ratios[i] = values[i] / weights[i];
    }

    // Using Bubble Sort to sort the items based on their value-to-weight ratio (Descending order)
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(ratios[j] < ratios[j+1]) {
                temp = ratios[j];
                ratios[j] = ratios[j+1];
                ratios[j+1] = temp;

                temp = weights[j];
                weights[j] = weights[j+1];
                weights[j+1] = temp;

                temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
            }
        }
    }

    // Using Greedy algorithm to select the items based on their value-to-weight ratio
    for(i=0; i<n; i++) {
        if(weights[i] <= sum) {
            sum += weights[i];
        } else {
            int remaining = sum - weights[i];
            sum += (remaining * ratios[i]);
            break;
        }
    }

    printf("The maximum total value that can be put in a knapsack of capacity %d is %d", sum, sum);
    return 0;
}