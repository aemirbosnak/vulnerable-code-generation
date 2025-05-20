//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Welcome message
    printf("Welcome to the CSV Reader!");

    // Get the filename from the user
    char filename[50];
    printf("\nEnter the name of the file: ");
    scanf("%s", filename);

    // Open the file and check if it exists
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("\nFile not found!");
        exit(-1);
    }

    // Read the first line of the file, which contains the header
    char header[256];
    fgets(header, sizeof(header), file);
    printf("\nHeader: %s", header);

    // Count the number of columns in the header
    int num_columns = 1;
    for (int i = 0; i < strlen(header); i++) {
        if (header[i] == ',') {
            num_columns++;
        }
    }
    printf("\nNumber of columns: %d", num_columns);

    // Read the rest of the file and store the data in an array of structs
    struct Data {
        char col1[256];
        char col2[256];
        char col3[256];
    };
    struct Data data[100];
    int num_rows = 0;
    while (!feof(file)) {
        char row[256];
        fgets(row, sizeof(row), file);
        if (strlen(row) > 1) {
            sscanf(row, "%[^,],%[^,],%[^\n]", data[num_rows].col1, data[num_rows].col2, data[num_rows].col3);
            num_rows++;
        }
    }
    printf("\nNumber of rows: %d", num_rows);

    // Print out the data
    for (int i = 0; i < num_rows; i++) {
        printf("\nRow %d: %s, %s, %s", i+1, data[i].col1, data[i].col2, data[i].col3);
    }

    // Close the file and exit the program
    fclose(file);
    printf("\nDone.");
    return 0;
}