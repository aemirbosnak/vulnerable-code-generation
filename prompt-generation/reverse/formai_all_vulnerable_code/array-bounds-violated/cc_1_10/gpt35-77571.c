//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, temp, cost = 0;
    printf("Enter number of items: ");
    scanf("%d", &n);
    int weights[n], values[n];

    printf("Enter weight and value of each item:\n");

    for(i=0; i<n; i++) {
        printf("Item %d: ", i+1);
        scanf("%d %d", &weights[i], &values[i]);
    }

    printf("Enter knapsack weight capacity: ");
    int capacity; 
    scanf("%d", &capacity);

    float ratio[n];
    for(i=0; i<n; i++) {
        ratio[i] = (float) values[i]/weights[i];
    }

    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(ratio[i] < ratio[j]) {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = values[j];
                values[j] = values[i];
                values[i] = temp;

                temp = weights[j];
                weights[j] = weights[i];
                weights[i] = temp;
            }
        }
    }

    i = 0;
    while(capacity > 0) {
        if(weights[i] <= capacity) {
            cost += values[i];
            capacity -= weights[i];
        } else {
             int fraction = capacity/weights[i];
            cost += fraction * values[i];
            capacity -= weights[i] * fraction;
        }
        i++;
    }

    printf("Maximum value of items that can be put into the knapsack = %d", cost);
    return 0;
}