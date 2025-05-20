//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 128
#define DELIMITER ","
#define TRUE 1
#define FALSE 0

int main() {

    char filename[MAX_FIELD_LENGTH];
    char line[MAX_LINE_LENGTH];
    char *field;
    int has_header = FALSE;

    printf("Enter CSV filename: ");
    scanf("%s", filename);

    FILE *csv_file = fopen(filename, "r");

    if (csv_file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Check if the file has a header
    printf("Does the file contain a header row? (Y/N): ");
    char ans[MAX_FIELD_LENGTH];
    scanf("%s", ans);

    if (strcmp(ans, "Y") == 0 || strcmp(ans, "y") == 0) {
        has_header = TRUE;
    }

    // Read the first line and parse the fields
    fgets(line, MAX_LINE_LENGTH, csv_file);
    field = strtok(line, DELIMITER);

    while (field != NULL) {
        printf("%s\t", field);
        field = strtok(NULL, DELIMITER);
    }

    printf("\n");

    // Read the remaining lines and parse the fields
    while (fgets(line, MAX_LINE_LENGTH, csv_file) != NULL) {
        field = strtok(line, DELIMITER);

        while (field != NULL) {
            printf("%s\t", field);
            field = strtok(NULL, DELIMITER);
        }

        printf("\n");
    }

    fclose(csv_file);
    return 0;
}