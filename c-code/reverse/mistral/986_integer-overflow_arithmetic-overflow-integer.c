#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quicksort(char** arr, int left, int right);
char** createArray(int size);

int main() {
    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);

    char** strings = createArray(n);

    for (int i = 0; i < n; ++i) {
        printf("Enter string %d: ", i + 1);
        scanf("%s", strings[i]);
    }

    quicksort(strings, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        printf("%s\n", strings[i]);
    }

    return 0;
}

char** createArray(int size) {
    char** arr = (char*)malloc(sizeof(char*) * size);
    return arr;
}

void quicksort(char** arr, int left, int right) {
    if (left < right) {
        int pivotIndex = (left + right) / 2;
        char* pivot = arr[pivotIndex];
        int i = left;
        int j = right;
        char* temp;

        while (i <= j) {
            while (strcmp(arr[i], pivot) < 0)
                i++;
            while (strcmp(arr[j], pivot) > 0)
                j--;
            if (i <= j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }
        quicksort(arr, left, j);
        quicksort(arr, i, right);
    }
}
