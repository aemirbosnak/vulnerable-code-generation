//Falcon-180B DATASET v1.0 Category: Sorting ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the structure of the element to be sorted
typedef struct {
    int id;
    char name[50];
    int age;
} Element;

// Function to compare two elements
int compare(const void* a, const void* b) {
    Element* elementA = (Element*)a;
    Element* elementB = (Element*)b;

    if (elementA->age < elementB->age) {
        return -1;
    } else if (elementA->age > elementB->age) {
        return 1;
    } else {
        return 0;
    }
}

// Function to display the array
void display(Element* array, int size) {
    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d - %s - %d\n", array[i].id, array[i].name, array[i].age);
    }
}

// Function to input the elements
void input(Element* array, int size) {
    printf("Input the elements:\n");
    for (int i = 0; i < size; i++) {
        printf("ID: ");
        scanf("%d", &array[i].id);
        printf("Name: ");
        scanf("%s", array[i].name);
        printf("Age: ");
        scanf("%d", &array[i].age);
    }
}

// Function to swap two elements
void swap(Element* array, int i, int j) {
    Element temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    Element* array = (Element*)malloc(size * sizeof(Element));

    // Input the elements
    input(array, size);

    // Sort the array
    qsort(array, size, sizeof(Element), compare);

    // Display the sorted array
    display(array, size);

    return 0;
}