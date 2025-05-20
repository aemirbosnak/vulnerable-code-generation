//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1000

// Function to split a line into fields based on a delimiter
char **split_line(char *line, char delimiter) {
    int num_fields = 0;
    char *token = strtok(line, delimiter);
    while (token!= NULL) {
        num_fields++;
        token = strtok(NULL, delimiter);
    }

    char **fields = malloc(sizeof(char *) * (num_fields + 1));
    fields[num_fields] = NULL;

    num_fields = 0;
    token = strtok(line, delimiter);
    while (token!= NULL) {
        fields[num_fields++] = strdup(token);
        token = strtok(NULL, delimiter);
    }

    return fields;
}

// Function to read a CSV file and print its contents
void read_csv_file(FILE *file) {
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, file)!= NULL) {
        char delimiter = line[0];
        char **fields = split_line(line, delimiter);

        for (int i = 0; fields[i]!= NULL; i++) {
            printf("%s ", fields[i]);
        }
        printf("\n");

        for (int i = 0; fields[i]!= NULL; i++) {
            free(fields[i]);
        }
        free(fields);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file '%s'\n", argv[1]);
        return 1;
    }

    read_csv_file(file);

    fclose(file);
    return 0;
}