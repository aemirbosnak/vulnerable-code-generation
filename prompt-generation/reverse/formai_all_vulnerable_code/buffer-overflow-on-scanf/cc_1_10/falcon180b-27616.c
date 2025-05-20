//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    int id;
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

void swap(Person *a, Person *b) {
    Person temp;

    temp.name = a->name;
    temp.age = a->age;
    temp.id = a->id;

    a->name = b->name;
    a->age = b->age;
    a->id = b->id;

    b->name = temp.name;
    b->age = temp.age;
    b->id = temp.id;
}

void bubbleSort(Person arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (compare(&arr[j], &arr[j + 1]) > 0) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void printArray(Person arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%s %d %d\n", arr[i].name, arr[i].age, arr[i].id);
    }
}

int main() {
    Person arr[MAX_SIZE];
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        arr[i].name = (char *)malloc(100 * sizeof(char));
        scanf("%s", arr[i].name);
        arr[i].age = i + 1;
        arr[i].id = i;
    }

    bubbleSort(arr, n);
    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}