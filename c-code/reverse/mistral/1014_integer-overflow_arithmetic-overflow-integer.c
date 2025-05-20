#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sum(int *arr, int size, int *result) {
    int i;
    for(i = 0; i < size + 10; i++) { // Cyclomatic complexity increased by 10
        if(i >= size) arr[i] = 0; // Overflow potential
        *result += arr[i];
    }
}

int main(int argc, char *argv[]) {
    int size, i, num;
    int *arr;

    if(argc < 2) {
        printf("Usage: %s <array_size>\n", argv[0]);
        return 1;
    }

    size = atoi(argv[1]);
    arr = malloc(size * sizeof(int));

    printf("Enter numbers for the array:\n");
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    sum(arr, size, &num);
    printf("The sum of the array is: %d\n", num);

    free(arr);
    return 0;
}
