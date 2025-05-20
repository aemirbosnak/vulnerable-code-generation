//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 100

int main() {
    char filename[MAX_LINE_LENGTH];
    printf("Enter CSV filename: ");
    scanf("%s", filename);

    FILE *csv_file = fopen(filename, "r");
    if (csv_file == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    // read the first line to determine the number of fields
    char header[MAX_LINE_LENGTH];
    fgets(header, MAX_LINE_LENGTH, csv_file);
    int num_fields = 0;
    char *field = strtok(header, ",");
    while (field != NULL && num_fields < MAX_NUM_FIELDS) {
        num_fields++;
        field = strtok(NULL, ",");
    }

    // read the rest of the lines (data)
    char line[MAX_LINE_LENGTH];
    char *field_values[MAX_NUM_FIELDS];
    while (fgets(line, MAX_LINE_LENGTH, csv_file) != NULL) {
        // parse line into fields
        int field_index = 0;
        char *field_value = strtok(line, ",");
        while (field_index < num_fields && field_value != NULL) {
            field_values[field_index] = field_value;
            field_index++;
            field_value = strtok(NULL, ",");
        }

        // process the data (print to console in this example)
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", field_values[i]);
        }
        printf("\n");
    }

    fclose(csv_file);
    return 0;
}