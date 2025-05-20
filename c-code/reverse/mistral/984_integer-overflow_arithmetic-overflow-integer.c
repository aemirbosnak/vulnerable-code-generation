#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quicksort(char** arr, int left, int right);

int main(int argc, char *argv[]) {
    int n, i;
    printf("Enter the number of strings: ");
    scanf("%d", &n);

    char** strings = (char**)malloc(n * sizeof(char*));

    for (i = 0; i < n; i++) {
        strings[i] = (char*)malloc(sizeof(char) * (1 + atoi(argv[i + 1])));
        scanf("%s", strings[i]);
    }

    quicksort(strings, 0, n - 1);

    for (i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
        free(strings[i]);
    }
    free(strings);

    return 0;
}

void quicksort(char** arr, int left, int right) {
    int i, last, temp;
    void swap(char** a, char** b) { char* t = *a; *a = *b; *b = t; }

    if (left < right) {
        last = left;
        i = right;
        char* pivot = arr[(left + right) / 2];

        do {
            while (strcmp(arr[last], pivot) < 0) last++;
            while (strcmp(arr[i], pivot) > 0) i--;
            if (last < i) swap(&arr[last], &arr[i]);
        } while (last < i);

        swap(&arr[last], &arr[right]);
        quicksort(arr, left, --right);
        quicksort(arr, left, last);
    }
}
