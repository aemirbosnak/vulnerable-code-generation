//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELD_SIZE 256

typedef struct {
    int num_fields;
    char *field_names[MAX_FIELD_SIZE];
    char *fields[MAX_FIELD_SIZE];
} CSVReader;

CSVReader *csv_reader_create() {
    CSVReader *reader = (CSVReader *)malloc(sizeof(CSVReader));
    reader->num_fields = 0;
    for (int i = 0; i < MAX_FIELD_SIZE; i++) {
        reader->field_names[i] = NULL;
        reader->fields[i] = NULL;
    }
    return reader;
}

void csv_reader_destroy(CSVReader *reader) {
    for (int i = 0; i < reader->num_fields; i++) {
        free(reader->field_names[i]);
        free(reader->fields[i]);
    }
    free(reader);
}

int csv_reader_load(CSVReader *reader, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }

    char line[MAX_LINE_SIZE];
    char *header = NULL;
    char *token = NULL;
    int num_fields = 0;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        if (header == NULL) {
            header = strdup(line);
            num_fields = 0;
            token = strtok(header, ",");
            while (token!= NULL) {
                reader->field_names[num_fields] = strdup(token);
                num_fields++;
                token = strtok(NULL, ",");
            }
            reader->num_fields = num_fields;
        } else {
            token = strtok(line, ",");
            int j = 0;
            while (token!= NULL) {
                reader->fields[j] = strdup(token);
                j++;
                token = strtok(NULL, ",");
            }
        }
    }

    fclose(file);
    free(header);
    return 0;
}

void csv_reader_print(CSVReader *reader) {
    for (int i = 0; i < reader->num_fields; i++) {
        printf("%s: %s\n", reader->field_names[i], reader->fields[i]);
    }
}

int main() {
    CSVReader *reader = csv_reader_create();
    csv_reader_load(reader, "data.csv");
    csv_reader_print(reader);
    csv_reader_destroy(reader);
    return 0;
}