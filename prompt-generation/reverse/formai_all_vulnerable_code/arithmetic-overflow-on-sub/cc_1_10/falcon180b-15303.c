//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 100000

typedef struct {
    int id;
    float value;
} Data;

void init(Data* data, int size) {
    for (int i = 0; i < size; i++) {
        data[i].id = i;
        data[i].value = rand() % 100;
    }
}

void print_data(Data* data, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d: %.2f\n", data[i].id, data[i].value);
    }
}

void sort(Data* data, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (data[j].value < data[i].value) {
                Data temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

int main() {
    Data data[MAX_SIZE];
    int size = rand() % MAX_SIZE + 1;

    init(data, size);
    printf("Before sorting:\n");
    print_data(data, size);

    clock_t start = clock();
    sort(data, size);
    clock_t end = clock();

    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("After sorting:\n");
    print_data(data, size);
    printf("Elapsed time: %.2f seconds\n", elapsed_time);

    return 0;
}