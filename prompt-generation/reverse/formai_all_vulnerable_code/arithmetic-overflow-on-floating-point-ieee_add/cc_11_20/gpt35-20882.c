//FormAI DATASET v1.0 Category: Data mining ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELDS 10

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: datamine <filename>\n");
        exit(1);
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Can't open file %s\n", filename);
        exit(1);
    }

    int num_fields;
    char field_names[MAX_FIELDS][MAX_LINE_SIZE];
    float data[MAX_FIELDS] = {0};
    while (!feof(file)) {
        char line[MAX_LINE_SIZE] = {0};
        if (fgets(line, MAX_LINE_SIZE, file)) {
            char *token = strtok(line, ",");
            num_fields = 0;
            while (token) {
                if (num_fields < MAX_FIELDS) {
                    strncpy(field_names[num_fields], token, MAX_LINE_SIZE);
                    num_fields++;
                }
                token = strtok(NULL, ",");
            }
            break;
        }
    }

    printf("Found %d fields:\n", num_fields);
    for (int i = 0; i < num_fields; i++) {
        printf("%s", field_names[i]);
    }

    int num_records = 0;
    float sum_data[MAX_FIELDS] = {0};
    while (!feof(file)) {
        char line[MAX_LINE_SIZE] = {0};
        if (fgets(line, MAX_LINE_SIZE, file)) {
            char *token = strtok(line, ",");
            int field_index = 0;
            while (token) {
                if (field_index < num_fields) {
                    data[field_index] = atof(token);
                    sum_data[field_index] += data[field_index];
                    field_index++;
                }
                token = strtok(NULL, ",");
            }
            num_records++;
        }
    }

    printf("Processed %d records\n", num_records);
    printf("Average values:\n");
    for (int i = 0; i < num_fields; i++) {
        printf("%s: %.2f\n", field_names[i], sum_data[i] / num_records);
    }

    fclose(file);
    return 0;
}