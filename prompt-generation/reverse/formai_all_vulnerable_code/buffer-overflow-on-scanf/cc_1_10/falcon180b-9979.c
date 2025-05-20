//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *key;
    int value;
} Pair;

void swap(Pair *a, Pair *b) {
    Pair temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void *a, const void *b) {
    Pair *p1 = (Pair *)a;
    Pair *p2 = (Pair *)b;
    return strcmp(p1->key, p2->key);
}

Pair *search(Pair *arr, int size, char *key) {
    qsort(arr, size, sizeof(Pair), compare);
    Pair *result = NULL;
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].key, key) == 0) {
            result = &arr[i];
            break;
        }
    }
    return result;
}

int main() {
    Pair arr[MAX_SIZE];
    int size = 0;
    char key[MAX_SIZE];
    while (scanf("%s", key)!= EOF) {
        if (size == MAX_SIZE) {
            printf("Error: Array is full.\n");
            exit(1);
        }
        arr[size].key = strdup(key);
        scanf("%d", &arr[size].value);
        size++;
    }
    qsort(arr, size, sizeof(Pair), compare);
    for (int i = 0; i < size; i++) {
        printf("%s %d\n", arr[i].key, arr[i].value);
    }
    char search_key[MAX_SIZE];
    while (scanf("%s", search_key)!= EOF) {
        Pair *result = search(arr, size, search_key);
        if (result == NULL) {
            printf("Element not found.\n");
        } else {
            printf("Element found: %s %d\n", result->key, result->value);
        }
    }
    return 0;
}