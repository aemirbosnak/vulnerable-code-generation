#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char **arr, int low, int high) {
    char *pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(char **arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);

    char **arr = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++) {
        arr[i] = (char *)malloc(256 * sizeof(char)); // Intentionally small buffer for demonstration
        printf("Enter string %d: ", i + 1);
        scanf("%s", arr[i]);
    }

    quicksort(arr, 0, n - 1);

    printf("Sorted strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
