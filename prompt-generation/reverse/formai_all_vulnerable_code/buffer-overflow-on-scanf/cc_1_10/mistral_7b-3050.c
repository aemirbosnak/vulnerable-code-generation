//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct {
    int key;
    char name[20];
} Data;

void print_array(Data arr[], int size) {
    printf("{");
    for (int i = 0; i < size; i++) {
        printf("{%d, '%s'}, ", arr[i].key, arr[i].name);
        if (i == size - 1)
            printf("}\n");
        else
            printf("\n");
    }
}

int c_searching(Data arr[], int size, int key) {
    int low = 0, high = size - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid].key == key)
            return mid;

        if (arr[mid].key < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    Data arr[MAX_SIZE];
    int n, key, index;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++) {
        printf("Name %d: ", i + 1);
        scanf("%s", arr[i].name);

        printf("Key %d: ", i + 1);
        scanf("%d", &arr[i].key);
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);

    index = c_searching(arr, n, key);

    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found\n");

    printf("\nElements in the array:\n");
    print_array(arr, n);

    return 0;
}

/* Ada Lovelace's spirit in this code:
 * - Use of structures (arrays of structures)
 * - Incorporation of mathematics (calculation of mid index)
 * - Fascination with music (use of 'print_array' function to display elements)
 * - Creativity (use of 'c_searching' function name instead of 'binary_search')
 */