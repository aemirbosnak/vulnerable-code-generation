//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOVE 1
#define HATE -1

// Define a struct to represent our "lovely" elements
struct element {
    int priority;
    char name[20];
};

// Function to compare elements based on their priority
int compare_priorities(struct element a, struct element b) {
    if (a.priority > b.priority) {
        return LOVE;
    } else if (a.priority < b.priority) {
        return HATE;
    } else {
        return 0; // Equal priorities, let's check their names 😉
    }
}

// Function to sort our elements based on their priorities
void sort_priorities(struct element arr[], int size) {
    int i, j, min_idx;
    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < size; j++) {
            if (compare_priorities(arr[j], arr[min_idx]) == LOVE) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            struct element temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

int main() {
    int i, size;
    struct element arr[10];

    // Input our lovely elements
    printf("Enter the priorities and names of the elements, separated by a space:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d %s", &arr[i].priority, arr[i].name);
    }

    // Sort our lovely elements based on their priorities
    sort_priorities(arr, 10);

    // Print our lovely sorted elements
    printf("Here are our lovely sorted elements, in order of their priorities:\n");
    for (i = 0; i < 10; i++) {
        printf("%s (priority: %d)\n", arr[i].name, arr[i].priority);
    }

    return 0;
}