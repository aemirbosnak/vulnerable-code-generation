//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 1000

typedef struct {
    char delimiter;
    int num_fields;
    char **fields;
} CSVReader;

CSVReader *create_csv_reader(char delimiter) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->delimiter = delimiter;
    reader->num_fields = 0;
    reader->fields = NULL;
    return reader;
}

void destroy_csv_reader(CSVReader *reader) {
    for (int i = 0; i < reader->num_fields; i++) {
        free(reader->fields[i]);
    }
    free(reader->fields);
    free(reader);
}

void add_field(CSVReader *reader, char *field) {
    reader->fields = realloc(reader->fields, sizeof(char *) * (reader->num_fields + 1));
    reader->fields[reader->num_fields] = field;
    reader->num_fields++;
}

int read_csv_line(CSVReader *reader, FILE *file) {
    char line[MAX_LINE_LENGTH];
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        return 0;
    }
    char *token = strtok(line, reader->delimiter);
    while (token!= NULL) {
        add_field(reader, token);
        token = strtok(NULL, reader->delimiter);
    }
    return 1;
}

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    CSVReader *reader = create_csv_reader(',');

    int row_num = 0;
    while (read_csv_line(reader, file)) {
        printf("Row %d:\n", row_num);
        for (int i = 0; i < reader->num_fields; i++) {
            printf("%s\n", reader->fields[i]);
        }
        row_num++;
        destroy_csv_reader(reader);
        reader = create_csv_reader(',');
    }

    fclose(file);
    return 0;
}