//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

#define MAX 1000
#define MIN_INT (-2147483647)
#define PI 3.14159265358979323846

typedef struct {
    int id;
    char name[20];
    float height;
    float weight;
} Person;

void swap(Person* a, Person* b) {
    Person temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Person arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].height > arr[j + 1].height) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int i;
    clock_t begin = clock();
    Person people[MAX];
    int n;

    printf("Enter the number of people: ");
    scanf("%d", &n);

    printf("\nEnter %d names, heights, and weights:\n", n);
    for (i = 0; i < n; i++) {
        printf("Person %d: ", i + 1);
        scanf("%s", people[i].name);
        scanf("%f", &people[i].height);
        scanf("%f", &people[i].weight);
    }

    bubbleSort(people, n);

    printf("\nSorted list:\n");
    for (i = 0; i < n; i++) {
        printf("%s (%f, %f)\n", people[i].name, people[i].height, people[i].weight);
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime spent: %f seconds", time_spent);

    return 0;
}