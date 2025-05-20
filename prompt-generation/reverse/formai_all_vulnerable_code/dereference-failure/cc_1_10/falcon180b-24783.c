//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_CSV_FIELDS 1000

typedef struct {
    char *data;
    size_t length;
} CSVField;

CSVField *read_csv(FILE *file) {
    CSVField *fields = NULL;
    size_t num_fields = 0;
    char line[MAX_LINE_LENGTH];
    int in_quotes = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        size_t line_length = strlen(line);
        if (line_length == 0 || line[line_length - 1] == '\r') {
            continue;
        }

        CSVField *new_fields = realloc(fields, sizeof(CSVField) * (num_fields + 1));
        if (new_fields == NULL) {
            free(fields);
            return NULL;
        }
        fields = new_fields;

        fields[num_fields].data = line;
        fields[num_fields].length = line_length;
        num_fields++;
    }

    return fields;
}

void free_csv_fields(CSVField *fields, size_t num_fields) {
    for (size_t i = 0; i < num_fields; i++) {
        free(fields[i].data);
    }
    free(fields);
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    CSVField *fields = read_csv(file);
    if (fields == NULL) {
        printf("Error reading CSV data.\n");
        return 1;
    }

    for (size_t i = 0; i < fields->length; i++) {
        printf("%s\n", fields[i].data);
    }

    free_csv_fields(fields, fields->length);
    fclose(file);

    return 0;
}