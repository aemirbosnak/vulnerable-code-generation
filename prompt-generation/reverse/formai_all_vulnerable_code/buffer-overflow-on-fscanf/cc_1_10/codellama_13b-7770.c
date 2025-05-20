//Code Llama-13B DATASET v1.0 Category: Database simulation ; Style: grateful
// Grateful C Database Simulation Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store data in database
typedef struct {
    char name[50];
    char email[50];
    int age;
} Person;

// Function to add data to database
void addData(Person* data) {
    FILE* file = fopen("data.txt", "a");
    fprintf(file, "%s %s %d\n", data->name, data->email, data->age);
    fclose(file);
}

// Function to search data in database
void searchData(Person* data) {
    FILE* file = fopen("data.txt", "r");
    while (fscanf(file, "%s %s %d", data->name, data->email, &data->age) == 3) {
        if (strcmp(data->name, data->name) == 0) {
            printf("Name: %s\n", data->name);
            printf("Email: %s\n", data->email);
            printf("Age: %d\n", data->age);
        }
    }
    fclose(file);
}

// Function to update data in database
void updateData(Person* data) {
    FILE* file = fopen("data.txt", "r");
    while (fscanf(file, "%s %s %d", data->name, data->email, &data->age) == 3) {
        if (strcmp(data->name, data->name) == 0) {
            fclose(file);
            file = fopen("data.txt", "w");
            fprintf(file, "%s %s %d\n", data->name, data->email, data->age);
            fclose(file);
        }
    }
    fclose(file);
}

// Function to delete data from database
void deleteData(Person* data) {
    FILE* file = fopen("data.txt", "r");
    while (fscanf(file, "%s %s %d", data->name, data->email, &data->age) == 3) {
        if (strcmp(data->name, data->name) == 0) {
            fclose(file);
            file = fopen("data.txt", "w");
            fprintf(file, "%s %s %d\n", data->name, data->email, data->age);
            fclose(file);
        }
    }
    fclose(file);
}

int main() {
    Person data;

    // Add data to database
    strcpy(data.name, "John");
    strcpy(data.email, "john@example.com");
    data.age = 30;
    addData(&data);

    // Search data in database
    strcpy(data.name, "John");
    searchData(&data);

    // Update data in database
    strcpy(data.name, "John");
    strcpy(data.email, "john123@example.com");
    data.age = 31;
    updateData(&data);

    // Search data in database
    strcpy(data.name, "John");
    searchData(&data);

    // Delete data from database
    strcpy(data.name, "John");
    deleteData(&data);

    // Search data in database
    strcpy(data.name, "John");
    searchData(&data);

    return 0;
}