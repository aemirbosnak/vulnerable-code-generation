//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct Bear {
    int age;
    char name[20];
} Bear;

void binary_bear_search(Bear arr[], int size, int key) {
    int low = 0, high = size - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid].age == key) {
            printf("Bear %s with age %d found!\n", arr[mid].name, arr[mid].age);
            return;
        }

        if (arr[mid].age < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("Bear not found.\n");
}

void generate_bears(Bear arr[], int size) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        Bear bear;
        bear.age = rand() % 50 + 1;
        sprintf(bear.name, "Bear %d", i + 1);
        arr[i] = bear;
    }
}

int main() {
    Bear bears[MAX_SIZE];
    int size, key;

    printf("Enter the number of bears: ");
    scanf("%d", &size);

    generate_bears(bears, size);

    printf("\nList of bears:\n");

    for (int i = 0; i < size; i++) {
        printf("\nName: %s, Age: %d", bears[i].name, bears[i].age);
    }

    printf("\nEnter the age of the bear you want to search for: ");
    scanf("%d", &key);

    binary_bear_search(bears, size, key);

    return 0;
}