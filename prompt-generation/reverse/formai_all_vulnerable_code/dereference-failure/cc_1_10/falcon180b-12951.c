//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *key;
    int value;
} Entry;

void insert(Entry *arr, int n, char *key, int value) {
    if (n >= MAX_SIZE) {
        printf("Error: table is full\n");
        return;
    }

    int i = 0;
    while (i < n && strcmp(arr[i].key, key) < 1) {
        i++;
    }

    for (int j = n; j > i; j--) {
        strcpy(arr[j].key, arr[j - 1].key);
        arr[j].value = arr[j - 1].value;
    }

    strcpy(arr[i].key, key);
    arr[i].value = value;
    n++;
}

int search(Entry *arr, int n, char *key) {
    int i = 0;
    while (i < n && strcmp(arr[i].key, key) < 1) {
        i++;
    }

    if (i == n || strcmp(arr[i].key, key)!= 0) {
        return -1;
    }

    return arr[i].value;
}

void delete(Entry *arr, int n, char *key) {
    int i = 0;
    while (i < n && strcmp(arr[i].key, key) < 1) {
        i++;
    }

    if (i == n || strcmp(arr[i].key, key)!= 0) {
        printf("Error: key not found\n");
        return;
    }

    for (int j = i; j < n - 1; j++) {
        strcpy(arr[j].key, arr[j + 1].key);
        arr[j].value = arr[j + 1].value;
    }

    n--;
}

int main() {
    Entry table[MAX_SIZE];
    int n = 0;

    insert(table, n, "apple", 1);
    insert(table, n, "banana", 2);
    insert(table, n, "cherry", 3);
    insert(table, n, "date", 4);
    insert(table, n, "elderberry", 5);

    int search_result = search(table, n, "banana");
    printf("Search result: %d\n", search_result);

    delete(table, n, "cherry");

    search_result = search(table, n, "cherry");
    printf("Search result: %d\n", search_result);

    return 0;
}