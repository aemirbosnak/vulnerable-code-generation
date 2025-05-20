//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_LINES 1000

// Function to compare two strings
int compare_strings(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1!= len2) {
        return 1;
    }
    for (int i = 0; i < len1; i++) {
        if (str1[i]!= str2[i]) {
            return 1;
        }
    }
    return 0;
}

// Function to print a line of text with a specific pattern
void print_line(char *line, char *pattern) {
    int len = strlen(pattern);
    int i = 0;
    while (line[i]!= '\0') {
        if (compare_strings(line + i, pattern)) {
            printf("%s", pattern);
            i += len;
        } else {
            printf("%c", line[i]);
            i++;
        }
    }
    printf("\n");
}

// Function to read a file and store its contents in memory
char *read_file(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }
    char *buffer = malloc(MAX_LINE_LENGTH * sizeof(char));
    if (buffer == NULL) {
        printf("Error: Could not allocate memory for buffer\n");
        exit(1);
    }
    char line[MAX_LINE_LENGTH];
    int lines = 0;
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        strcat(buffer, line);
        lines++;
        if (lines >= MAX_LINES) {
            printf("Error: File '%s' is too large\n", filename);
            exit(1);
        }
    }
    fclose(file);
    return buffer;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <pattern>\n", argv[0]);
        return 1;
    }
    char *filename = argv[1];
    char *pattern = argv[2];
    char *buffer = read_file(filename);
    printf("Pattern: %s\n", pattern);
    print_line(buffer, pattern);
    free(buffer);
    return 0;
}