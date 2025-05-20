//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 10

typedef struct {
    int key;
    char name[20];
} Element;

void swap(Element *a, Element *b) {
    Element temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bucketSort(Element arr[], int n) {
    int i, j, bucket, index;
    Element *pointer;
    int *bucketArray;

    bucketArray = (int *)calloc(SIZE, sizeof(int));

    for (i = 0; i < SIZE; i++) {
        bucketArray[i] = 0;
    }

    for (i = 0; i < n; i++) {
        index = (arr[i].key % SIZE);
        bucketArray[index]++;
    }

    pointer = (Element *)calloc(SIZE, sizeof(Element));

    for (i = 0, j = 0; i < SIZE; i++) {
        while (bucketArray[i]--) {
            pointer[j++] = arr[i];
        }
    }

    for (i = 0; i < n; i++) {
        arr[i] = pointer[i];
    }

    free(pointer);
    free(bucketArray);
}

int main() {
    Element data[SIZE];
    int i;

    printf("Enter the data (name and number):\n");

    for (i = 0; i < SIZE; i++) {
        scanf("%s %d", data[i].name, &data[i].key);
    }

    printf("Before Sorting:\n");

    for (i = 0; i < SIZE; i++) {
        printf("%s: %d\n", data[i].name, data[i].key);
    }

    bucketSort(data, SIZE);

    printf("\nAfter Sorting:\n");

    for (i = 0; i < SIZE; i++) {
        printf("%s: %d\n", data[i].name, data[i].key);
    }

    return 0;
}