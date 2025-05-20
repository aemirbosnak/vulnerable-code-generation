//MISTRAL-7B DATASET v1.0 Category: Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define ARRAY_SIZE 10

typedef struct {
    int key;
    char name[MAX_LINE_LENGTH];
} Person;

void swap(Person *a, Person *b) {
    Person temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(Person arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j].key < arr[min_idx].key) {
                min_idx = j;
            }
        }
        swap(&arr[i], &arr[min_idx]);
    }
}

int main(void) {
    Person people[ARRAY_SIZE];
    int i;

    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("Enter name and age of person %d: ", i + 1);
        fgets(people[i].name, MAX_LINE_LENGTH, stdin);
        sscanf(strchr(people[i].name, ' '), "%d", &people[i].key);
    }

    selectionSort(people, ARRAY_SIZE);

    printf("\nSorted list:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("Name: %s, Age: %d\n", people[i].name, people[i].key);
    }

    return EXIT_SUCCESS;
}