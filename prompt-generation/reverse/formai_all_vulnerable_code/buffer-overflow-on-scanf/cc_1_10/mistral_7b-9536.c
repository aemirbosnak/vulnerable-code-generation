//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int id;
    char name[50];
} Person;

void print_arr(Person arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d. %s %d\n", i + 1, arr[i].name, arr[i].id);
    }
}

void swap(Person *a, Person *b) {
    Person temp = *a;
    *a = *b;
    *b = temp;
}

void sereneBubbleSort(Person arr[], int size) {
    int i, j, flag = 1;
    for (i = 0; i < size - 1 && flag; i++) {
        flag = 0;
        for (j = 0; j < size - i - 1; j++) {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
                swap(&arr[j], &arr[j + 1]);
                flag = 1;
                usleep(100000); // Pause for a short time to make sorting calmer
            }
        }
    }
}

int main() {
    srand(time(NULL));
    Person arr[MAX_SIZE];
    int size = 0;

    while (size < MAX_SIZE && scanf("%s %d", arr[size].name, &arr[size].id) != EOF) {
        size++;
    }

    sereneBubbleSort(arr, size);
    printf("Before sorting:\n");
    print_arr(arr, size);

    sereneBubbleSort(arr, size);
    printf("\nAfter sorting:\n");
    print_arr(arr, size);

    return 0;
}