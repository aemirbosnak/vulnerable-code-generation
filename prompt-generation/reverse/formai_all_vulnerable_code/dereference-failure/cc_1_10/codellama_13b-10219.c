//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: dynamic
/*
 * csv_reader.c
 *
 *  Created on: 02/12/2022
 *      Author: 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define DELIMITER ','

typedef struct {
    char *line;
    char *fields[MAX_FIELD_LENGTH];
    int num_fields;
} csv_record;

void csv_reader(FILE *fp, csv_record *record) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        // Ignore empty lines
        if (strlen(line) == 0) {
            continue;
        }

        // Split the line into fields
        char *field = strtok(line, DELIMITER);
        int i = 0;
        while (field) {
            record->fields[i++] = field;
            field = strtok(NULL, DELIMITER);
        }
        record->num_fields = i;

        // Print the record
        printf("Record: %s\n", record->line);
        for (int i = 0; i < record->num_fields; i++) {
            printf("Field %d: %s\n", i + 1, record->fields[i]);
        }
        printf("\n");
    }

    free(line);
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    csv_record record;
    csv_reader(fp, &record);

    fclose(fp);
    return 0;
}