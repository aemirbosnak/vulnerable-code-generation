//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    float value;
    float weight;
    float value_per_weight;
} Gem;

void calculate_value_per_weight(Gem* gems, int n) {
    for (int i = 0; i < n; i++) {
        gems[i].value_per_weight = gems[i].value / gems[i].weight;
    }
}

int compare_gems(const void* a, const void* b) {
    Gem* gem1 = (Gem*)a;
    Gem* gem2 = (Gem*)b;
    return (gem1->value_per_weight > gem2->value_per_weight) ? -1 : 1; // Sort in descending order
}

float maximum_value(Gem* gems, int n, float capacity) {
    qsort(gems, n, sizeof(Gem), compare_gems);
    
    float total_value = 0.0;
    for (int i = 0; i < n; i++) {
        if (capacity > 0 && gems[i].weight <= capacity) {
            total_value += gems[i].value;
            capacity -= gems[i].weight;
            printf("Taking full gem %d: value = %.2f, weight = %.2f\n", gems[i].id, gems[i].value, gems[i].weight);
        } else if (capacity > 0) {
            total_value += gems[i].value_per_weight * capacity;
            printf("Taking fraction of gem %d: value = %.2f, weight = %.2f\n", gems[i].id, gems[i].value_per_weight * capacity, capacity);
            capacity = 0; // No more capacity left
        }
    }
    return total_value;
}

int main() {
    int n;
    float capacity;

    printf("Enter the number of gems: ");
    scanf("%d", &n);

    Gem* gems = malloc(n * sizeof(Gem));
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of gem %d: ", i + 1);
        scanf("%f %f", &gems[i].value, &gems[i].weight);
        gems[i].id = i + 1; // Assign an ID to each gem
    }

    printf("Enter the weight capacity of the treasure bag: ");
    scanf("%f", &capacity);

    calculate_value_per_weight(gems, n);
    float max_value = maximum_value(gems, n, capacity);

    printf("Maximum value collected: %.2f\n", max_value);

    free(gems);
    return 0;
}