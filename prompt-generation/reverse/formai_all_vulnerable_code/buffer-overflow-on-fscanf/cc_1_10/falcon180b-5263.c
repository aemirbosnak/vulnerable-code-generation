//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    int index;
} Person;

void swap(Person *a, Person *b) {
    Person temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Person *array, int low, int high, int (*compare)(Person *, Person *)) {
    Person pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (compare(&array[j], &pivot) < 0) {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);

    return i + 1;
}

void quicksort(Person *array, int low, int high, int (*compare)(Person *, Person *)) {
    if (low >= high)
        return;

    int pi = partition(array, low, high, compare);

    quicksort(array, low, pi - 1, compare);
    quicksort(array, pi + 1, high, compare);
}

int compare_age(Person *a, Person *b) {
    return a->age - b->age;
}

int compare_name(Person *a, Person *b) {
    return strcmp(a->name, b->name);
}

void print_array(Person *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s %d\n", array[i].name, array[i].age);
    }
}

int main() {
    Person array[MAX_SIZE];
    int size = 0;

    FILE *file = fopen("data.txt", "r");

    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fscanf(file, "%s %d", array[size].name, &array[size].age)!= EOF) {
        size++;
    }

    fclose(file);

    quicksort(array, 0, size - 1, compare_age);
    print_array(array, size);

    quicksort(array, 0, size - 1, compare_name);
    print_array(array, size);

    return 0;
}