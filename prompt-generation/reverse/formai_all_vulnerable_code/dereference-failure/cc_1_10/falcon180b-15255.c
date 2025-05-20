//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // maximum size of the array

typedef struct {
    char *name;
    int age;
} Person;

void sort_array(Person arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].age > arr[j].age) {
                Person temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int binary_search(Person arr[], int n, char *name) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (strcmp(arr[mid].name, name) == 0) {
            return mid;
        } else if (strcmp(arr[mid].name, name) > 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1; // element not found
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    Person arr[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        arr[i].name = (char *)malloc(100 * sizeof(char));
        arr[i].age = 0;
        printf("Enter the name and age of element %d: ", i + 1);
        scanf("%s %d", arr[i].name, &arr[i].age);
    }

    printf("Enter the name to search for: ");
    char *name = (char *)malloc(100 * sizeof(char));
    scanf("%s", name);

    int result = binary_search(arr, n, name);

    if (result!= -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    for (int i = 0; i < n; i++) {
        free(arr[i].name);
    }
    free(name);

    return 0;
}