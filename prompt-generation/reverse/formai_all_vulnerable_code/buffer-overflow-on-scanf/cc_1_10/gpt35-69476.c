//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define MAX_COLUMNS 10

int main() {
    char filename[MAX_LENGTH];
    printf("Enter file name: ");
    scanf("%s", filename);
    
    // Open file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file: %s\n", filename);
        return 1;
    }

    // Read header
    char header[MAX_LENGTH];
    fgets(header, MAX_LENGTH, file);

    // Parse header
    int num_columns = 0;
    char *column_names[MAX_COLUMNS];
    column_names[num_columns] = strtok(header, ",");
    while (column_names[num_columns] != NULL && num_columns < MAX_COLUMNS) {
        num_columns++;
        column_names[num_columns] = strtok(NULL, ",");
    }

    // Read data
    char data[MAX_COLUMNS][MAX_LENGTH];
    int row_number = 1;
    while (fgets(data[0], MAX_LENGTH, file)) {
        int i = 1;
        while (i < num_columns && fgets(data[i], MAX_LENGTH, file)) {
            i++;
        }
        row_number++;

        // Do something with the data
        printf("Row %d:\n", row_number);
        for (int j = 0; j < num_columns; j++) {
            printf("%s: %s", column_names[j], data[j]);
        }
    }

    // Close file
    fclose(file);
    return 0;
}