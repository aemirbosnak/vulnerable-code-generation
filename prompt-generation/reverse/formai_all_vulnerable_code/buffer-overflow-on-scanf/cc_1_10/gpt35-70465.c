//FormAI DATASET v1.0 Category: Benchmarking ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MIN_VALUE 100
#define MAX_VALUE 1000

typedef struct multivariable {
    int a;
    float b;
    double c;
} multivariable;

void fill_array(multivariable array[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        array[i].a = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;;
        array[i].b = (float)(rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;;
        array[i].c = (double)(rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;;
    }
}

void print_array(multivariable array[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d %.2f %.2lf\n", array[i].a, array[i].b, array[i].c);
    }
}

void insertion_sort(multivariable array[], int size) {
    int i, j;
    multivariable temp;
    for (i = 1; i < size; i++) {
        temp = array[i];
        j = i - 1;
        while (j >= 0 && array[j].c > temp.c) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

int main() {
    int size, i;
    clock_t start, end;
    double time_taken;
    srand(time(0));
    printf("Enter the size of array: ");
    scanf("%d", &size);
    multivariable* array = (multivariable*)malloc(size * sizeof(multivariable));
    fill_array(array, size);
    printf("Printing unsorted array:\n");
    print_array(array, size);
    start = clock();
    insertion_sort(array, size);
    end = clock();
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Printing sorted array:\n");
    print_array(array, size);
    printf("Time taken for sorting: %lf seconds.\n", time_taken);
    free(array);
    return 0;
}