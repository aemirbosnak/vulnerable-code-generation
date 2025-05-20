//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;         // Item ID
    float value;   // Value of the item
    float weight;  // Weight of the item
    float ratio;   // Value-to-weight ratio
} Item;

// Function prototypes
void calculateRatios(Item items[], int count);
void swap(Item *a, Item *b);
void sortItems(Item items[], int count);
float fractionalKnapsack(Item items[], int count, float capacity);
void printItems(Item items[], int count);

int main() {
    int n;
    float capacity;

    printf("Welcome to the Fractional Knapsack Adventure!\n");
    printf("How many items do you want to consider? Enter a number: ");
    scanf("%d", &n);
    
    Item *items = (Item *)malloc(n * sizeof(Item));
    if(items == NULL) {
        fprintf(stderr, "Memory allocation failed! Exiting program.\n");
        return 1;
    }

    // Input items' values and weights
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d (format: value weight): ", i + 1);
        scanf("%f %f", &items[i].value, &items[i].weight);
        items[i].id = i + 1; // ID the item
    }

    printf("What is the maximum capacity of your knapsack? Enter a number: ");
    scanf("%f", &capacity);

    calculateRatios(items, n);
    sortItems(items, n);
    printf("\nItems sorted by value-to-weight ratio:\n");
    printItems(items, n);

    float maxValue = fractionalKnapsack(items, n, capacity);
    printf("\nMaximum value achievable in the knapsack: %.2f\n", maxValue);

    free(items);
    return 0;
}

// Function to calculate value-to-weight ratio for each item
void calculateRatios(Item items[], int count) {
    for (int i = 0; i < count; i++) {
        items[i].ratio = items[i].value / items[i].weight; // Calculate the ratio
    }
}

// Function to swap two items
void swap(Item *a, Item *b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort items based on their value-to-weight ratio using Bubble Sort
void sortItems(Item items[], int count) {
    for(int i = 0; i < count - 1; i++) {
        for(int j = 0; j < count - i - 1; j++) {
            if(items[j].ratio < items[j + 1].ratio) {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}

// Function to solve fractional knapsack problem
float fractionalKnapsack(Item items[], int count, float capacity) {
    float totalValue = 0.0;

    for (int i = 0; i < count; i++) {
        if (capacity > 0 && items[i].weight <= capacity) {
            // If the item can be fully included
            totalValue += items[i].value;
            capacity -= items[i].weight;
            printf("Including item %d (Weight: %.2f, Value: %.2f) - Added Full Value: %.2f\n", 
                    items[i].id, items[i].weight, items[i].value, items[i].value);
        } else if (capacity > 0) {
            // If the item can't be fully included, take the fraction
            float fraction = capacity / items[i].weight;
            totalValue += items[i].value * fraction;
            printf("Including item %d (Weight: %.2f, Value: %.2f) - Added Partial Value: %.2f\n", 
                    items[i].id, items[i].weight, items[i].value, items[i].value * fraction);
            capacity = 0; // Knapsack is full
        }
    }

    return totalValue;
}

// Function to print items and their details
void printItems(Item items[], int count) {
    printf("ID\tValue\tWeight\tRatio\n");
    for(int i = 0; i < count; i++) {
        printf("%d\t%.2f\t%.2f\t%.2f\n", items[i].id, items[i].value, items[i].weight, items[i].ratio);
    }
}