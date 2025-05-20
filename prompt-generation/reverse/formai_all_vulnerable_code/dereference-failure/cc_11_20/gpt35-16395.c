//FormAI DATASET v1.0 Category: Data mining ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1000
#define MAX_FIELD_LEN 200
#define MAX_FIELDS 50

int main(int argc, char *argv[]) {
    // check for correct usage
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];

    // open the input file for reading
    FILE *input_fp = fopen(input_file, "r");
    if (input_fp == NULL) {
        printf("Could not open input file %s\n", input_file);
        return 2;
    }

    // open the output file for writing
    FILE *output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        printf("Could not open output file %s\n", output_file);
        return 3;
    }

    int num_fields = 0;
    char fields[MAX_FIELDS][MAX_FIELD_LEN];
    int field_counts[MAX_FIELDS];

    // read the header line and extract field names
    char line[MAX_LINE_LEN];
    if (fgets(line, MAX_LINE_LEN, input_fp) != NULL) {
        // remove newline character at end of line
        line[strcspn(line, "\n")] = 0;

        // tokenize the line on commas to get fields
        char *token = strtok(line, ",");
        while (token != NULL && num_fields < MAX_FIELDS) {
            strcpy(fields[num_fields], token);
            field_counts[num_fields] = 0;
            num_fields++;
            token = strtok(NULL, ",");
        }
    }

    // read data lines and count field values
    while (fgets(line, MAX_LINE_LEN, input_fp) != NULL) {
        // remove newline character at end of line
        line[strcspn(line, "\n")] = 0;

        // tokenize the line on commas to get field values
        char *token = strtok(line, ",");
        int i = 0;
        while (token != NULL && i < num_fields) {
            field_counts[i]++;
            i++;
            token = strtok(NULL, ",");
        }
    }

    // print field names and counts to output file
    fprintf(output_fp, "Field Name,Count\n");
    for (int i = 0; i < num_fields; i++) {
        fprintf(output_fp, "%s,%d\n", fields[i], field_counts[i]);
    }

    // close the input and output files
    fclose(input_fp);
    fclose(output_fp);

    printf("Data mining complete!\n");

    return 0;
}