//Code Llama-13B DATASET v1.0 Category: Searching algorithm ; Style: automated
// C Searching Algorithm Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100

// Structure to represent an element
typedef struct {
    int key;
    char value[10];
} element_t;

// Structure to represent a list of elements
typedef struct {
    element_t* elements;
    int size;
    int capacity;
} list_t;

// Function to initialize a list
void init_list(list_t* list) {
    list->elements = (element_t*)malloc(sizeof(element_t) * MAX_ELEMENTS);
    list->size = 0;
    list->capacity = MAX_ELEMENTS;
}

// Function to add an element to the list
void add_element(list_t* list, int key, char* value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->elements = (element_t*)realloc(list->elements, sizeof(element_t) * list->capacity);
    }
    list->elements[list->size].key = key;
    strcpy(list->elements[list->size].value, value);
    list->size++;
}

// Function to search for an element in the list
int search_element(list_t* list, int key) {
    for (int i = 0; i < list->size; i++) {
        if (list->elements[i].key == key) {
            return i;
        }
    }
    return -1;
}

// Function to delete an element from the list
void delete_element(list_t* list, int index) {
    for (int i = index; i < list->size - 1; i++) {
        list->elements[i] = list->elements[i + 1];
    }
    list->size--;
}

// Function to print the list
void print_list(list_t* list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d %s\n", list->elements[i].key, list->elements[i].value);
    }
}

int main() {
    list_t list;
    init_list(&list);
    add_element(&list, 1, "apple");
    add_element(&list, 2, "banana");
    add_element(&list, 3, "cherry");
    add_element(&list, 4, "date");
    add_element(&list, 5, "elderberry");
    print_list(&list);
    printf("Searching for element with key 3: %d\n", search_element(&list, 3));
    delete_element(&list, 2);
    print_list(&list);
    return 0;
}