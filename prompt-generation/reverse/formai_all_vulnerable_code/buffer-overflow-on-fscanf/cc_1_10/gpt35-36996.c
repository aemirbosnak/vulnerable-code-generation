//FormAI DATASET v1.0 Category: File handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int read_file(char *filename, int *array, int length) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Failed to open file %s\n", filename);
        return -1;
    }

    int i = 0;
    while (!feof(f) && i < length) {
        fscanf(f, "%d", &array[i]);
        i++;
    }

    fclose(f);

    return i;
}

void write_file(char *filename, int *array, int length) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        printf("Failed to open file %s\n", filename);
        return;
    }

    for (int i = 0; i < length; i++) {
        fprintf(f, "%d ", array[i]);
    }

    fclose(f);
}

void print_array(int *array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubble_sort(int *array, int length) {
    for (int i = 0; i < length-1; i++) {
        for (int j = 0; j < length-i-1; j++) {
            if (array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
            }
        }
    }
}


int main() {
    int array[MAX_SIZE];
    int length;

    length = read_file("input.txt", array, MAX_SIZE);
    if (length <= 0) {
        return 0;
    }

    printf("Original Array:\n");
    print_array(array, length);

    bubble_sort(array, length);

    printf("Sorted Array:\n");
    print_array(array, length);

    write_file("output.txt", array, length);

    return 0;
}