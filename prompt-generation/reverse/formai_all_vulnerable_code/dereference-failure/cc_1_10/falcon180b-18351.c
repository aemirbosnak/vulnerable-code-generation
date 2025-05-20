//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    char *address;
} Person;

int compare(const void *a, const void *b) {
    Person *personA = (Person *)a;
    Person *personB = (Person *)b;

    int result = strcmp(personA->name, personB->name);

    if (result == 0) {
        result = personA->age - personB->age;
    }

    return result;
}

void swap(Person **a, Person **b) {
    Person *temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(Person *arr, int left, int right) {
    if (left >= right) {
        return;
    }

    Person *pivot = arr + (left + right) / 2;
    pivot->name = "pivot"; // for visualization purposes only
    int i = left, j = right;

    while (i <= j) {
        while (strcmp(arr[i].name, pivot->name) < 0) {
            i++;
        }
        while (strcmp(arr[j].name, pivot->name) > 0) {
            j--;
        }
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    swap(&arr[i], &arr[right]);
    quicksort(arr, left, i - 1);
    quicksort(arr, i + 1, right);
}

int main() {
    Person *arr = malloc(MAX_SIZE * sizeof(Person));
    int size = 0;

    char input[100];
    while (fgets(input, 100, stdin)!= NULL) {
        char *name = strtok(input, ",");
        int age = atoi(strtok(NULL, ","));
        char *address = strtok(NULL, ",");

        if (size == MAX_SIZE) {
            printf("Maximum size reached.\n");
            break;
        }

        arr[size].name = strdup(name);
        arr[size].age = age;
        arr[size].address = strdup(address);
        size++;
    }

    quicksort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        printf("%s,%d,%s\n", arr[i].name, arr[i].age, arr[i].address);
    }

    free(arr);
    return 0;
}