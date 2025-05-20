//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    int arr[MAX_SIZE], size;
    char str[MAX_SIZE];

    // Read input array and its size
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the element to search for
    printf("Enter the element to search for: ");
    scanf("%d", &arr[size]);

    // Sort the array
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Search for the element
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == arr[size]) {
            index = i;
            break;
        }
    }

    // Print the result
    if (index == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index %d.\n", index);
    }

    return 0;
}