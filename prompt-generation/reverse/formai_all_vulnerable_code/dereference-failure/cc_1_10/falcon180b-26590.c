//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

// Function to compare two strings (case insensitive)
int compare_strings(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1!= len2) {
        return 0;
    }

    for (int i = 0; i < len1; i++) {
        if (tolower(str1[i])!= tolower(str2[i])) {
            return 0;
        }
    }

    return 1;
}

// Function to search for a string in a file
int search_file(FILE* file, const char* search_string) {
    char line[MAX_LINE_LENGTH];
    int found = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (compare_strings(line, search_string)) {
            found = 1;
        }
    }

    return found;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <filename> <search_string>\n", argv[0]);
        exit(1);
    }

    FILE* file = fopen(argv[1], "r");

    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'.\n", argv[1]);
        exit(1);
    }

    int found = search_file(file, argv[2]);

    if (found) {
        printf("String found in file.\n");
    } else {
        printf("String not found in file.\n");
    }

    fclose(file);
    exit(0);
}