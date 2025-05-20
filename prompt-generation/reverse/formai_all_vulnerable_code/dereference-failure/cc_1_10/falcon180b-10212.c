//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

/* Function to read a line from a file */
char *read_line(FILE *file) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    line = malloc(MAX_LINE_SIZE);
    if (line == NULL) {
        fprintf(stderr, "Error allocating memory.\n");
        exit(1);
    }

    while ((read = getline(&line, &len, file))!= -1) {
        if (read == 0) {
            fprintf(stderr, "Line too long.\n");
            exit(1);
        }
    }

    return line;
}

/* Function to split a line into fields */
char **split_line(char *line) {
    char **fields = NULL;
    int num_fields = 0;
    char *token;

    token = strtok(line, ",");
    while (token!= NULL) {
        num_fields++;
        fields = realloc(fields, sizeof(char *) * num_fields);
        fields[num_fields - 1] = token;
        token = strtok(NULL, ",");
    }

    return fields;
}

/* Function to print a line of fields */
void print_line(char **fields) {
    int i;

    for (i = 0; fields[i]!= NULL; i++) {
        printf("%s ", fields[i]);
    }
    printf("\n");
}

/* Function to read and print a CSV file */
void read_csv_file(char *filename) {
    FILE *file;
    char *line;
    char **fields;

    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        exit(1);
    }

    while ((line = read_line(file))!= NULL) {
        fields = split_line(line);
        print_line(fields);
        free(line);
        free(fields);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    read_csv_file(argv[1]);

    return 0;
}