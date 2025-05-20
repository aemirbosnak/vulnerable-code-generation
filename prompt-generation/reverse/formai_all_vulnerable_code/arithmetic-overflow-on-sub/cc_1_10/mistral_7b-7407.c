//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX_LOCATIONS 100

typedef struct {
    int location;
    int value;
} Location;

void swap(Location *a, Location *b) {
    Location temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(Location array[], int size) {
    int i, j, min_idx;

    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < size; j++) {
            if (array[j].value < array[min_idx].value) {
                min_idx = j;
            }
        }
        swap(&array[min_idx], &array[i]);
    }
}

int main() {
    Location locations[MAX_LOCATIONS];
    int num_locations, i, total_value = 0;

    scanf("%d", &num_locations);

    for (i = 0; i < num_locations; i++) {
        scanf("%d%d", &locations[i].location, &locations[i].value);
    }

    selection_sort(locations, num_locations);

    printf("The optimal route is:\n");

    for (i = num_locations - 1; i >= 0; i--) {
        total_value += locations[i].value;
        printf("Location %d with value %d\n", locations[i].location, locations[i].value);
    }

    printf("Total value of gems collected: %d\n", total_value);

    return 0;
}