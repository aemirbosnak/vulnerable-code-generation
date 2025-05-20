//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_RECORD_LENGTH 256
#define MAX_FIELD_LENGTH 32

int main(int argc, char *argv[]) {
    char *filename;
    if (argc == 2) {
        filename = argv[1];
    } else {
        printf("Please provide the file name as an argument.\n");
        return 1;
    }

    printf("Opening file %s...\n", filename);
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file %s.\n", filename);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char record[MAX_RECORD_LENGTH][MAX_FIELD_LENGTH];
    int record_count = 0;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        // Remove newline character
        line[strcspn(line, "\n")] = 0;

        // Check for buffer overflow
        if (strlen(line) >= MAX_LINE_LENGTH - 1) {
            printf("Line too long: %s\n", line);
            return 1;
        }

        // Check for record overflow
        if (record_count >= MAX_RECORD_LENGTH) {
            printf("Too many records.\n");
            return 1;
        }

        // Parse fields
        char *field = strtok(line, ",");
        int field_count = 0;
        while (field != NULL) {
            // Remove leading/trailing whitespace
            int i = 0;
            while (field[i] == ' ' || field[i] == '\t') {
                i++;
            }
            memmove(&field[0], &field[i], strlen(field) - i + 1);
            i = strlen(field) - 1;
            while (field[i] == ' ' || field[i] == '\t') {
                field[i] = 0;
                i--;
            }

            // Check for field overflow
            if (strlen(field) >= MAX_FIELD_LENGTH) {
                printf("Field too long: %s\n", field);
                return 1;
            }

            // Add field to record
            strcpy(record[field_count], field);
            field_count++;

            // Get next field
            field = strtok(NULL, ",");
        }

        // Check for missing fields
        if (field_count == 0) {
            printf("Missing fields: %s\n", line);
            return 1;
        }
        if (field_count < 3) {
            printf("Not enough fields: %s\n", line);
            return 1;
        }
        if (field_count > 3) {
            printf("Too many fields: %s\n", line);
            return 1;
        }

        // Process record
        printf("Processing record %d:\n", record_count);
        printf("Name: %s\n", record[0]);
        printf("Age: %s\n", record[1]);
        printf("City: %s\n", record[2]);
        printf("\n");

        record_count++;
    }

    printf("Processed %d records.\n", record_count);

    fclose(file);
    return 0;
}