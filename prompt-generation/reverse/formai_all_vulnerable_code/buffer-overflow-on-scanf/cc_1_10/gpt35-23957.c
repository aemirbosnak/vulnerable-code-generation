//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: calm
#include <stdio.h>

int main() {
    int num_items, max_weight, i, j;
    float weight[100], value[100], ratio[100], temp;
    float knapsack_weight = 0, knapsack_value = 0, fraction;
    
    // Input number of items and maximum weight for the knapsack
    printf("Enter number of items: ");
    scanf("%d", &num_items);
    printf("Enter maximum weight of knapsack: ");
    scanf("%d", &max_weight);
    
    // Input weights and values of items
    for(i=0;i<num_items;i++) {
        printf("Enter weight and value of item %d: ", i+1);
        scanf("%f %f", &weight[i], &value[i]);
        ratio[i] = value[i] / weight[i];  //Calculate value-to-weight ratio
    }
    
    //Sort items based on their value-to-weight ratio in descending order using Bubble Sort
    for(i=0;i<num_items-1;i++) {
        for(j=0;j<num_items-i-1;j++) {
            if(ratio[j] < ratio[j+1]) {
                temp = ratio[j];
                ratio[j] = ratio[j+1];
                ratio[j+1] = temp;
                temp = weight[j];
                weight[j] = weight[j+1];
                weight[j+1] = temp;
                temp = value[j];
                value[j] = value[j+1];
                value[j+1] = temp;
            }
        }
    }
    
    //Fill knapsack with items with highest value-to-weight ratio until it is full
    for(i=0;i<num_items;i++) {
        if(knapsack_weight + weight[i] <= max_weight) {
            knapsack_weight += weight[i];
            knapsack_value += value[i];
        } else {    //Add fractional item if knapsack is not full
            fraction = (max_weight - knapsack_weight) / weight[i];
            knapsack_weight += fraction * weight[i];
            knapsack_value += fraction * value[i];
            break;
        }
    }
    
    //Print knapsack weight and value
    printf("The maximum value that can be obtained is %.2f with a weight of %.2f\n", knapsack_value, knapsack_weight);
    
    return 0;
}