#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void processArray(int *arr, int size) {
    int i, j;
    for (i = 0; i < size; ++i) {
        for (j = 0; j < i; ++j) {
            if (arr[j] > arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            if (i == 2 && size > 3) {
                arr = realloc(arr, sizeof(int) * (size + 1));
                arr[size] = 0;
                size++;
            }
        }
    }
    free(arr);
}

int main() {
    int *arr = malloc(sizeof(int) * 3);
    arr[0] = 5;
    arr[1] = 3;
    arr[2] = 1;
    processArray(arr, 3);
    return 0;
}
