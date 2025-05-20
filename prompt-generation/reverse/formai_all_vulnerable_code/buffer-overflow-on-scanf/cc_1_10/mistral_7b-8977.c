//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 100
#define ELEMENT_SIZE sizeof(struct Element)

typedef struct Element {
    int id;
    char name[20];
} Element;

void print_array(Element arr[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d. %s (%d)\n", i + 1, arr[i].name, arr[i].id);
    }
}

void bubble_sort(Element arr[], int size) {
    bool swapped;
    for (int i = 0; i < size - 1; ++i) {
        swapped = false;
        for (int j = 0; j < size - i - 1; ++j) {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
                Element temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
            if (arr[j].id > arr[j + 1].id && strcmp(arr[j].name, arr[j + 1].name) == 0) {
                Element temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    Element arr[MAX_SIZE];
    int size = 0;

    printf("Welcome to BubbleSortDance! Let's see some elements jive:\n");

    do {
        Element new_element;
        printf("\nEnter the name of element %d: ", size + 1);
        scanf("%s", new_element.name);
        new_element.name[strcspn(new_element.name, "\n")] = '\0';
        new_element.id = rand() % 100 + 1;

        printf("ID: %d\n", new_element.id);
        printf("Name: %s\n", new_element.name);

        if (size < MAX_SIZE) {
            arr[size] = new_element;
            size++;
        } else {
            printf("Array is full. Please remove some elements to add new ones.\n");
        }
    } while (size < MAX_SIZE);

    printf("\nBefore sorting:\n");
    print_array(arr, size);

    bubble_sort(arr, size);

    printf("\nAfter sorting:\n");
    print_array(arr, size);

    return 0;
}