//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELDS   128
#define MAX_FIELD_LEN 128

int main(int argc, char *argv[])
{
    // Check command line args
    if (argc != 2) {
        fprintf(stderr, "Error: Usage: %s csv_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    // Open the CSV file
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Read the first line of the CSV file to determine the number of fields
    char line[MAX_LINE_LEN];
    if (!fgets(line, MAX_LINE_LEN, fp)) {
        fprintf(stderr, "Error: Empty file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Split the first line into fields and count them
    char *fields[MAX_FIELDS];
    int num_fields = 0;
    char *tok = strtok(line, ",");
    while (tok != NULL && num_fields < MAX_FIELDS) {
        fields[num_fields++] = tok;
        tok = strtok(NULL, ",");
    }
    if (num_fields == MAX_FIELDS) {
        fprintf(stderr, "Error: Too many fields in file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Verify that all field names are alphanumeric
    for (int i = 0; i < num_fields; i++) {
        char *field = fields[i];
        for (int j = 0; j < strlen(field); j++) {
            if (!isalnum(field[j])) {
                fprintf(stderr, "Error: Invalid field name in file %s\n", argv[1]);
                exit(EXIT_FAILURE);
            }
        } 
    }

    // Read the remaining lines of the CSV file
    char values[num_fields][MAX_FIELD_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)) {
        if (strlen(line) == 0 || line[0] == '\n') {
            continue;
        }

        // Split the line into fields and count them
        char *tok = strtok(line, ",");
        int field_count = 0;
        while (tok != NULL && field_count < num_fields) {
            strcpy(values[field_count++], tok);
            tok = strtok(NULL, ",");
        }
        if (field_count != num_fields) {
            fprintf(stderr, "Error: Mismatched field count in file %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }

        // Verify that all field values are alphanumeric
        for (int i = 0; i < num_fields; i++) {
            char *value = values[i];
            for (int j = 0; j < strlen(value); j++) {
                if (!isalnum(value[j])) {
                    fprintf(stderr, "Error: Invalid field value in file %s\n", argv[1]);
                    exit(EXIT_FAILURE);
                }
            } 
        }
    }

    // Close the CSV file
    fclose(fp);

    printf("Successfully read CSV file %s with %d fields.\n", argv[1], num_fields);

    return EXIT_SUCCESS;
}