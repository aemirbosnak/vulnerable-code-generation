//Falcon-180B DATASET v1.0 Category: Recursive ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to swap two strings
void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
int partition(char **arr, int low, int high) {
    char *pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            swap(&arr[i+1], &arr[j]);
            i++;
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i + 1;
}

// Function to perform quicksort
void quicksort(char **arr, int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quicksort(arr, low, pivot_index - 1);
        quicksort(arr, pivot_index + 1, high);
    }
}

int main() {
    int num_strings;
    printf("Enter the number of strings: ");
    scanf("%d", &num_strings);
    char **strings = malloc(num_strings * sizeof(char*));
    for (int i = 0; i < num_strings; i++) {
        strings[i] = malloc(1000 * sizeof(char));
        printf("Enter string %d: ", i+1);
        scanf("%s", strings[i]);
    }
    quicksort(strings, 0, num_strings - 1);
    printf("Sorted strings:\n");
    for (int i = 0; i < num_strings; i++) {
        printf("%s\n", strings[i]);
        free(strings[i]);
    }
    free(strings);
    return 0;
}