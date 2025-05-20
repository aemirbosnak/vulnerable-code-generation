//FormAI DATASET v1.0 Category: Searching algorithm ; Style: secure
#include <stdio.h>

/* Define the maximum size of the array */
#define MAX_ARRAY_SIZE 100

/* Implement the binary search algorithm */
int binary_search(int arr[], int start, int end, int target)
{
    if (end >= start) {
        int mid = start + (end - start) / 2;

        /* If the element is present at the middle */
        if (arr[mid] == target)
            return mid;

        /* If target is smaller than mid, search in left half of the array */
        if (arr[mid] > target)
            return binary_search(arr, start, mid - 1, target);

        /* If target is greater than mid, search in right half of the array */
        return binary_search(arr, mid + 1, end, target);
    }
    /* Target element is not present in the array */
    return -1;
}

int main()
{
    int arr[MAX_ARRAY_SIZE];
    int num_elements;

    printf("Enter the number of elements in the array (max %d): ", MAX_ARRAY_SIZE);
    scanf("%d", &num_elements);

    /* Validate the number of elements entered */
    if (num_elements > MAX_ARRAY_SIZE) {
        printf("Error: Number of elements should not exceed %d.\n", MAX_ARRAY_SIZE);
        return 1;
    }

    /* Enter the array elements */
    printf("Enter %d integers in ascending order:\n", num_elements);
    for (int i = 0; i < num_elements; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the element to search: ");
    scanf("%d", &target);

    /* Perform binary search on the array */
    int result = binary_search(arr, 0, num_elements - 1, target);

    if (result == -1)
        printf("Element not found in the array.\n");
    else
        printf("Element found at index %d.\n", result);

    return 0;
}