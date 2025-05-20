//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records and attributes
#define MAX_RECORDS 1000
#define MAX_ATTRIBUTES 100

// Define the data structure for a record
typedef struct {
    char attributes[MAX_ATTRIBUTES][50];
    int class_label;
} record_t;

// Define the data structure for the data set
typedef struct {
    record_t records[MAX_RECORDS];
    int num_records;
    int num_attributes;
} data_set_t;

// Read the data set from a file
data_set_t *read_data_set(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    data_set_t *data_set = malloc(sizeof(data_set_t));
    if (data_set == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return NULL;
    }

    // Read the number of records and attributes
    fscanf(fp, "%d %d", &data_set->num_records, &data_set->num_attributes);

    // Read the records
    for (int i = 0; i < data_set->num_records; i++) {
        for (int j = 0; j < data_set->num_attributes; j++) {
            fscanf(fp, "%s", data_set->records[i].attributes[j]);
        }
        fscanf(fp, "%d", &data_set->records[i].class_label);
    }

    fclose(fp);

    return data_set;
}

// Print the data set
void print_data_set(data_set_t *data_set) {
    for (int i = 0; i < data_set->num_records; i++) {
        for (int j = 0; j < data_set->num_attributes; j++) {
            printf("%s ", data_set->records[i].attributes[j]);
        }
        printf("%d\n", data_set->records[i].class_label);
    }
}

// Free the memory allocated for the data set
void free_data_set(data_set_t *data_set) {
    free(data_set);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    data_set_t *data_set = read_data_set(argv[1]);
    if (data_set == NULL) {
        return EXIT_FAILURE;
    }

    print_data_set(data_set);

    free_data_set(data_set);

    return EXIT_SUCCESS;
}