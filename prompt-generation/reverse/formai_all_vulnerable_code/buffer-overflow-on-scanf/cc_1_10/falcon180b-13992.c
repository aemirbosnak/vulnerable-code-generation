//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of elements the array can hold
#define MAX_ELEMENTS 100

// Define the structure of the element to be searched
typedef struct {
    char name[50];
    int value;
} Element;

// Function to compare two elements
int compare_elements(const void *a, const void *b) {
    Element *element1 = (Element *) a;
    Element *element2 = (Element *) b;

    if (strcmp(element1->name, element2->name) == 0) {
        return 0;
    } else if (strcmp(element1->name, element2->name) > 0) {
        return 1;
    } else {
        return -1;
    }
}

// Function to search for an element in the array
int search(Element array[], int size, char *name) {
    Element *result = bsearch(name, array, size, sizeof(Element), compare_elements);

    if (result == NULL) {
        printf("Element not found.\n");
        return -1;
    } else {
        printf("Element found: %s\n", result->name);
        return 0;
    }
}

// Main function
int main() {
    Element array[MAX_ELEMENTS];
    int size = 0;

    // Initialize the array with some elements
    strcpy(array[size].name, "apple");
    array[size].value = 1;
    size++;

    strcpy(array[size].name, "banana");
    array[size].value = 2;
    size++;

    strcpy(array[size].name, "cherry");
    array[size].value = 3;
    size++;

    // Search for an element in the array
    char name[50];
    printf("Enter the name of the element to search for: ");
    scanf("%s", name);

    int result = search(array, size, name);

    if (result == -1) {
        printf("Exiting...\n");
    } else {
        printf("Continuing...\n");
    }

    return 0;
}