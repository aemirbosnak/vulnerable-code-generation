//Code Llama-13B DATASET v1.0 Category: Searching algorithm ; Style: Linus Torvalds
/*
 * A unique C Searching algorithm example program in a Linus Torvalds style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024
#define MAX_ARRAY_LENGTH 100

typedef struct {
    char *key;
    int value;
} KeyValuePair;

void print_array(KeyValuePair arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", arr[i].key, arr[i].value);
    }
}

void bubble_sort(KeyValuePair arr[], int size) {
    int swapped;
    int i;
    int j;
    int temp;

    do {
        swapped = 0;
        for (i = 0; i < size - 1; i++) {
            if (strcmp(arr[i].key, arr[i + 1].key) > 0) {
                temp = arr[i].value;
                arr[i].value = arr[i + 1].value;
                arr[i + 1].value = temp;

                temp = arr[i].key;
                arr[i].key = arr[i + 1].key;
                arr[i + 1].key = temp;

                swapped = 1;
            }
        }
    } while (swapped);
}

int linear_search(KeyValuePair arr[], int size, char *key) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].key, key) == 0) {
            return arr[i].value;
        }
    }
    return -1;
}

int main() {
    KeyValuePair arr[MAX_ARRAY_LENGTH] = {
        {"apple", 1},
        {"banana", 2},
        {"cherry", 3},
        {"date", 4},
        {"egg", 5},
        {"fig", 6},
        {"grape", 7},
        {"honey", 8},
        {"ice cream", 9},
        {"jelly", 10}
    };

    bubble_sort(arr, MAX_ARRAY_LENGTH);
    print_array(arr, MAX_ARRAY_LENGTH);

    char key[MAX_STRING_LENGTH];
    printf("Enter a key to search: ");
    scanf("%s", key);

    int value = linear_search(arr, MAX_ARRAY_LENGTH, key);
    if (value != -1) {
        printf("%s found at index %d\n", key, value);
    } else {
        printf("%s not found\n", key);
    }

    return 0;
}