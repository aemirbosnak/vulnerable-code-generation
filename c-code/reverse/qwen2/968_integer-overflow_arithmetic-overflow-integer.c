#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_bags;
    int min_weight, max_weight;

    printf("Enter the number of bags: ");
    scanf("%d", &num_bags);

    printf("Enter the minimum bag weight: ");
    scanf("%d", &min_weight);

    printf("Enter the maximum bag weight: ");
    scanf("%d", &max_weight);

    srand(time(0));

    for (int i = 0; i < num_bags; i++) {
        int weight = rand() % (max_weight - min_weight + 1) + min_weight;
        printf("Bag %d weighs %d kg\n", i + 1, weight);
    }

    return 0;
}
