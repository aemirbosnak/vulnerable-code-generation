//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define MAX_FIELDS 10

char filename[MAX_LENGTH];

int main()
{
    printf("Enter CSV file name with extension: ");
    scanf("%s", filename);

    // Open CSV file for reading
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    // Declare variables for reading CSV rows and fields
    char row[MAX_LENGTH];
    char* fields[MAX_FIELDS];
    char* field;

    int num_fields;

    // Read and print CSV headers
    if (fgets(row, MAX_LENGTH, file) != NULL) {
        printf("CSV headers: %s", row);
    }

    // Read and print CSV data
    while (fgets(row, MAX_LENGTH, file) != NULL) {
        // Parse row into fields
        num_fields = 0;
        field = strtok(row, ",");
        while (field != NULL && num_fields < MAX_FIELDS) {
            fields[num_fields++] = field;
            field = strtok(NULL, ",");
        }

        // Print fields in row
        printf("CSV row: ");
        for (int i=0; i<num_fields; i++) {
            printf("%s", fields[i]);
        }
        printf("\n");
    }

    // Close CSV file
    fclose(file);

    return 0;
}