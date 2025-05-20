//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The good old Watson, always ready to assist
typedef struct {
    int size;
    int *array;
} Watson;

// Sherlock's brilliant deduction method
void sherlockSort(Watson *watson)
{
    int i, j, smallest;
    for (i = 0; i < watson->size - 1; i++) {
        smallest = i;
        for (j = i + 1; j < watson->size; j++) {
            if (watson->array[j] < watson->array[smallest]) {
                smallest = j;
            }
        }
        // Watson, swap the suspects!
        int temp = watson->array[i];
        watson->array[i] = watson->array[smallest];
        watson->array[smallest] = temp;
    }
}

int main()
{
    // Let us gather some clues
    int n;
    printf("Watson, how many suspects do we have? ");
    scanf("%d", &n);

    // Watson, initialize our array of suspects
    Watson suspects;
    suspects.size = n;
    suspects.array = malloc(n * sizeof(int));

    // Watson, gather information about each suspect
    printf("Watson, enter the heights of the suspects: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &suspects.array[i]);
    }

    // Sherlock, use your brilliant deduction to sort the suspects
    sherlockSort(&suspects);

    // Watson, present the sorted list of suspects
    printf("Watson, the suspects are sorted: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", suspects.array[i]);
    }

    // Conclusion
    printf("\nElementary, my dear Watson!\n");

    // Free the memory allocated for the suspects
    free(suspects.array);

    return 0;
}