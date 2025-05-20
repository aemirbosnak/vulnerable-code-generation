//Falcon-180B DATASET v1.0 Category: File handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000

typedef struct {
    char *data;
    size_t length;
} Line;

int main() {
    FILE *file;
    char filename[MAX_LINE_LENGTH];
    Line lines[MAX_NUM_LINES];
    size_t num_lines = 0;

    printf("Enter a filename to read:\n");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    while (num_lines < MAX_NUM_LINES && fgets(lines[num_lines].data, MAX_LINE_LENGTH, file)!= NULL) {
        lines[num_lines].length = strlen(lines[num_lines].data);
        ++num_lines;
    }

    fclose(file);

    printf("Enter a search string:\n");
    char search_string[MAX_LINE_LENGTH];
    scanf("%s", search_string);

    size_t num_matches = 0;
    for (size_t i = 0; i < num_lines; ++i) {
        if (strstr(lines[i].data, search_string)!= NULL) {
            printf("Match found in line %zu:\n%s\n", i + 1, lines[i].data);
            ++num_matches;
        }
    }

    printf("Found %zu matches\n", num_matches);

    return 0;
}