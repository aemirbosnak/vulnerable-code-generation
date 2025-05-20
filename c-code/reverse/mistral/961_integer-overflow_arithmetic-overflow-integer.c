#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_WEIGHT 1000
#define MIN_WEIGHT 1
#define MAX_PLANE_WEIGHT 800

int main() {
    int num_bags, i, plane_weight = 0;
    int bags[MAX_BAGS];

    printf("Enter the number of bags: ");
    scanf("%d", &num_bags);

    srand(time(NULL));

    for (i = 0; i < num_bags; ++i) {
        bags[i] = rand() % (MAX_WEIGHT - MIN_WEIGHT + 1) + MIN_WEIGHT;
        printf("Bag %d: %d weight units\n", i + 1, bags[i]);
        plane_weight += bags[i];

        if (plane_weight > MAX_PLANE_WEIGHT) {
            printf("Exceeded plane weight limit. Removing bag %d.\n", i + 1);
            --num_bags;
            break;
        }
    }

    printf("Remaining bags after removing overweight bags:\n");
    for (i = 0; i < num_bags; ++i) {
        printf("Bag %d: %d weight units\n", i + 1, bags[i]);
    }

    return 0;
}
