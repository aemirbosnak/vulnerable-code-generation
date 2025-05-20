//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELD_LENGTH 50
#define MAX_NUM_FIELDS 10
#define MAX_NUM_RECORDS 100

typedef struct {
    char field_name[MAX_FIELD_LENGTH];
    char field_value[MAX_FIELD_LENGTH];
} field;

typedef struct {
    int num_fields;
    field fields[MAX_NUM_FIELDS];
} record;

int main() {
    char input_filename[MAX_FIELD_LENGTH];
    char output_filename[MAX_FIELD_LENGTH];
    char field_names[MAX_NUM_FIELDS][MAX_FIELD_LENGTH];
    int num_fields, num_records, i, j;

    printf("Enter input file name: ");
    scanf("%s", input_filename);

    printf("Enter output file name: ");
    scanf("%s", output_filename);

    printf("Enter the number of fields in the input file: ");
    scanf("%d", &num_fields);

    // Populate field names array
    printf("Enter field names:\n");
    for (i = 0; i < num_fields; i++) {
        scanf("%s", field_names[i]);
    }

    // Read input file and parse records
    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    record records[MAX_NUM_RECORDS];

    for (i = 0; i < MAX_NUM_RECORDS; i++) {
        records[i].num_fields = num_fields;

        for (j = 0; j < num_fields; j++) {
            if (fscanf(input_file, "%s", records[i].fields[j].field_value) != 1) {
                break;
            }

            strcpy(records[i].fields[j].field_name, field_names[j]);
        }

        if (j < num_fields) {
            records[i].num_fields = j;
            break; // End of input file
        }
    }

    num_records = i; // Number of records read

    fclose(input_file);

    // Write output file
    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    // Write field names
    for (i = 0; i < num_fields; i++) {
        fprintf(output_file, "%s", field_names[i]);

        if (i < num_fields - 1) {
            fprintf(output_file, ",");
        } else {
            fprintf(output_file, "\n");
        }
    }

    // Write records
    for (i = 0; i < num_records; i++) {
        for (j = 0; j < records[i].num_fields; j++) {
            fprintf(output_file, "%s", records[i].fields[j].field_value);

            if (j < records[i].num_fields - 1) {
                fprintf(output_file, ",");
            } else {
                fprintf(output_file, "\n");
            }
        }
    }

    fclose(output_file);

    return 0;
}