//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 1000
#define MAX_KEY_LENGTH 50

// Define the structure of each element in the array
typedef struct {
    char key[MAX_KEY_LENGTH];
    int value;
} element_t;

// Function to perform binary search on the array
int binary_search(element_t arr[], int size, char* key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(arr[mid].key, key);

        if (cmp == 0) {
            // Key found
            return mid;
        } else if (cmp < 0) {
            // Key not found, search right half
            low = mid + 1;
        } else {
            // Key not found, search left half
            high = mid - 1;
        }
    }

    // Key not found
    return -1;
}

// Function to sort the array in ascending order based on keys
void sort_array(element_t arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            int cmp = strcmp(arr[i].key, arr[j].key);

            if (cmp > 0) {
                // Swap elements
                element_t temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int size;
    printf("Enter the number of elements to be stored: ");
    scanf("%d", &size);

    element_t arr[MAX_ELEMENTS];
    for (int i = 0; i < size; i++) {
        char key[MAX_KEY_LENGTH];
        printf("Enter key for element %d: ", i + 1);
        scanf("%s", key);
        strncpy(arr[i].key, key, MAX_KEY_LENGTH);
        arr[i].value = i + 1;
    }

    // Sort the array
    sort_array(arr, size);

    // Perform binary search on the array
    char search_key[MAX_KEY_LENGTH];
    printf("Enter the key to search: ");
    scanf("%s", search_key);

    int index = binary_search(arr, size, search_key);

    if (index == -1) {
        printf("Key not found\n");
    } else {
        printf("Key found at index %d\n", index);
    }

    return 0;
}