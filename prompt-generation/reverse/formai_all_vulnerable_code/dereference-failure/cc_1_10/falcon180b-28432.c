//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELDS 1000

// Function to split a line into fields based on the comma separator
void split_line(char *line, char **fields) {
    char *token = strtok(line, ",");
    int count = 0;

    while (token!= NULL) {
        fields[count] = token;
        count++;
        token = strtok(NULL, ",");
    }
}

// Function to read a CSV file and print its contents
void read_csv_file(FILE *fp) {
    char line[MAX_LINE_LEN];
    char **fields = NULL;
    int num_fields = 0;

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        // Split the line into fields
        split_line(line, &fields);

        // Print the fields
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", fields[i]);
        }
        printf("\n");

        // Free the memory allocated for the fields
        for (int i = 0; i < num_fields; i++) {
            free(fields[i]);
        }
        free(fields);
        num_fields = 0;
    }
}

int main() {
    FILE *fp = fopen("example.csv", "r");

    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    read_csv_file(fp);

    fclose(fp);

    return 0;
}