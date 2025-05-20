//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LINE_LENGTH 1000
#define MAX_PATTERN_LENGTH 50

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Invalid number of arguments.\n");
        return 1;
    }

    char *filename = argv[1];
    char *pattern = argv[2];

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char pattern_lower[MAX_PATTERN_LENGTH];
    strcpy(pattern_lower, pattern);
    for (int i = 0; i < strlen(pattern_lower); i++) {
        pattern_lower[i] = tolower(pattern_lower[i]);
    }

    int found_count = 0;
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int line_length = strlen(line);
        if (line_length == 0) {
            continue;
        }

        int pattern_length = strlen(pattern_lower);
        int found_index = -1;
        for (int i = 0; i <= line_length - pattern_length; i++) {
            int j = 0;
            while (j < pattern_length && line[i + j] == pattern_lower[j]) {
                j++;
            }
            if (j == pattern_length) {
                found_index = i;
                found_count++;
                break;
            }
        }

        if (found_index!= -1) {
            printf("Line %d: %s\n", found_count, line);
        }
    }

    fclose(file);
    return 0;
}