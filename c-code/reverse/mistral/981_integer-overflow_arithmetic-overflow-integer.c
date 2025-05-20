#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 10000

int cmp(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void quicksort(char **arr, int left, int right) {
    if (left < right) {
        int pivotIndex = left + (right - left) / 2;
        char *pivot = arr[pivotIndex];
        int i = left, j = right;
        char *temp;

        while (i <= j) {
            while (strcmp(arr[i], pivot) < 0) i++;
            while (strcmp(arr[j], pivot) > 0) j--;
            if (i <= j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }
        quicksort(arr, left, j);
        if (i != right) quicksort(arr, i, right);
    }
}

int main() {
    char **strings, input[MAX_SIZE];
    int n, i;

    scanf("%d", &n);
    strings = (char **)malloc(n * sizeof(char *));

    for (i = 0; i < n; i++) {
        gets(input);
        strings[i] = (char *)malloc((strlen(input) + 1) * sizeof(char));
        strcpy(strings[i], input);
    }

    quicksort(strings, 0, n - 1);

    for (i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
        free(strings[i]);
    }

    free(strings);

    return 0;
}
