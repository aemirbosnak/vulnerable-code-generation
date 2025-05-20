//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

// Function to split a line into fields based on the delimiter
void split_line(char *line, char delimiter, char **fields) {
    int n_fields = 0;
    char *token = strtok(line, delimiter);
    while (token!= NULL) {
        fields[n_fields] = token;
        n_fields++;
        token = strtok(NULL, delimiter);
    }
}

// Function to read a CSV file
void read_csv_file(FILE *fp, char delimiter, void (*callback)(char **)) {
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        char *fields[100];
        split_line(line, delimiter, fields);
        callback(fields);
    }
}

// Example callback function to print the fields
void print_fields(char **fields) {
    for (int i = 0; fields[i]!= NULL; i++) {
        printf("%s ", fields[i]);
    }
    printf("\n");
}

// Main function to run the program
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <delimiter>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file '%s'\n", argv[1]);
        return 1;
    }

    char delimiter = argv[2][0];
    read_csv_file(fp, delimiter, print_fields);

    fclose(fp);
    return 0;
}