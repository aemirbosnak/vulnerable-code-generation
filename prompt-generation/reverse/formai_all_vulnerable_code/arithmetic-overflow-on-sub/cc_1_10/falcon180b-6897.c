//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

int compare(const void *a, const void *b) {
    Person *personA = (Person *)a;
    Person *personB = (Person *)b;
    return strcmp(personA->name, personB->name);
}

void swap(Person *a, Person *b) {
    Person temp = *a;
    *a = *b;
    *b = temp;
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

int main() {
    int n;
    scanf("%d", &n);
    Person arr[n];
    for (int i = 0; i < n; i++) {
        arr[i].name = (char *)malloc(MAX_SIZE * sizeof(char));
        scanf("%s", arr[i].name);
        scanf("%d", &arr[i].age);
    }
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", arr[i].name, arr[i].age);
    }
    for (int i = 0; i < n; i++) {
        free(arr[i].name);
    }
    return 0;
}