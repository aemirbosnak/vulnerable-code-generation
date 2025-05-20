//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Dennis Ritchie
/* C Personal Finance Planner */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} item_t;

int main() {
    int num_items;
    item_t *items;
    char input[MAX_NAME_LENGTH + MAX_VALUE_LENGTH + 2]; // +2 for space and null terminator
    int i, j;

    // Get number of items
    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    // Allocate memory for items
    items = (item_t *)malloc(num_items * sizeof(item_t));
    if (items == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    // Get item names and values
    for (i = 0; i < num_items; i++) {
        printf("Enter item %d name: ", i + 1);
        scanf("%s", items[i].name);

        printf("Enter item %d value: ", i + 1);
        scanf("%s", input);
        strncpy(items[i].value, input, MAX_VALUE_LENGTH);
    }

    // Calculate total value
    double total_value = 0.0;
    for (i = 0; i < num_items; i++) {
        total_value += atof(items[i].value);
    }

    // Print item list and total value
    printf("\nItem List:\n");
    for (i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i + 1, items[i].name, atof(items[i].value));
    }

    printf("\nTotal Value: $%.2f\n", total_value);

    // Free memory
    for (i = 0; i < num_items; i++) {
        free(items[i].name);
        free(items[i].value);
    }
    free(items);

    return 0;
}