//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELD_LEN 1024
#define DELIMITER ","

// Function to split a line of text into fields based on a delimiter
void split_line(char* line, char** fields) {
    int num_fields = 0;
    char* field = line;
    char* delimiter_pos = strchr(line, DELIMITER);

    // Count the number of fields
    while (delimiter_pos!= NULL) {
        num_fields++;
        delimiter_pos = strchr(delimiter_pos + 1, DELIMITER);
    }
    num_fields++;

    // Allocate memory for each field
    fields[0] = malloc(MAX_FIELD_LEN);
    strcpy(fields[0], field);
    fields[num_fields - 1] = malloc(MAX_FIELD_LEN);
    strcpy(fields[num_fields - 1], "");

    // Split the line into fields
    for (int i = 1; i < num_fields - 1; i++) {
        delimiter_pos = strchr(field, DELIMITER);
        int field_len = delimiter_pos - field;
        fields[i] = malloc(field_len + 1);
        strncpy(fields[i], field, field_len);
        fields[i][field_len] = '\0';
        field = delimiter_pos + 1;
    }
}

// Function to read a CSV file and print each line of data
void read_csv_file(FILE* file) {
    char line[MAX_LINE_LEN];
    char** fields;

    while (fgets(line, MAX_LINE_LEN, file)!= NULL) {
        fields = malloc(MAX_FIELD_LEN * (MAX_FIELD_LEN + 1));
        split_line(line, fields);

        for (int i = 0; i < MAX_FIELD_LEN; i++) {
            if (fields[i]!= NULL) {
                printf("%s\t", fields[i]);
            }
        }
        printf("\n");

        for (int i = 0; i < MAX_FIELD_LEN; i++) {
            if (fields[i]!= NULL) {
                free(fields[i]);
            }
        }
        free(fields);
    }
}

int main() {
    FILE* file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    read_csv_file(file);

    fclose(file);
    return 0;
}