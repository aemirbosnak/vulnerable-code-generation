//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: curious
#include <stdio.h>

int main() {
    int n, i, j, temp;
    int weight[100], value[100], capacity;
    float ratio[100], maxValue = 0;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("\nEnter the weights and values of each item:\n");
    for(i = 0; i < n; ++i){
        printf("Item %d:\n", i + 1);
        printf("Weight: ");
        scanf("%d", &weight[i]);
        printf("Value: ");
        scanf("%d", &value[i]);
        ratio[i] = (float)value[i] / (float)weight[i];
    }

    printf("\nEnter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    for(i = 0; i < n; ++i){
        for(j = i+1; j < n; ++j){
            if(ratio[i] < ratio[j]){
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = value[j];
                value[j] = value[i];
                value[i] = temp;
            }
        }
    }

    for(i = 0; i < n; ++i){
        if(weight[i] > capacity)
            break;
        else{
            maxValue += value[i];
            capacity -= weight[i];
        }
    }

    if(i < n)
        maxValue += (float)capacity * ratio[i];

    printf("\nMaximum value: %f", maxValue);

    return 0;
}