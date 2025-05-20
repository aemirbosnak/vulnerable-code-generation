//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

int compare(const void *a, const void *b) {
    Person *personA = (Person *)a;
    Person *personB = (Person *)b;

    if (personA->age > personB->age) {
        return 1;
    } else if (personA->age < personB->age) {
        return -1;
    } else {
        return 0;
    }
}

void printArray(Person arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Name: %s, Age: %d\n", arr[i].name, arr[i].age);
    }
}

int main() {
    Person arr[] = {{ "John", 25 }, { "Jane", 30 }, { "Bob", 20 }, { "Alice", 28 }};
    int size = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, size, sizeof(Person), compare);

    printf("Sorted array:\n");
    printArray(arr, size);

    Person target = {.name = "Alice",.age = 28 };
    Person *result = bsearch(&target, arr, size, sizeof(Person), compare);

    if (result!= NULL) {
        printf("\nFound %s at index %d\n", result->name, (int)(result - arr));
    } else {
        printf("\n%s not found\n", target.name);
    }

    return 0;
}