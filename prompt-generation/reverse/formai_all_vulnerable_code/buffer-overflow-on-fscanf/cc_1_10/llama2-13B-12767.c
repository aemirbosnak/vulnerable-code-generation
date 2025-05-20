//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the structure to store the data
struct data {
    char name[50];
    int age;
    float salary;
};

// Define the function to read data from the database
struct data *read_data(const char *file_name) {
    // Open the file in read mode
    FILE *file = fopen(file_name, "r");

    // Check if the file is empty
    if (feof(file)) {
        // If the file is empty, return NULL
        return NULL;
    }

    // Read the data from the file
    struct data *data = malloc(sizeof(struct data));
    fscanf(file, "%s %d %f", data->name, &data->age, &data->salary);

    // Close the file
    fclose(file);

    return data;
}

// Define the function to write data to the database
void write_data(const char *file_name, struct data *data) {
    // Open the file in write mode
    FILE *file = fopen(file_name, "w");

    // Write the data to the file
    fprintf(file, "%s %d %f", data->name, data->age, data->salary);

    // Close the file
    fclose(file);
}

int main() {
    // Create a data structure to store the data
    struct data data = {
        .name = "Alice",
        .age = 25,
        .salary = 50000.0
    };

    // Read the data from the database
    struct data *db_data = read_data("data.dat");

    // If the data is not found in the database, insert it
    if (db_data == NULL) {
        write_data("data.dat", &data);
        db_data = read_data("data.dat");
    }

    // Print the data from the database
    printf("Name: %s, Age: %d, Salary: %f\n", db_data->name, db_data->age, db_data->salary);

    // Update the data in the database
    db_data->salary = 60000.0;
    write_data("data.dat", db_data);

    // Print the updated data from the database
    printf("Name: %s, Age: %d, Salary: %f\n", db_data->name, db_data->age, db_data->salary);

    return 0;
}