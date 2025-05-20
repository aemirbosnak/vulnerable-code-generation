//FormAI DATASET v1.0 Category: HTML beautifier ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    printf("Welcome to the C HTML Beautifier!\n");

    // Let's get the file name from the user
    printf("Please enter the name of the HTML file to beautify: ");
    char filename[50];
    scanf("%s", filename);

    // Let's open the file to read
    FILE *fp = fopen(filename, "r");

    // If the file can't be opened for some reason, let's exit the program
    if (fp == NULL) {
        printf("Sorry, could not open file %s\n", filename);
        return 1;
    }

    // Variables to store the lines of code
    char buffer[250];
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // Variables to keep track of the indentation level
    int indent_level = 0;
    int indent_size = 4;

    printf("Beautifying file %s...\n\n", filename);

    // Let's read the file line by line
    while ((read = getline(&line, &len, fp)) != -1) {
        // Let's remove whitespace at the beginning and end of the line
        line[strcspn(line, " \t\r\n")] = 0;
        int line_length = strlen(line);

        // Only beautify non-empty lines
        if (line_length > 0) {
            // Let's check if this is a closing tag
            if (line[0] == '<' && line[1] == '/') {
                indent_level--;
            }

            // Let's add the indentation
            int i;
            for (i = 0; i < indent_size * indent_level; i++) {
                putchar(' ');
            }

            // Now let's print the line
            printf("%s\n", line);

            // Let's check if this is an opening tag with no closing tag
            if (line[line_length - 2] == '/' && line[line_length - 1] == '>') {
                // Do nothing, it's already complete
            } else if (line[0] == '<' && line[1] != '/') {
                // This is an opening tag
                indent_level++;
            }
        }
    }

    // Let's close the file and free any memory
    fclose(fp);
    if (line) {
        free(line);
    }

    printf("\nBeautification complete! Have a nice day :)\n");

    return 0;
}