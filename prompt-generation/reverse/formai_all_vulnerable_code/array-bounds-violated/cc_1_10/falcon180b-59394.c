//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    char arr[MAX_SIZE];
    int n, key;

    // take input from user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // take input elements from user
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // take input key from user
    printf("Enter the key to search: ");
    scanf("%d", &key);

    // perform linear search
    int index = 0;
    while (index < n) {
        if (arr[index] == key) {
            printf("Element found at index %d\n", index);
            break;
        }
        index++;
    }

    // perform binary search
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == key) {
            printf("Element found at index %d\n", mid);
            break;
        }
        else if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return 0;
}