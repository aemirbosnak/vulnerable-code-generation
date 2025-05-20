//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of CSV fields in a row
#define MAX_FIELDS 10

// Define maximum length of each CSV field
#define MAX_LENGTH 20

int main() {
    FILE *fp;
    char filename[50];
    char fields[MAX_FIELDS][MAX_LENGTH];
    char line[MAX_FIELDS * MAX_LENGTH];
    int row = 0, field = 0;

    // Ask user for filename
    printf("Enter CSV filename: ");
    scanf("%s", filename);

    // Open CSV file
    fp = fopen(filename, "r");

    // Check if file exists
    if (fp == NULL) {
        printf("Error: File not found\n");
        return 1;
    }

    // Read each line in CSV file
    while (fgets(line, sizeof(line), fp)) {
        // Remove newline character from line
        line[strcspn(line, "\n")] = 0;

        // Split line into CSV fields
        char *p = strtok(line, ",");
        while (p) {
            // Copy field to array
            strcpy(fields[field], p);

            // Increment field index
            field++;

            // Check if too many fields in row
            if (field > MAX_FIELDS) {
                printf("Error: Too many fields in row %d\n", row);
                return 1;
            }

            // Get next field
            p = strtok(NULL, ",");
        }

        // Check if too few fields in row
        if (field < MAX_FIELDS) {
            printf("Error: Too few fields in row %d\n", row);
            return 1;
        }

        // Print row with fields
        printf("Row %d: ", row);
        for (int i = 0; i < MAX_FIELDS; i++) {
            printf("%s ", fields[i]);
        }
        printf("\n");

        // Reset field index for next row
        field = 0;

        // Increment row index
        row++;
    }

    // Close CSV file
    fclose(fp);

    return 0;
}