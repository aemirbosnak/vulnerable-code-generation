//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int search(char *array[], char *key, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(array[i], key) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int size;
    char **array;
    char key[MAX_SIZE];

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    array = (char **)malloc(size * sizeof(char *));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        array[i] = (char *)malloc(MAX_SIZE * sizeof(char));
        scanf("%s", array[i]);
    }

    printf("Enter the key to search for:\n");
    scanf("%s", key);

    int index = search(array, key, size);

    if (index == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index %d.\n", index);
    }

    for (int i = 0; i < size; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}