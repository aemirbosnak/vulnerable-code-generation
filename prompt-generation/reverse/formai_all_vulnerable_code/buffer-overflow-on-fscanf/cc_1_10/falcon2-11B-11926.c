//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

struct csv_record {
    char *field1;
    char *field2;
    char *field3;
};

int parse_csv_record(char *line, struct csv_record *record) {
    char *token;
    char *field1;
    char *field2;
    char *field3;

    if ((token = strtok_r(line, ",", &line)) == NULL) {
        return -1;
    }

    field1 = strdup(token);
    if (field1 == NULL) {
        return -1;
    }

    if ((token = strtok_r(NULL, ",", &line)) == NULL) {
        return -1;
    }

    field2 = strdup(token);
    if (field2 == NULL) {
        return -1;
    }

    if ((token = strtok_r(NULL, ",", &line)) == NULL) {
        return -1;
    }

    field3 = strdup(token);
    if (field3 == NULL) {
        return -1;
    }

    record->field1 = field1;
    record->field2 = field2;
    record->field3 = field3;

    return 0;
}

int main() {
    char *filename = "example.csv";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        exit(1);
    }

    struct csv_record record;
    while (fscanf(file, "%s,%s,%s\n", record.field1, record.field2, record.field3)!= EOF) {
        printf("%s,%s,%s\n", record.field1, record.field2, record.field3);
    }

    fclose(file);
    return 0;
}