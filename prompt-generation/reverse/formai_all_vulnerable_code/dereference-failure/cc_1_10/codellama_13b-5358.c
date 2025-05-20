//Code Llama-13B DATASET v1.0 Category: Searching algorithm ; Style: complex
/*
 * A unique C searching algorithm example program in a complex style
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STR_LEN 100

// Custom data structure for the list of strings
typedef struct {
    char** strings;
    int size;
    int capacity;
} StringList;

// Function to create a new string list
StringList* create_string_list(int capacity) {
    StringList* list = malloc(sizeof(StringList));
    list->strings = malloc(capacity * sizeof(char*));
    list->size = 0;
    list->capacity = capacity;
    return list;
}

// Function to add a string to the list
void add_string(StringList* list, char* string) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->strings = realloc(list->strings, list->capacity * sizeof(char*));
    }
    list->strings[list->size++] = string;
}

// Function to search for a string in the list
int search_string(StringList* list, char* string) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->strings[i], string) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to print the list
void print_list(StringList* list) {
    for (int i = 0; i < list->size; i++) {
        printf("%s\n", list->strings[i]);
    }
}

// Function to free the list
void free_list(StringList* list) {
    for (int i = 0; i < list->size; i++) {
        free(list->strings[i]);
    }
    free(list->strings);
    free(list);
}

int main() {
    StringList* list = create_string_list(10);

    add_string(list, "hello");
    add_string(list, "world");
    add_string(list, "goodbye");
    add_string(list, "world");

    int index = search_string(list, "world");
    printf("Index of 'world' in the list: %d\n", index);

    print_list(list);

    free_list(list);

    return 0;
}