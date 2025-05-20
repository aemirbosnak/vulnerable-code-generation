//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char **data;
    int num_fields;
    int num_lines;
} CSVReader;

void initialize_csv_reader(CSVReader *reader) {
    reader->data = NULL;
    reader->num_fields = 0;
    reader->num_lines = 0;
}

void destroy_csv_reader(CSVReader *reader) {
    int i;
    for (i = 0; i < reader->num_fields; i++) {
        free(reader->data[i]);
    }
    free(reader->data);
}

int read_csv_file(CSVReader *reader, FILE *file) {
    char line[MAX_LINE_LENGTH];
    char *token;
    int num_fields = 0;
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        num_fields = 0;
        reader->data[num_fields] = strtok(line, ",");
        while ((token = strtok(NULL, ","))!= NULL) {
            num_fields++;
            reader->data[num_fields] = token;
        }
        reader->num_fields = num_fields;
        reader->num_lines++;
    }
    return 0;
}

int main() {
    CSVReader reader;
    initialize_csv_reader(&reader);
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    read_csv_file(&reader, file);
    fclose(file);
    int i, j;
    for (i = 0; i < reader.num_lines; i++) {
        for (j = 0; j < reader.num_fields; j++) {
            printf("%s ", reader.data[j]);
        }
        printf("\n");
    }
    destroy_csv_reader(&reader);
    return 0;
}