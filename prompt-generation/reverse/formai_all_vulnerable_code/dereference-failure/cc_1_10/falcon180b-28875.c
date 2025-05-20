//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 1024
#define MAX_FIELDS 1000

typedef struct {
    char *data;
    int len;
} String;

typedef struct {
    String *fields;
    int num_fields;
} Row;

typedef struct {
    Row *rows;
    int num_rows;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(1);
    }

    CSV *csv = malloc(sizeof(CSV));
    csv->rows = NULL;
    csv->num_rows = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        int i = 0;
        String *fields = NULL;
        while (i < MAX_FIELDS && line[i]!= '\0' && line[i]!= ',') {
            fields = realloc(fields, sizeof(String) * ++i);
            fields[i-1].data = malloc(MAX_FIELD_LENGTH);
            fields[i-1].len = 0;
            while (isalnum(line[i]) || line[i] == '_') {
                fields[i-1].data = realloc(fields[i-1].data, sizeof(char) * ++fields[i-1].len);
                fields[i-1].data[fields[i-1].len-1] = tolower(line[i]);
                i++;
            }
            fields[i-1].data[fields[i-1].len] = '\0';
        }
        csv->rows = realloc(csv->rows, sizeof(Row) * ++csv->num_rows);
        csv->rows[csv->num_rows-1].fields = fields;
        csv->rows[csv->num_rows-1].num_fields = i;
    }

    fclose(fp);
    return csv;
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->rows[i].num_fields; j++) {
            free(csv->rows[i].fields[j].data);
        }
        free(csv->rows[i].fields);
    }
    free(csv->rows);
    free(csv);
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->rows[i].num_fields; j++) {
            printf("%s\t", csv->rows[i].fields[j].data);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    CSV *csv = csv_open(argv[1]);
    csv_print(csv);
    csv_close(csv);

    return 0;
}