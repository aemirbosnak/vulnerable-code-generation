//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *key;
    int value;
} Entry;

int compare(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void swap(Entry *a, Entry *b) {
    char *temp = a->key;
    a->key = b->key;
    b->key = temp;
    
    int temp_val = a->value;
    a->value = b->value;
    b->value = temp_val;
}

int partition(Entry arr[], int low, int high) {
    Entry pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (compare(arr + j, &pivot) < 0) {
            swap(arr + j, arr + i + 1);
            i++;
        }
    }
    swap(arr + i + 1, arr + high);
    return i + 1;
}

void quicksort(Entry arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void print_entries(Entry arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s -> %d\n", arr[i].key, arr[i].value);
    }
}

int main() {
    Entry arr[MAX_SIZE];
    int size = 0;
    
    char key[MAX_SIZE];
    int value;
    while (fgets(key, MAX_SIZE, stdin)!= NULL) {
        if (size >= MAX_SIZE) {
            printf("Error: Maximum size exceeded.\n");
            exit(1);
        }
        
        value = atoi(strtok(key, " "));
        arr[size].key = strdup(key);
        arr[size].value = value;
        size++;
    }
    
    quicksort(arr, 0, size - 1);
    print_entries(arr, size);
    
    for (int i = 0; i < size; i++) {
        free(arr[i].key);
    }
    free(arr);
    
    return 0;
}