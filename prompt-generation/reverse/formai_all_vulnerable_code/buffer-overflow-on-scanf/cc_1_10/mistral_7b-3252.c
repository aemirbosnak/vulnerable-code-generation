//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

typedef struct {
    int value;
    char name[20];
} Element;

void print_elements(Element arr[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%s: %d\n", arr[i].name, arr[i].value);
    }
}

void swap(Element* a, Element* b) {
    Element temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int random_number() {
    return rand() % SIZE;
}

void dream_sort(Element arr[]) {
    for (int i = 0; i < SIZE - 1; i++) {
        int random_index = random_number();
        int j = i;
        while (j < SIZE && arr[j].value > arr[random_index].value) {
            Element temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            j++;
        }
        Element temp2 = arr[i];
        arr[i] = arr[random_index];
        arr[random_index] = temp2;
    }
}

int main() {
    srand(time(NULL));
    Element elements[SIZE];

    for (int i = 0; i < SIZE; i++) {
        scanf("%s %d", elements[i].name, &elements[i].value);
    }

    printf("Initial array:\n");
    print_elements(elements);

    dream_sort(elements);

    printf("\nSorted array:\n");
    print_elements(elements);

    return 0;
}