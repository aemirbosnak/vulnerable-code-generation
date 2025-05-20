//Falcon-180B DATASET v1.0 Category: Memory management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for our data
struct data {
    int id;
    char name[20];
    float score;
};

// Function to allocate memory for our data
struct data* createData(int id, char* name, float score) {
    struct data* newData = (struct data*) malloc(sizeof(struct data));
    if (newData == NULL) {
        printf("Error: Memory allocation failed!\n");
        return NULL;
    }
    newData->id = id;
    strcpy(newData->name, name);
    newData->score = score;
    return newData;
}

// Function to print our data
void printData(struct data* data) {
    printf("ID: %d\n", data->id);
    printf("Name: %s\n", data->name);
    printf("Score: %.2f\n", data->score);
}

// Function to free memory for our data
void deleteData(struct data* data) {
    free(data);
    data = NULL;
}

int main() {
    // Allocate memory for our data
    struct data* student1 = createData(101, "John Doe", 85.5);
    struct data* student2 = createData(102, "Jane Smith", 90.0);

    // Print our data
    printData(student1);
    printData(student2);

    // Free memory for our data
    deleteData(student1);
    deleteData(student2);

    return 0;
}