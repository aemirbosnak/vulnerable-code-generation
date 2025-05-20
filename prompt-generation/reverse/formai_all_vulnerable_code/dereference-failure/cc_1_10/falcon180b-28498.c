//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_FIELDS 1000
#define MAX_FIELD_LENGTH 1000

typedef struct {
    char *field[MAX_NUM_FIELDS];
    int num_fields;
} record_t;

record_t read_csv_record(FILE *csv_file) {
    record_t record = {0};
    char line[MAX_LINE_LENGTH];
    char *token;
    int num_fields = 0;

    fgets(line, MAX_LINE_LENGTH, csv_file);
    token = strtok(line, ",");

    while (token!= NULL) {
        if (num_fields >= MAX_NUM_FIELDS) {
            printf("Error: Too many fields in record.\n");
            exit(1);
        }

        record.field[num_fields++] = strdup(token);
        token = strtok(NULL, ",");
    }

    if (num_fields == 0) {
        printf("Error: Empty record.\n");
        exit(1);
    }

    record.num_fields = num_fields;
    return record;
}

void print_csv_record(record_t record) {
    int i;

    for (i = 0; i < record.num_fields; i++) {
        printf("%s ", record.field[i]);
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    FILE *csv_file;
    record_t record;

    if (argc!= 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        exit(1);
    }

    csv_file = fopen(argv[1], "r");

    if (csv_file == NULL) {
        printf("Error: Could not open CSV file.\n");
        exit(1);
    }

    while ((record = read_csv_record(csv_file)).num_fields > 0) {
        print_csv_record(record);
        memset(record.field, 0, sizeof(record.field));
        record.num_fields = 0;
    }

    fclose(csv_file);
    return 0;
}