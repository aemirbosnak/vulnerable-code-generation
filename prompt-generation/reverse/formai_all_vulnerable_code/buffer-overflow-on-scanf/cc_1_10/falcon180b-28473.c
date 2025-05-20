//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    FILE *file;
    char filename[50];
    char line[100];
    int count = 0;
    int lettercount = 0;
    int spacecount = 0;
    int i, j;

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    // Read file and count lines, letters, and spaces
    while (fgets(line, 100, file)!= NULL) {
        count++;
        lettercount += strlen(line) - 1; // -1 to exclude newline character
        spacecount += countspaces(line);
    }

    // Calculate letter and space percentages
    float letterpercentage = (float)lettercount / count * 100;
    float spacepercentage = (float)spacecount / count * 100;

    // Print results
    printf("File: %s\n", filename);
    printf("Lines: %d\n", count);
    printf("Letters: %d\n", lettercount);
    printf("Spaces: %d\n", spacecount);
    printf("Letter percentage: %.2f%%\n", letterpercentage);
    printf("Space percentage: %.2f%%\n", spacepercentage);

    // Convert text to ASCII art
    printf("\nASCII art:\n");
    for (i = 0; i < count; i++) {
        printf("Line %d:\n", i+1);
        for (j = 0; j < strlen(line); j++) {
            if (isalpha(line[j])) {
                printf("%c", line[j]);
            } else if (isspace(line[j])) {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Close file
    fclose(file);

    return 0;
}

int countspaces(char *line) {
    int count = 0;
    int i;
    for (i = 0; i < strlen(line); i++) {
        if (isspace(line[i])) {
            count++;
        }
    }
    return count;
}