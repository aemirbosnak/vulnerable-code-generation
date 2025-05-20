//Falcon-180B DATASET v1.0 Category: Error handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_LINE_NUMBER 100

bool is_valid_line(char *line) {
    int i = 0;
    while (line[i]!= '\0') {
        if (!isdigit(line[i])) {
            return false;
        }
        i++;
    }
    return true;
}

int get_line_number(char *filename, char *line) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    int line_number = 1;
    char *buffer = malloc(MAX_LINE_LENGTH);
    while (fgets(buffer, MAX_LINE_LENGTH, fp)!= NULL) {
        if (strcmp(buffer, line) == 0) {
            fclose(fp);
            return line_number;
        }
        line_number++;
    }
    fclose(fp);
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Error: Invalid number of arguments\n");
        printf("Usage: %s <filename> <line_number>\n", argv[0]);
        return 1;
    }
    char *filename = argv[1];
    char *line = argv[2];
    int line_number = get_line_number(filename, line);
    if (line_number == -1) {
        printf("Error: Line not found\n");
        return 1;
    }
    printf("Line %d: %s\n", line_number, line);
    return 0;
}