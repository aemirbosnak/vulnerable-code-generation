//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: systematic
#include<stdio.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 1000

typedef struct {
    int weight;
    int value;
} Item;

void display_items(int n, Item items[]) {
    printf("------------------\n");
    printf("Items        || Weight || Value\n");
    printf("------------------\n");
    for(int i = 0; i < n; i++) {
        printf("Item %2d      || %4d   || %4d\n", i+1, items[i].weight, items[i].value);
    }
    printf("------------------\n\n");
}

double get_max_profit(int n, Item items[], int capacity) {
    double max_profit = 0.0;
    int current_weight = 0;
    
    // Sort items by value per unit weight in descending order
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            double value_per_unit_weight_i = (double) items[i].value / items[i].weight;
            double value_per_unit_weight_j = (double) items[j].value / items[j].weight;
            if(value_per_unit_weight_i < value_per_unit_weight_j) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    // Select items greedily
    for(int i = 0; i < n; i++) {
        if(current_weight + items[i].weight <= capacity) {
            max_profit += items[i].value;
            current_weight += items[i].weight;
        } else {
            int remaining_capacity = capacity - current_weight;
            double profit = items[i].value * ((double) remaining_capacity / items[i].weight);
            max_profit += profit;
            break;
        }
    }
    return max_profit;
}

int main() {
    Item items[MAX_ITEMS];
    int n, capacity;
    
    printf("Enter the number of items (Maximum %d) : ", MAX_ITEMS);
    scanf("%d", &n);
    
    if(n > MAX_ITEMS) {
        printf("Number of items exceeds the maximum limit!\n");
        return 0;
    }
    
    printf("Enter the maximum capacity of the knapsack (Maximum %d) : ", MAX_CAPACITY);
    scanf("%d", &capacity);
    
    if(capacity > MAX_CAPACITY) {
        printf("Capacity exceeds the maximum limit!\n");
        return 0;
    }
    
    printf("\nEnter the weight and value of each item : \n");
    for(int i = 0; i < n; i++) {
        printf("\nItem %d : \n", i+1);
        printf("Weight : ");
        scanf("%d", &items[i].weight);
        printf("Value : ");
        scanf("%d", &items[i].value);
    }
    
    display_items(n, items);
    
    double max_profit = get_max_profit(n, items, capacity);
    
    printf("\nMaximum profit that can be obtained using greedy algorithm : %.2lf\n", max_profit);
    
    return 0;
}