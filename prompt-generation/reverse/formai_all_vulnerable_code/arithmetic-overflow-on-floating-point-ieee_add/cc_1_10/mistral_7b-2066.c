//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 10
#define MAX_LINE_LENGTH 256

typedef struct {
    char fields[MAX_FIELDS][256];
} Record;

void parse_csv_line(char *line, Record *record) {
    char *token, *delimiter = ",";
    int i = 0;

    record->fields[0][0] = '\0';

    token = strtok(line, delimiter);
    while (token != NULL && i < MAX_FIELDS) {
        strcpy(record->fields[i], token);
        token = strtok(NULL, delimiter);
        i++;
    }
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    Record current_record;
    Record total_record = {{"", "", ""}};
    int record_count = 0;
    double total_age = 0, total_spending = 0;

    file = fopen("customers.csv", "r");
    if (file == NULL) {
        printf("Error: Unable to open file\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        parse_csv_line(line, &current_record);

        if (strcmp(current_record.fields[0], "") != 0) { // Skip header line
            total_age += atof(current_record.fields[1]);
            total_spending += atof(current_record.fields[2]);
            record_count++;
        }
    }

    fclose(file);

    if (record_count > 0) {
        total_age /= record_count;
        total_spending /= record_count;

        printf("Average age: %.2f\n", total_age);
        printf("Total spending: %.2f\n", total_spending);
    }

    return 0;
}