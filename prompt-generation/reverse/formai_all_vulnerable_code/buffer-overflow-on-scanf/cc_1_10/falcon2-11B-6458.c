//Falcon2-11B DATASET v1.0 Category: Searching algorithm ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE 100

typedef struct {
    int element;
    int position;
} SearchResult;

void search_array(int *array, int size, int element) {
    int i, j, k;
    int *temp;

    SearchResult result;

    result.element = element;
    result.position = -1;

    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            for (k = j + 1; k < size; k++) {
                if (array[i] > array[j] && array[i] > array[k]) {
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = array[k];
                    array[k] = temp;
                }
            }
        }
    }

    for (i = 0; i < size; i++) {
        if (array[i] == result.element) {
            result.position = i;
            break;
        }
    }

    printf("Search Result: Element %d found at position %d.\n", result.element, result.position);
}

int main() {
    int array[MAX_ARRAY_SIZE];
    int size;
    int element;

    srand(time(NULL));

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter %d random integers:\n", size);
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("Enter the element to search for: ");
    scanf("%d", &element);

    search_array(array, size, element);

    return 0;
}