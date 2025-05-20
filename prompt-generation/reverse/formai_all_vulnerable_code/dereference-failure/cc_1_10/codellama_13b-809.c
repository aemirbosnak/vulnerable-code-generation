//Code Llama-13B DATASET v1.0 Category: Searching algorithm ; Style: scientific
// Example: Unique C Searching Algorithm Program in a Scientific Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of the data to be searched
typedef struct {
    int id;
    char name[30];
    char email[50];
    int age;
} Person;

// Define the structure of the data to be sorted
typedef struct {
    Person *data;
    int size;
} Data;

// Define the sorting function
void sort(Data *data) {
    // Sort the data in ascending order of age
    for (int i = 0; i < data->size - 1; i++) {
        for (int j = i + 1; j < data->size; j++) {
            if (data->data[i].age > data->data[j].age) {
                Person temp = data->data[i];
                data->data[i] = data->data[j];
                data->data[j] = temp;
            }
        }
    }
}

// Define the searching function
void search(Data *data, int age) {
    // Search for the first occurrence of the specified age
    for (int i = 0; i < data->size; i++) {
        if (data->data[i].age == age) {
            printf("Found %s at index %d\n", data->data[i].name, i);
            return;
        }
    }
    printf("No match found\n");
}

int main() {
    // Initialize the data
    Data data = {0};
    data.size = 5;
    data.data = malloc(data.size * sizeof(Person));

    // Populate the data
    data.data[0].id = 1;
    strcpy(data.data[0].name, "John");
    strcpy(data.data[0].email, "john@example.com");
    data.data[0].age = 25;

    data.data[1].id = 2;
    strcpy(data.data[1].name, "Jane");
    strcpy(data.data[1].email, "jane@example.com");
    data.data[1].age = 30;

    data.data[2].id = 3;
    strcpy(data.data[2].name, "Bob");
    strcpy(data.data[2].email, "bob@example.com");
    data.data[2].age = 35;

    data.data[3].id = 4;
    strcpy(data.data[3].name, "Alice");
    strcpy(data.data[3].email, "alice@example.com");
    data.data[3].age = 40;

    data.data[4].id = 5;
    strcpy(data.data[4].name, "Eve");
    strcpy(data.data[4].email, "eve@example.com");
    data.data[4].age = 45;

    // Sort the data
    sort(&data);

    // Search for the first occurrence of age 35
    search(&data, 35);

    // Free the allocated memory
    free(data.data);

    return 0;
}