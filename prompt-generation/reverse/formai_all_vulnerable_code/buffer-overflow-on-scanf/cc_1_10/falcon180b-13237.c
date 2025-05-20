//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WIDTH 80
#define MAX_HEIGHT 25

// Function to print an ASCII art representation of the given string
void print_ascii_art(char* str, int width, int height) {
    int len = strlen(str);
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < len; j++) {
            if (isalpha(str[j])) {
                printf("%c", tolower(str[j]));
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *filename;

    // Get filename from user input
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read file contents
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        // Remove trailing newline character
        line[strcspn(line, "\n")] = '\0';

        // Print ASCII art representation of line
        print_ascii_art(line, MAX_WIDTH, MAX_HEIGHT);
    }

    // Close file
    fclose(fp);

    return 0;
}