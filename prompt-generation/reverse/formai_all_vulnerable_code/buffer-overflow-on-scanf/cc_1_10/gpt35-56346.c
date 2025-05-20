//FormAI DATASET v1.0 Category: Memory management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main() {
    // declare initial pointers
    int* my_nums = NULL;
    int* new_nums = NULL;
    int i, n;

    printf("Enter the number of integers you wish to store:");
    scanf("%d", &n);

    // allocate memory for initial pointer
    my_nums = (int*)calloc(n, sizeof(int));

    // ensure memory allocation was successful
    if (my_nums == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }

    // populate initial pointer with values
    for (i = 0; i < n; i++) {
        printf("Enter integer #%d:", i + 1);
        scanf("%d", &my_nums[i]);
    }

    // reallocate memory for new pointer with additional space
    new_nums = (int*)realloc(my_nums, (n + 5) * sizeof(int));

    // ensure memory reallocation was successful
    if (new_nums == NULL) {
        printf("Memory reallocation failed.");
        return 1;
    }

    // update initial pointer to new memory location
    my_nums = new_nums;

    // populate additional space with new values
    for (i = n; i < n + 5; i++) {
        printf("Enter integer #%d:", i + 1);
        scanf("%d", &my_nums[i]);
    }

    // print all stored integers
    printf("Here are the stored integers:\n");
    for (i = 0; i < n + 5; i++) {
        printf("%d ", my_nums[i]);
    }

    // free allocated memory
    free(my_nums);

    return 0;
}