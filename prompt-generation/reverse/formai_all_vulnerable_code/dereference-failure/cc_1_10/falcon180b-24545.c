//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_LEN 50

typedef struct {
    char *name;
    int age;
    float salary;
} record_t;

record_t records[MAX_RECORDS];
int num_records = 0;

void read_csv(FILE *file) {
    char line[MAX_FIELD_LEN];
    char delimiter = ',';
    while (fgets(line, MAX_FIELD_LEN, file)!= NULL) {
        char *token = strtok(line, &delimiter);
        if (token == NULL) {
            continue;
        }
        record_t *record = &records[num_records];
        strcpy(record->name, token);
        token = strtok(NULL, &delimiter);
        record->age = atoi(token);
        token = strtok(NULL, &delimiter);
        record->salary = atof(token);
        num_records++;
    }
}

void write_csv(FILE *file) {
    for (int i = 0; i < num_records; i++) {
        record_t *record = &records[i];
        fprintf(file, "%s,%d,%.2f\n", record->name, record->age, record->salary);
    }
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    read_csv(input_file);
    fclose(input_file);

    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }
    write_csv(output_file);
    fclose(output_file);

    return 0;
}