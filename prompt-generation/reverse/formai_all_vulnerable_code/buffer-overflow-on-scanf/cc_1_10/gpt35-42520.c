//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_FIELD_LENGTH 32
#define MAX_NUM_FIELDS 10

void display_row(char** fields, int num_fields) {
    printf("Row: ");
    for (int i = 0; i < num_fields; i++) {
        printf("%s ", fields[i]);
    }
    printf("\n");
}

int main() {
    printf("Welcome to the CSV Reader program!\n");
    printf("Please enter the filename of the CSV file you would like to read: ");

    char filename[MAX_FIELD_LENGTH];
    scanf("%s", filename);

    FILE* csv_file = fopen(filename, "r");

    if (csv_file == NULL) {
        printf("Error: file not found or could not be opened.\n");
        return 1;
    }

    printf("CSV file found!\n");

    char line[MAX_LINE_LENGTH];
    char* fields[MAX_NUM_FIELDS];

    while (fgets(line, MAX_LINE_LENGTH, csv_file) != NULL) {
        int num_fields = 0;
        char* field = strtok(line, ",");
        while (field != NULL && num_fields < MAX_NUM_FIELDS) {
            fields[num_fields] = malloc(sizeof(char) * MAX_FIELD_LENGTH);
            strcpy(fields[num_fields], field);
            num_fields++;
            field = strtok(NULL, ",");
        }
        display_row(fields, num_fields);
        for (int i = 0; i < num_fields; i++) {
            free(fields[i]);
        }
    }

    fclose(csv_file);
    printf("CSV file successfully read!\n");

    return 0;
}