//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

// Function to remove leading and trailing whitespace from a string
void trim(char* str) {
    char* start = str;
    char* end = str + strlen(str) - 1;

    while (isspace(*start)) {
        start++;
    }

    while (isspace(*end)) {
        end--;
        *end = '\0';
    }

    if (start > str) {
        memmove(str, start, end - start + 1);
    }
}

// Function to split a string into tokens based on a delimiter
int split(char* str, char delim, char*** tokens) {
    char* token = strtok(str, delim);
    int count = 0;

    while (token!= NULL) {
        count++;
        char** new_tokens = realloc(*tokens, sizeof(char*) * (count + 1));

        if (new_tokens == NULL) {
            fprintf(stderr, "Error: Memory allocation failed\n");
            exit(1);
        }

        *tokens = new_tokens;
        (*tokens)[count - 1] = token;

        token = strtok(NULL, delim);
    }

    (*tokens)[count] = NULL;

    return count;
}

// Function to read a CSV file and print its contents
void read_csv(FILE* file) {
    char line[MAX_LINE_LENGTH];
    char delim;

    // Read the first line to determine the delimiter
    fgets(line, MAX_LINE_LENGTH, file);
    trim(line);

    if (line[0] == ',') {
        delim = ';';
    } else if (line[0] == ';') {
        delim = ',';
    } else {
        fprintf(stderr, "Error: Invalid delimiter\n");
        exit(1);
    }

    // Read the rest of the file and print each row
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        trim(line);

        if (line[0] == '\0') {
            continue;
        }

        char** tokens = NULL;
        int count = split(line, delim, &tokens);

        for (int i = 0; i < count; i++) {
            printf("%s ", tokens[i]);
        }

        printf("\n");

        for (int i = 0; i < count; i++) {
            free(tokens[i]);
        }
        free(tokens);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        exit(1);
    }

    FILE* file = fopen(argv[1], "r");

    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file\n");
        exit(1);
    }

    read_csv(file);

    fclose(file);

    return 0;
}