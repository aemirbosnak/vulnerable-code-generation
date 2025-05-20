//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: multivariable
/*
 * Building a CSV Reader example program in a multivariable style
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 100
#define MAX_LINE_LENGTH 1024

typedef struct {
    char** fields;
    int num_fields;
} csv_record_t;

csv_record_t* read_csv(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    csv_record_t* records = malloc(sizeof(csv_record_t));
    records->num_fields = 0;
    records->fields = malloc(sizeof(char*) * MAX_FIELDS);

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Split the line into fields
        char* field = strtok(line, ",");
        int i = 0;
        while (field != NULL && i < MAX_FIELDS) {
            records->fields[i] = field;
            i++;
            field = strtok(NULL, ",");
        }
        records->num_fields = i;
    }

    fclose(fp);
    return records;
}

int main() {
    csv_record_t* records = read_csv("example.csv");
    if (records == NULL) {
        fprintf(stderr, "Error reading CSV file\n");
        return 1;
    }

    // Print the records
    for (int i = 0; i < records->num_fields; i++) {
        printf("%s\n", records->fields[i]);
    }

    // Free the memory
    for (int i = 0; i < records->num_fields; i++) {
        free(records->fields[i]);
    }
    free(records->fields);
    free(records);

    return 0;
}