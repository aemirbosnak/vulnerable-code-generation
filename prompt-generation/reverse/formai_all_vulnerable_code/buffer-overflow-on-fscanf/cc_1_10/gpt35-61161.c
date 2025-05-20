//FormAI DATASET v1.0 Category: File handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int readFile(const char *fileName, int *array, int *size)
{
    FILE *file;
    int number, count = 0;

    file = fopen(fileName, "r");

    if (!file) {
        printf("Unable to open the file!\n");
        return 0;
    }

    while (fscanf(file, "%d", &number) == 1 && count < MAX_SIZE) {
        array[count++] = number;
    }

    *size = count;

    fclose(file);

    return 1;
}

int writeFile(const char *fileName, const char *mode, int *array, int size)
{
    FILE *file;
    int i;

    file = fopen(fileName, mode);

    if (!file) {
        printf("Unable to open the file!\n");
        return 0;
    }

    for (i = 0; i < size; ++i) {
        fprintf(file, "%d ", array[i]);
    }

    fclose(file);

    return 1;
}

void sort(int *array, int size)
{
    int i, j, temp;

    for (i = 0; i < size; ++i) {
        for (j = i + 1; j < size; ++j) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main(void)
{
    int array[MAX_SIZE];
    int size;

    if (readFile("input.txt", array, &size)) {
        printf("Before sorting: \n");
        for (int i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }

        sort(array, size);

        printf("\n\nAfter sorting: \n");
        for (int i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }

        if (!writeFile("output.txt", "w", array, size)) {
            printf("Error writing to file.\n");
        }

    }

    return 0;
}