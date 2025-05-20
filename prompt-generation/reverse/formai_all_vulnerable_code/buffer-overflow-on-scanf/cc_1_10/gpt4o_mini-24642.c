//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform linear search
int linear_search(const char *arr[], int size, const char *target) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i], target) == 0) {
            count++;
            printf("Found \"%s\" at index %d.\n", target, i);
        }
    }
    return count;
}

// Function to get the item list from the user
void get_items(char **items, int num_items) {
    printf("Enter %d item names (each not exceeding 20 characters):\n", num_items);
    for (int i = 0; i < num_items; i++) {
        printf("Item %d: ", i + 1);
        scanf("%s", items[i]);
    }
}

// Function to free the allocated memory for items
void free_items(char **items, int num_items) {
    for (int i = 0; i < num_items; i++) {
        free(items[i]);
    }
    free(items);
}

int main() {
    int num_items;

    printf("Welcome to the Item Search Program!\n");
    printf("How many items do you want to enter? ");
    scanf("%d", &num_items);

    // Dynamic memory allocation for item names
    char **items = malloc(num_items * sizeof(char *));
    for (int i = 0; i < num_items; i++) {
        items[i] = malloc(21 * sizeof(char)); // Allowing for 20 characters + null terminator
    }

    // Get item names from user
    get_items(items, num_items);

    char target[21];
    printf("Enter the item name you want to search for: ");
    scanf("%s", target);

    // Perform linear search
    int result_count = linear_search((const char **)items, num_items, target);

    // Display results
    if (result_count > 0) {
        printf("The item \"%s\" was found %d times in your list.\n", target, result_count);
    } else {
        printf("The item \"%s\" was not found in your list.\n", target);
    }

    // Free the allocated memory
    free_items(items, num_items);

    printf("Thank you for using the Item Search Program!\n");
    return 0;
}