//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char filename[MAX_LENGTH];
    printf("Enter CSV filename: ");
    scanf("%s", filename);

    FILE *csv_file = fopen(filename, "r");

    if (!csv_file) {
        printf("Error opening file.\n");
        return 1;
    }

    char header[MAX_LENGTH];
    fgets(header, MAX_LENGTH, csv_file);

    char temp[MAX_LENGTH];
    int num_cols = 1;

    for (int i = 0; i < strlen(header); i++) {
        if (header[i] == ',') {
            num_cols++;
        } else {
            temp[strlen(temp)] = header[i];
        }
    }

    char *columns[num_cols];
    columns[0] = strtok(temp, ",");
    int index = 1;

    while (index < num_cols) {
        columns[index] = strtok(NULL, ",");
        index++;
    }

    printf("CSV headers:\n");
    for (int i = 0; i < num_cols; i++) {
        printf("%s\n", columns[i]);
    }

    char row[MAX_LENGTH];
    int line_num = 1;

    while (fgets(row, MAX_LENGTH, csv_file)) {
        char *cell = strtok(row, ",");
        int cell_num = 0;

        printf("Row %d:\n", line_num);

        while (cell != NULL) {
            printf("%s: %s\n", columns[cell_num], cell);
            cell = strtok(NULL, ",");
            cell_num++;
        }

        line_num++;
    }

    fclose(csv_file);

    return 0;
}