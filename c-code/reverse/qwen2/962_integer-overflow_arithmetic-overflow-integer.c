#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int num_bags;
    printf("Enter the number of bags: ");
    scanf("%d", &num_bags);

    int min_weight, max_weight;
    printf("Enter the minimum weight range (kg): ");
    scanf("%d", &min_weight);
    printf("Enter the maximum weight range (kg): ");
    scanf("%d", &max_weight);

    // Intentionally vulnerable to integer overflow
    int total_weight = num_bags * (max_weight - min_weight + 1);

    printf("Total weight of baggage: %d kg\n", total_weight);

    return 0;
}
