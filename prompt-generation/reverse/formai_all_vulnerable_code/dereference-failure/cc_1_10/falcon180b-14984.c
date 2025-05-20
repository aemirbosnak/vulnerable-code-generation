//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// define a struct for the data we will be searching through
typedef struct {
    int value;
    char name[50];
} data_t;

// define a function for comparing two data_t objects
int compare_data(const void *a, const void *b) {
    data_t *data_a = (data_t *)a;
    data_t *data_b = (data_t *)b;
    
    if (data_a->value == data_b->value) {
        return 0;
    } else if (data_a->value > data_b->value) {
        return 1;
    } else {
        return -1;
    }
}

// define a function for printing a data_t object
void print_data(data_t *data) {
    printf("Value: %d, Name: %s\n", data->value, data->name);
}

// define a function for sorting an array of data_t objects
void sort_data(data_t *data, int n) {
    qsort(data, n, sizeof(data_t), compare_data);
}

// define a function for searching through an array of data_t objects
int search_data(data_t *data, int n, int value) {
    data_t *result = bsearch(&value, data, n, sizeof(data_t), compare_data);
    
    if (result == NULL) {
        return -1;
    } else {
        return result - data;
    }
}

int main() {
    // create an array of data_t objects
    data_t data[] = {
        {1, "Alice"},
        {3, "Bob"},
        {2, "Charlie"},
        {4, "Dave"},
        {5, "Eve"}
    };
    
    // sort the array
    sort_data(data, 5);
    
    // print the sorted array
    printf("Sorted data:\n");
    for (int i = 0; i < 5; i++) {
        print_data(&data[i]);
    }
    
    // search for a value in the array
    int index = search_data(data, 5, 2);
    
    if (index == -1) {
        printf("Value not found.\n");
    } else {
        print_data(&data[index]);
    }
    
    return 0;
}