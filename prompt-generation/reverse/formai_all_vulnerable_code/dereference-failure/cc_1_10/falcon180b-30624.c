//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 100

// Define the index structure
typedef struct {
    char index_name[20];
    int index_size;
    int *index_array;
} Index;

// Function to create an index
Index *create_index(char *index_name) {
    Index *index = (Index *) malloc(sizeof(Index));
    strcpy(index->index_name, index_name);
    index->index_size = 0;
    index->index_array = NULL;
    return index;
}

// Function to add a value to the index
void add_to_index(Index *index, int value) {
    int *new_array;
    int new_size = index->index_size + 1;
    new_array = (int *) realloc(index->index_array, new_size * sizeof(int));
    if (new_array == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    index->index_array = new_array;
    index->index_array[new_size - 1] = value;
    index->index_size = new_size;
}

// Function to search the index for a value
int search_index(Index *index, int value) {
    int i;
    for (i = 0; i < index->index_size; i++) {
        if (index->index_array[i] == value) {
            return i;
        }
    }
    return -1;
}

// Function to print the index
void print_index(Index *index) {
    int i;
    printf("Index: %s\n", index->index_name);
    printf("Size: %d\n", index->index_size);
    printf("Values:\n");
    for (i = 0; i < index->index_size; i++) {
        printf("%d\n", index->index_array[i]);
    }
}

// Main function to test the indexing system
int main() {
    Index *index = create_index("test_index");
    add_to_index(index, 10);
    add_to_index(index, 20);
    add_to_index(index, 30);
    print_index(index);
    int result = search_index(index, 20);
    if (result == -1) {
        printf("Value not found\n");
    } else {
        printf("Value found at index %d\n", result);
    }
    return 0;
}