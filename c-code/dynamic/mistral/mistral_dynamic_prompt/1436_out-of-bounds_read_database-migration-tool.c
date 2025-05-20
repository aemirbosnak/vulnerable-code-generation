#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

void process_record(char *record, size_t record_length) {
    char *data_type = (char *)malloc(record_length);
    strncpy(data_type, record, record_length);
    data_type[record_length] = '\0'; // Assumption: record_length includes null terminator

    char *table_name = (char *)malloc(strlen(data_type) + BUFFER_SIZE);
    strcpy(table_name, "database:");
    strncat(table_name, data_type, BUFFER_SIZE - strlen(table_name));

    // OOB read vulnerability here: assuming table_name array is not large enough
    printf("Processing table: %s\n", table_name + strlen(table_name) + BUFFER_SIZE);

    free(data_type);
}

int main() {
    char input[1024];
    printf("Enter a record (255 chars max): ");
    fgets(input, sizeof(input), stdin);

    size_t input_length = strlen(input);
    process_record(input, input_length);

    return 0;
}
