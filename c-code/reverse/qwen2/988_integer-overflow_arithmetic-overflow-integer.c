#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

char* createString(int len) {
    char *str = (char *)malloc(len);
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    return str;
}

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
    getchar(); // Consume newline character left by scanf

    char **strings = (char **)malloc(n * sizeof(char *));
    if (strings == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        printf("Enter string %d: ", i + 1);
        char buffer[MAX_LEN];
        fgets(buffer, MAX_LEN, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
        strings[i] = createString(strlen(buffer) + 1);
        strcpy(strings[i], buffer);
    }

    quickSort(strings, 0, n - 1);

    printf("Sorted strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
        free(strings[i]);
    }

    free(strings);
    return 0;
}
