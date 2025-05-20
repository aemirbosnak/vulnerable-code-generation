//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Define struct to store each CSV row
struct DataRow {
    int id;
    char name[MAX_LINE_LENGTH];
    double salary;
};

int main(int argc, char** argv) {
    // Check if a filename was provided as command line argument
    if (argc < 2) {
        printf("Please provide a filename as command line argument.\n");
        return 1;
    }

    // Open the file for reading
    FILE* file = fopen(argv[1], "r");
    if (!file) {
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    // Allocate memory for storing the rows of the CSV file
    struct DataRow* dataRows = (struct DataRow*) malloc(sizeof(struct DataRow));
    int numDataRows = 0;

    // Read the file line by line
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        // Strip the newline character from the line
        int lineLen = strlen(line);
        if (line[lineLen-1] == '\n') {
            line[lineLen-1] = '\0';
        }

        // Split the line into fields using comma as the delimiter
        char* idStr = strtok(line, ",");
        char* nameStr = strtok(NULL, ",");
        char* salaryStr = strtok(NULL, ",");

        // Convert the fields to their respective types
        int id = atoi(idStr);
        char name[MAX_LINE_LENGTH];
        strncpy(name, nameStr, MAX_LINE_LENGTH);
        double salary = atof(salaryStr);

        // Store the row in memory
        dataRows = (struct DataRow*) realloc(dataRows, (numDataRows+1) * sizeof(struct DataRow));
        dataRows[numDataRows].id = id;
        strncpy(dataRows[numDataRows].name, name, MAX_LINE_LENGTH);
        dataRows[numDataRows].salary = salary;
        numDataRows++;
    }

    // Close the file
    fclose(file);

    // Print the data rows
    for (int i = 0; i < numDataRows; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", dataRows[i].id, dataRows[i].name, dataRows[i].salary);
    }

    // Free the allocated memory
    free(dataRows);

    return 0;
}