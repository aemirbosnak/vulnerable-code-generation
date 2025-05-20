//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELD_LENGTH 256 // max field length in the CSV file
#define MAX_FIELDS 100 // max number of fields in each line
#define MAX_LINE_LENGTH (MAX_FIELD_LENGTH * MAX_FIELDS + MAX_FIELDS - 1) // max length of a line in the CSV file

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error: cannot open file '%s'\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int line_num = 0;
    while (fgets(line, sizeof(line), fp)) {
        line_num++;

        // remove newline character at the end
        size_t len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }

        char *fields[MAX_FIELDS];
        int field_count = 0;

        // split the line into fields
        char *p = strtok(line, ",");
        while (p) {
            if (field_count >= MAX_FIELDS) {
                printf("Error: too many fields in line %d\n", line_num);
                return 1;
            }

            fields[field_count++] = p;
            p = strtok(NULL, ",");
        }

        // process the fields
        for (int i = 0; i < field_count; i++) {
            printf("Field %d in line %d: %s\n", i + 1, line_num, fields[i]);
        }
    }

    fclose(fp);

    return 0;
}