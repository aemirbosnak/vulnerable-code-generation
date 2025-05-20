//FormAI DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include <stdio.h>

// function to perform binary search
int binary_search(int array[], int search_key, int low, int high)
{
    int mid;

    // if element is not found
    if (low > high) {
        return -1;
    }

    // divide the array in half
    mid = (low + high) / 2;

    // if element is found at mid element
    if (array[mid] == search_key) {
        return mid;
    }

    // search in left half
    if (search_key < array[mid]) {
        return binary_search(array, search_key, low, mid - 1);
    }

    // search in right half
    return binary_search(array, search_key, mid + 1, high);
}

int main()
{
    int size, i, search_key, index;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // declare the array
    int array[size];

    // input the array elements
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    // ask user for search key
    printf("Enter the search key: ");
    scanf("%d", &search_key);

    // perform binary search
    index = binary_search(array, search_key, 0, size - 1);

    // print the result
    if (index == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", index);
    }

    return 0;
}