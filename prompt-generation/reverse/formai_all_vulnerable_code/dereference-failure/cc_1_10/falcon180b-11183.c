//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

// Function to split a string into an array of strings using a delimiter
int split(char *str, char delimiter, char ***result) {
    char *token = strtok(str, delimiter);
    int count = 0;
    while (token!= NULL) {
        count++;
        char **array = realloc(*result, sizeof(char *) * count);
        if (array == NULL) {
            for (int i = 0; i < count - 1; i++) {
                free(*result[i]);
            }
            free(*result);
            return -1;
        }
        *result = array;
        (*result)[count - 1] = strdup(token);
        token = strtok(NULL, delimiter);
    }
    return count;
}

// Function to read a CSV file and print its contents
void read_csv(FILE *file) {
    char line[MAX_LINE_SIZE];
    char delimiter = ',';
    char **header = NULL;
    int header_count = 0;
    int row_count = 0;
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        row_count++;
        if (header == NULL) {
            header = malloc(sizeof(char *));
            header_count = split(line, delimiter, &header);
            if (header_count <= 0) {
                printf("Error: Invalid CSV format.\n");
                exit(1);
            }
        } else {
            char **row = malloc(sizeof(char *) * header_count);
            int cell_count = split(line, delimiter, &row);
            if (cell_count!= header_count) {
                printf("Error: Invalid CSV format in row %d.\n", row_count);
                exit(1);
            }
            for (int i = 0; i < header_count; i++) {
                printf("%s: %s\n", header[i], row[i]);
            }
            for (int i = 0; i < header_count; i++) {
                free(row[i]);
            }
            free(row);
        }
    }
    if (header!= NULL) {
        for (int i = 0; i < header_count; i++) {
            free(header[i]);
        }
        free(header);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        exit(1);
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    read_csv(file);
    fclose(file);
    return 0;
}