//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELD_SIZE 100  // maximum size of a field in the CSV file
#define MAX_NUM_FIELDS 10   // maximum number of fields in a row of the CSV file

int main() {
    char filename[100];
    printf("Enter the filename of the CSV file: ");
    scanf("%s", filename);

    // open the CSV file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s.", filename);
        return 1;
    }

    // read the first line of the CSV file to determine the number of fields
    char line[MAX_FIELD_SIZE * MAX_NUM_FIELDS];
    fgets(line, sizeof(line), fp);
    int num_fields = 0;
    char* token = strtok(line, ",");
    while (token != NULL && num_fields < MAX_NUM_FIELDS) {
        num_fields++;
        token = strtok(NULL, ",");
    }

    // rewind the CSV file to the beginning
    rewind(fp);

    // read the CSV file row by row
    char field[MAX_FIELD_SIZE];
    char row[MAX_NUM_FIELDS][MAX_FIELD_SIZE];
    while (fgets(line, sizeof(line), fp)) {
        int i = 0;
        token = strtok(line, ",");
        while (token != NULL && i < num_fields) {
            strncpy(row[i++], token, MAX_FIELD_SIZE);
            token = strtok(NULL, ",");
        }

        // do something with the row data
        for (int j = 0; j < num_fields; j++) {
            printf("%s", row[j]);
            if (j < num_fields - 1) {
                printf(",");
            }
        }
        printf("\n");
    }

    // close the CSV file
    fclose(fp);

    return 0;
}