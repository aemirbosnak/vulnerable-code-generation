//Code Llama-13B DATASET v1.0 Category: Data recovery tool ; Style: intelligent
// C Data recovery tool example program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store data
struct Data {
    int id;
    char name[50];
    char email[50];
};

// Function to read data from file
void read_data(struct Data *data) {
    FILE *fp;
    char line[100];

    // Open file for reading
    fp = fopen("data.txt", "r");

    // Check if file is valid
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read data from file
    while (fgets(line, 100, fp) != NULL) {
        // Split line into id and name
        char *id = strtok(line, " ");
        char *name = strtok(NULL, " ");

        // Add data to structure
        data->id = atoi(id);
        strcpy(data->name, name);
    }

    // Close file
    fclose(fp);
}

// Function to write data to file
void write_data(struct Data *data) {
    FILE *fp;
    char line[100];

    // Open file for writing
    fp = fopen("data.txt", "w");

    // Check if file is valid
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Write data to file
    for (int i = 0; i < 5; i++) {
        sprintf(line, "%d %s\n", data[i].id, data[i].name);
        fputs(line, fp);
    }

    // Close file
    fclose(fp);
}

// Main function
int main() {
    // Initialize data structure
    struct Data data[5];

    // Read data from file
    read_data(data);

    // Modify data
    data[0].id = 10;
    strcpy(data[0].name, "John");
    data[1].id = 20;
    strcpy(data[1].name, "Jane");
    data[2].id = 30;
    strcpy(data[2].name, "Bob");
    data[3].id = 40;
    strcpy(data[3].name, "Alice");
    data[4].id = 50;
    strcpy(data[4].name, "Eve");

    // Write modified data to file
    write_data(data);

    return 0;
}