//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1000

typedef struct {
    char *text;
    int length;
} Line;

int main() {
    FILE *file;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    Line lines[MAX_LINES];
    int num_lines = 0;

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Read file line by line
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (num_lines >= MAX_LINES) {
            printf("Error: too many lines in file.\n");
            fclose(file);
            return 1;
        }
        lines[num_lines].text = strdup(line);
        lines[num_lines].length = strlen(line);
        num_lines++;
    }

    // Close file
    fclose(file);

    // Display lines in reverse order
    for (int i = num_lines - 1; i >= 0; i--) {
        printf("%d: %s\n", i + 1, lines[i].text);
    }

    // Free memory
    for (int i = 0; i < num_lines; i++) {
        free(lines[i].text);
    }
    free(lines);

    return 0;
}