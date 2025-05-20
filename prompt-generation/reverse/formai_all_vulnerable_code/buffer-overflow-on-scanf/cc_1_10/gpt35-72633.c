//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 256
#define MAX_CSV_LINE_SIZE 1024
#define MAX_CSV_FIELD_SIZE 128
#define MAX_CSV_FIELDS 32

typedef struct csv_field {
    char value[MAX_CSV_FIELD_SIZE];
} csv_field_t;

typedef struct csv_line {
    csv_field_t fields[MAX_CSV_FIELDS];
    int field_count;
} csv_line_t;

typedef struct csv_file {
    FILE *fp;
    csv_line_t current_line;
} csv_file_t;

char file_name[MAX_FILE_NAME_SIZE];
csv_file_t csv_file;

int open_csv_file(void)
{
    printf("Enter CSV file name: ");
    scanf("%s", file_name);
    csv_file.fp = fopen(file_name, "r");
    if (csv_file.fp == NULL) {
        printf("Error opening file %s!\n", file_name);
        return -1;
    }
    printf("CSV file %s opened successfully!\n", file_name);
    return 0;
}

int read_csv_line(csv_line_t *line)
{
    char csv_line[MAX_CSV_LINE_SIZE];
    char *field_value;
    int i;
    if (fgets(csv_line, MAX_CSV_LINE_SIZE, csv_file.fp) != NULL) {
        field_value = strtok(csv_line, ",");
        i = 0;
        while (field_value != NULL) {
            strncpy(line->fields[i].value, field_value, MAX_CSV_FIELD_SIZE);
            i++;
            field_value = strtok(NULL, ",");
        }
        line->field_count = i;
        return 0;
    }
    return -1;
}

int close_csv_file(void)
{
    fclose(csv_file.fp);
    printf("CSV file %s closed successfully!\n", file_name);
    return 0;
}

int main()
{
    int rc;
    rc = open_csv_file();
    if (rc == -1) {
        return -1;
    }
    while (read_csv_line(&csv_file.current_line) == 0) {
        printf("CSV line with %d fields read:\n", csv_file.current_line.field_count);
        int i;
        for (i = 0; i < csv_file.current_line.field_count; i++) {
            printf("    Field #%d: %s\n", i + 1, csv_file.current_line.fields[i].value);
        }
    }
    rc = close_csv_file();
    if (rc == -1) {
        return -1;
    }
    return 0;
}