//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 1024

int main()
{
    char filename[MAX_FIELD_LENGTH];
    char line[MAX_LINE_LENGTH];
    char *fields[MAX_FIELDS];
    int num_fields, i;

    printf("Please enter the name of the CSV file to read: ");
    scanf("%s", filename);

    FILE *csv_file = fopen(filename, "r");

    if (!csv_file) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, csv_file)) {

        // Replace new line character with null character
        int last_char_index = strlen(line) - 1;
        if (line[last_char_index] == '\n') {
            line[last_char_index] = '\0';
        }

        num_fields = 0;

        // Split the line into fields
        char *field = strtok(line, ",");
        while (field != NULL) {
            fields[num_fields++] = field;
            field = strtok(NULL, ",");
        }

        // Process the fields
        for (i = 0; i < num_fields; i++) {
            printf("Field %d: %s\n", i+1, fields[i]);
        }

        printf("\n");
    }

    fclose(csv_file);

    return 0;
}