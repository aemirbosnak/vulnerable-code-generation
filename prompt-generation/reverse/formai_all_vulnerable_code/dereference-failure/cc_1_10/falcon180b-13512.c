//Falcon-180B DATASET v1.0 Category: Memory management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store data
typedef struct data {
    int a;
    char b[10];
    float c;
} Data;

// Function to allocate memory for a new Data struct
Data* createData() {
    Data* newData = (Data*)malloc(sizeof(Data));
    if (newData == NULL) {
        printf("Error: Unable to allocate memory for new Data struct.\n");
        exit(1);
    }
    return newData;
}

// Function to copy data from one struct to another
void copyData(Data* dest, Data* src) {
    dest->a = src->a;
    strcpy(dest->b, src->b);
    dest->c = src->c;
}

// Function to free memory used by a Data struct
void destroyData(Data* data) {
    free(data);
}

// Function to print the contents of a Data struct
void printData(Data* data) {
    printf("a: %d\n", data->a);
    printf("b: %s\n", data->b);
    printf("c: %f\n", data->c);
}

int main() {
    // Create a new Data struct
    Data* data1 = createData();

    // Set some values for the data
    data1->a = 42;
    strcpy(data1->b, "Hello, world!");
    data1->c = 3.14;

    // Print the initial data
    printf("Initial data:\n");
    printData(data1);

    // Create a copy of the data
    Data* data2 = (Data*)malloc(sizeof(Data));
    copyData(data2, data1);

    // Print the copied data
    printf("\nCopied data:\n");
    printData(data2);

    // Free the memory used by the original data
    destroyData(data1);

    // Print the original data again (should be all zeros)
    printf("\nOriginal data after being freed:\n");
    printData(data1);

    return 0;
}