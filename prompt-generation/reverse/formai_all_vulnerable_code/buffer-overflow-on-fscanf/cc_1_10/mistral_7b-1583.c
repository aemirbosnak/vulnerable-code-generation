//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void bubbleSort(int arr[], int n);
int readFile(const char *filename, int arr[], int *size);
int writeFile(const char *filename, int arr[], int size);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    int n, *arr;
    arr = (int *)calloc(1, sizeof(int) * (readFile(argv[1], NULL, &n) / sizeof(int)));
    if (arr == NULL) {
        perror("Memory allocation failed\n");
        return 1;
    }

    bubbleSort(arr, n);
    writeFile(argv[1], arr, n);

    free(arr);
    return 0;
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int readFile(const char *filename, int arr[], int *size) {
    FILE *fp;
    int i = 0;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file\n");
        *size = 0;
        return 0;
    }

    while (!feof(fp)) {
        if (fscanf(fp, "%d", &arr[i]) != EOF) {
            i++;
        }
    }

    *size = i;
    fclose(fp);
    return i * sizeof(int);
}

int writeFile(const char *filename, int arr[], int size) {
    FILE *fp;

    fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file for writing\n");
        return 1;
    }

    fwrite(arr, sizeof(int), size, fp);
    fclose(fp);
    return 0;
}