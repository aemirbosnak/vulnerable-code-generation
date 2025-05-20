//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to split a string by a delimiter
char **split(char *str, char delimiter) {
    int count = 0;
    char **tokens = NULL;
    char *token = strtok(str, delimiter);

    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = token;
        token = strtok(NULL, delimiter);
    }

    tokens[count - 1] = NULL;
    return tokens;
}

// function to read a CSV file and print its contents
void read_csv(FILE *file) {
    char line[1024];
    char **tokens;

    while (fgets(line, sizeof(line), file)!= NULL) {
        tokens = split(line, ',');

        for (int i = 0; tokens[i]!= NULL; i++) {
            printf("%s ", tokens[i]);
        }

        printf("\n");

        for (int i = 0; tokens[i]!= NULL; i++) {
            free(tokens[i]);
        }
        free(tokens);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file '%s'\n", argv[1]);
        return 1;
    }

    read_csv(file);

    fclose(file);

    return 0;
}