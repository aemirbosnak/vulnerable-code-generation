//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

// Function to split a line of text into fields based on a delimiter
int split_line(char *line, char delimiter, char **fields) {
    char *token = strtok(line, delimiter);
    int count = 0;

    while (token!= NULL) {
        fields[count] = token;
        count++;
        token = strtok(NULL, delimiter);
    }

    return count;
}

// Function to read a CSV file and print its contents
void read_csv(FILE *fp) {
    char line[MAX_LINE_LEN];
    char **fields;
    int num_fields;

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        num_fields = split_line(line, ',', fields);

        for (int i = 0; i < num_fields; i++) {
            printf("%s ", fields[i]);
        }

        printf("\n");

        for (int i = 0; i < num_fields; i++) {
            free(fields[i]);
        }
        free(fields);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    read_csv(fp);

    fclose(fp);

    return 0;
}