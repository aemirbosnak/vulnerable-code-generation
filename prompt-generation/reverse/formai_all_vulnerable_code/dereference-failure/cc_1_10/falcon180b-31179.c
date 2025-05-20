//Falcon-180B DATASET v1.0 Category: Error handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main() {
    char line[MAX_LINE_LENGTH];
    int count = 0;
    FILE *file;
    char filename[MAX_LINE_LENGTH];

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        exit(1);
    }

    // Read file line by line
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        count++;

        // Remove newline character from end of line
        line[strcspn(line, "\n")] = '\0';

        // Reverse the line
        char *start = line;
        char *end = line + strlen(line) - 1;
        while (start < end) {
            char temp = *start;
            *start = *end;
            *end = temp;
            start++;
            end--;
        }

        // Print reversed line
        printf("%d. %s\n", count, line);
    }

    // Close file
    fclose(file);

    return 0;
}