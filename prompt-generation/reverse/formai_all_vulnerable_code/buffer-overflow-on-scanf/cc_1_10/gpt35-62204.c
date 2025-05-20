//FormAI DATASET v1.0 Category: Data recovery tool ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold the data information
typedef struct {
    int id;
    char name[50];
    char location[50];
    float size;
} Data;

// Define functions for each task
Data* read_data(FILE* file, int* size);
void print_data(Data* data, int size);
void recover_data(Data* data, int size, char* file_name);

int main(void) {
    FILE* file;
    Data* data = NULL;
    int size = 0;
    char file_name[50];

    // Prompt user for file name
    printf("Enter file name: ");
    scanf("%s", file_name);

    // Open file for reading
    file = fopen(file_name, "rb");

    // Handle file read error
    if (file == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    // Read data from file
    data = read_data(file, &size);

    // Close file
    fclose(file);

    // Print recovered data
    printf("Recovered data:\n");
    print_data(data, size);

    // Write recovered data to new file
    recover_data(data, size, "recovered_data.txt");

    // Free memory used by data array
    free(data);

    return 0;
}

/*
 * Read data from file into an array of struct Data
 */
Data* read_data(FILE* file, int* size) {
    Data* data = NULL;
    int num_records = 0;

    // Read number of records from beginning of file
    fread(&num_records, sizeof(int), 1, file);

    // Allocate memory for data array
    data = (Data*) malloc(sizeof(Data) * num_records);

    // Read data from file
    fread(data, sizeof(Data), num_records, file);

    // Set size variable
    *size = num_records;

    return data;
}

/*
 * Print recovered data to console
 */
void print_data(Data* data, int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("ID: %d\n", data[i].id);
        printf("Name: %s\n", data[i].name);
        printf("Location: %s\n", data[i].location);
        printf("Size: %.2f KB\n", data[i].size);
        printf("\n");
    }
}

/*
 * Write recovered data to new file
 */
void recover_data(Data* data, int size, char* file_name) {
    FILE* file = fopen(file_name, "w");
    int i;

    // Write data to file
    for (i = 0; i < size; i++) {
        fprintf(file, "ID: %d\n", data[i].id);
        fprintf(file, "Name: %s\n", data[i].name);
        fprintf(file, "Location: %s\n", data[i].location);
        fprintf(file, "Size: %.2f KB\n", data[i].size);
        fprintf(file, "\n");
    }

    // Close file
    fclose(file);
}