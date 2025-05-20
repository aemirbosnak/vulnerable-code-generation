//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: minimalist
#include <stdio.h>

int main() {
    int n, w;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the maximum weight capacity: ");
    scanf("%d", &w);
    int value[n], weight[n];
    float ratio[n], totalValue = 0, totalWeight = 0;
    int i, j, temp;

    // Take user input for values and weights of the items
    for(i=0; i<n; i++) {
        printf("Enter the value and weight of item %d: ", i+1);
        scanf("%d %d",&value[i], &weight[i]);
        ratio[i] = (float)value[i] / weight[i];
    }

    // Sort the items in decreasing order of value/weight ratio using Bubble sort
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(ratio[j] < ratio[j+1]) {
                // Swap the value/weight ratio
                temp = ratio[j];
                ratio[j] = ratio[j+1];
                ratio[j+1] = temp;

                // Swap the value
                temp = value[j];
                value[j] = value[j+1];
                value[j+1] = temp;

                // Swap the weight
                temp = weight[j];
                weight[j] = weight[j+1];
                weight[j+1] = temp;
            }
        }
    }

    // Take as many items as possible until the max weight is reached
    for(i=0; i<n; i++) {
        if(totalWeight + weight[i] <= w) {
            totalValue += value[i];
            totalWeight += weight[i];
        }
        else {
            float remaining = w - totalWeight;
            totalValue += remaining * ratio[i];
            break;
        }
    }

    printf("Maximum value that can be obtained = %.2f\n", totalValue);

    return 0;
}