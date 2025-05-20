//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELD_LEN 256

int main(int argc, char *argv[]) {

    // check if the input file is provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s input_file.csv\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // open the input file
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Failed to open input file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // allocate memory for the line buffer
    char *line = (char*) malloc(MAX_LINE_LEN * sizeof(char));
    if (line == NULL) {
        fprintf(stderr, "Failed to allocate memory for line buffer\n");
        exit(EXIT_FAILURE);
    }

    // allocate memory for the field buffer
    char *field = (char*) malloc(MAX_FIELD_LEN * sizeof(char));
    if (field == NULL) {
        fprintf(stderr, "Failed to allocate memory for field buffer\n");
        exit(EXIT_FAILURE);
    }

    // read the first line as the header
    if (fgets(line, MAX_LINE_LEN, input_file) == NULL) {
        fprintf(stderr, "Failed to read header from input file\n");
        exit(EXIT_FAILURE);
    }

    // count the number of fields in the header
    int num_fields = 1;
    char *ptr = line;
    while ((ptr = strchr(ptr, ',')) != NULL) {
        ptr++;
        num_fields++;
    }

    // allocate memory for the field names
    char **field_names = (char**) malloc(num_fields * sizeof(char*));
    if (field_names == NULL) {
        fprintf(stderr, "Failed to allocate memory for field names\n");
        exit(EXIT_FAILURE);
    }

    // parse the field names from the header
    ptr = strtok(line, ",");
    int i = 0;
    while (ptr != NULL && i < num_fields) {
        // remove the newline character from the end of the field name
        char *newline = strchr(ptr, '\n');
        if (newline != NULL) {
            *newline = '\0';
        }
        // allocate memory for the field name
        field_names[i] = (char*) malloc(strlen(ptr) + 1);
        if (field_names[i] == NULL) {
            fprintf(stderr, "Failed to allocate memory for field name\n");
            exit(EXIT_FAILURE);
        }
        // copy the field name to the allocated memory
        strcpy(field_names[i], ptr);
        ptr = strtok(NULL, ",");
        i++;
    }

    // read the rest of the lines as data records
    while (fgets(line, MAX_LINE_LEN, input_file) != NULL) {
        int field_index = 0;
        ptr = strtok(line, ",");
        while (ptr != NULL && field_index < num_fields) {
            // remove the newline character from the end of the field value
            char *newline = strchr(ptr, '\n');
            if (newline != NULL) {
                *newline = '\0';
            }
            // allocate memory for the field value
            int len = strlen(ptr);
            field[field_index] = (char*) malloc(len + 1);
            if (field[field_index] == NULL) {
                fprintf(stderr, "Failed to allocate memory for field value\n");
                exit(EXIT_FAILURE);
            }
            // copy the field value to the allocated memory
            strcpy(field[field_index], ptr);
            ptr = strtok(NULL, ",");
            field_index++;
        }
        // print the data record
        for (i = 0; i < num_fields; i++) {
            printf("%s=%s ", field_names[i], field[i]);
            free(field[i]);
        }
        printf("\n");
    }

    // free the memory allocated for field names and field values
    for (i = 0; i < num_fields; i++) {
        free(field_names[i]);
    }
    free(field_names);
    free(field);

    // free the memory allocated for the line buffer and close the input file
    free(line);
    fclose(input_file);

    return 0;
}