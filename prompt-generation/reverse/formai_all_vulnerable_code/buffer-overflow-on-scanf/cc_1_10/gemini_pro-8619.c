//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // Whoa! We're going to sort an array of integers!

    int n;
    printf("How many integers do you want to sort, my friend?\n");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the integers, one by one:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Oopsie! We need to sort them now!

    qsort(arr, n, sizeof(int), compare);

    // Ta-da! The array is sorted! Let's show it off:

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Wait, what if we want to sort them in descending order?

    qsort(arr, n, sizeof(int), compare);

    // Wow! They're sorted in reverse order now!

    printf("Sorted array in descending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Time to free the memory we allocated earlier:

    free(arr);

    return 0;
}