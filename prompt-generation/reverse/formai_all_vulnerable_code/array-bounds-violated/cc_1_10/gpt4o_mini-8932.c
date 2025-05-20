//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

// Function prototypes
void parse_csv_line(char *line, char *fields[], int *num_fields);
void print_fields(char *fields[], int num_fields);

int main(int argc, char *argv[]) {
    // Input validation
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Could not open file");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    char *fields[MAX_FIELDS];
    int num_fields;

    // Read and parse each line in the CSV file
    while (fgets(line, sizeof(line), file)) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0'; // Remove newline character
        }
        
        parse_csv_line(line, fields, &num_fields);
        print_fields(fields, num_fields);
    }

    fclose(file);
    return EXIT_SUCCESS;
}

// Function to parse a CSV line
void parse_csv_line(char *line, char *fields[], int *num_fields) {
    char *token;
    *num_fields = 0;
    
    // Get the first token
    token = strtok(line, ",");
    while (token != NULL && *num_fields < MAX_FIELDS) {
        fields[(*num_fields)++] = strdup(token); // Dynamically allocate memory for the field
        token = strtok(NULL, ",");
    }
}

// Function to print fields
void print_fields(char *fields[], int num_fields) {
    printf("Parsed Fields:\n");
    for (int i = 0; i < num_fields; i++) {
        printf("Field %d: %s\n", i + 1, fields[i]);
        free(fields[i]); // Free the dynamically allocated memory
    }
    printf("\n");
}