#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

void swap(char *a, char *b, int n) {
    char temp[n + 1];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

int partition(char *arr, int low, int high) {
    char pivot = arr[(low + high) / 2];
    int i = low, j = high;

    while (i <= j) {
        while (strcmp(arr[i], pivot) < 0) i++;
        while (strcmp(arr[j], pivot) > 0) j--;
        if (i <= j) swap(arr[i], arr[j], sizeof(arr[0]));
    }

    return i;
}

void quicksort(char *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    char arr[MAX_N][100];
    int n, i;

    printf("Enter the number of strings: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter string %d: ", i + 1);
        scanf("%s", arr[i]);
    }

    quicksort(arr, 0, n - 1);

    for (i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}
