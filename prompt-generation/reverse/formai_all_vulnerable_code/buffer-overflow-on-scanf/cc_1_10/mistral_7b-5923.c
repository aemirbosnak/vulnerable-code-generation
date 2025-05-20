//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct {
    int value;
    char* name;
} Item;

void swap(Item* a, Item* b) {
    Item temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int greedy_algorithm(Item items[], int n) {
    int i, j, max_index;
    Item max_item;

    for (i = 0; i < n; i++) {
        max_index = i;
        max_item = items[i];

        for (j = i + 1; j < n; j++) {
            if (max_item.value < items[j].value) {
                max_index = j;
                max_item = items[j];
            }
        }

        if (i != max_index) {
            swap(&items[i], &items[max_index]);
        }
    }

    for (i = 0; i < n; i++) {
        printf("The %s treasure is worth %d gold coins.\n", items[i].name, items[i].value);
    }

    return 0;
}

int main() {
    int n;
    Item treasures[100];

    printf("Welcome brave adventurer to the Enchanted Forest!\n");
    printf("Please enter the number of treasures you wish to find: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the name and worth of the %d treasure: ", i + 1);
        scanf("%s %d", treasures[i].name, &treasures[i].value);
    }

    printf("\nThe order of treasures to find is as follows:\n");
    greedy_algorithm(treasures, n);

    return 0;
}