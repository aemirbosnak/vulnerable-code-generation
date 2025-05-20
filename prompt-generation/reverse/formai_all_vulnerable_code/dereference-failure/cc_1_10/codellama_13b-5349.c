//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: automated
/*
 * csv_reader.c
 *
 *  Created on: Feb 10, 2023
 *      Author: Evan
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *field;
    int field_size;
    char *data;
    int data_size;
} csv_record_t;

int read_csv_record(FILE *file, csv_record_t *record) {
    char buffer[BUFFER_SIZE];
    char *field, *data;
    int field_size, data_size;

    field = fgets(buffer, BUFFER_SIZE, file);
    if (field == NULL) {
        return 0;
    }

    field_size = strlen(field);

    data = fgets(buffer, BUFFER_SIZE, file);
    if (data == NULL) {
        return 0;
    }

    data_size = strlen(data);

    record->field = malloc(field_size + 1);
    record->field_size = field_size;
    memcpy(record->field, field, field_size + 1);

    record->data = malloc(data_size + 1);
    record->data_size = data_size;
    memcpy(record->data, data, data_size + 1);

    return 1;
}

int main(int argc, char *argv[]) {
    FILE *file;
    csv_record_t record;
    int i;

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    while (read_csv_record(file, &record)) {
        printf("Field: %s\n", record.field);
        printf("Data: %s\n", record.data);
    }

    fclose(file);
    return 0;
}