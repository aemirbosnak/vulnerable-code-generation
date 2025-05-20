//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 50
#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 20

// Define a struct to hold the information for each row
typedef struct {
    char **fields;
    int num_fields;
} csv_row_t;

// Function to free the memory allocated for a csv_row_t
void free_csv_row(csv_row_t *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

// Function to read a row from a csv file
csv_row_t *read_csv_row(FILE *fp, char delimiter) {
    char line[MAX_LINE_LENGTH];
    if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) {
        return NULL;
    }
    int num_fields = 0;
    char **fields = malloc(MAX_FIELDS * sizeof(char *));
    char *token = strtok(line, &delimiter);
    while (token != NULL) {
        fields[num_fields] = malloc(MAX_FIELD_LENGTH * sizeof(char));
        strcpy(fields[num_fields], token);
        num_fields++;
        token = strtok(NULL, &delimiter);
    }
    csv_row_t *row = malloc(sizeof(csv_row_t));
    row->fields = fields;
    row->num_fields = num_fields;
    return row;
}

// Function to print a row of a csv file
void print_csv_row(csv_row_t *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s", row->fields[i]);
        if (i < row->num_fields - 1) {
            printf(",");
        }
    }
    printf("\n");
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    printf("Enter the name of the csv file to read: ");
    scanf("%s", file_name);
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", file_name);
        return 1;
    }
    char delimiter;
    printf("Enter the delimiter used in the csv file: ");
    scanf(" %c", &delimiter);
    printf("\n");
    csv_row_t *row;
    while ((row = read_csv_row(fp, delimiter)) != NULL) {
        print_csv_row(row);
        free_csv_row(row);
    }
    fclose(fp);
    return 0;
}