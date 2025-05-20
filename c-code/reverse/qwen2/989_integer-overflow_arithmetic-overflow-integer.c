#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char **arr, int low, int high) {
    char *pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(char **arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);
    getchar(); // Consume newline character left in buffer

    char **strings = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        strings[i] = malloc(MAX_STR_LEN * sizeof(char));
        printf("Enter string %d: ", i + 1);
        fgets(strings[i], MAX_STR_LEN, stdin);
        strings[i][strcspn(strings[i], "\n")] = '\0'; // Remove newline character
    }

    quickSort(strings, 0, n - 1);

    printf("\nSorted strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
        free(strings[i]); // Free each individual string
    }

    free(strings); // Free array of pointers

    return 0;
}
