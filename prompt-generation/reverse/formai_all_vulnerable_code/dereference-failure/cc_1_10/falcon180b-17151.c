//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELD_SIZE 256

// Function to trim leading and trailing whitespace
void trim(char* str) {
    int len = strlen(str);
    while (isspace(str[len - 1])) {
        str[--len] = 0;
    }
    while (isspace(*str)) {
        str++;
        len--;
    }
    memmove(str, str + len, strlen(str) + 1);
}

// Function to split a string into fields using a delimiter
int split(char* str, char delim, char** fields, int max_fields) {
    int count = 0;
    char* token = strtok(str, delim);
    while (token!= NULL && count < max_fields) {
        trim(token);
        fields[count++] = token;
        token = strtok(NULL, delim);
    }
    return count;
}

// Function to read a line from a file
char* read_line(FILE* file) {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    getline(&line, &len, file);
    if (line == NULL) {
        fprintf(stderr, "Error reading line.\n");
        exit(1);
    }
    return line;
}

// Function to read a CSV file and print its contents
void read_csv(FILE* file) {
    char* line = NULL;
    char* fields[MAX_FIELD_SIZE];
    int num_fields;
    while ((line = read_line(file))!= NULL) {
        num_fields = split(line, ',', fields, MAX_FIELD_SIZE);
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", fields[i]);
        }
        printf("\n");
    }
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }
    read_csv(file);
    fclose(file);
    return 0;
}