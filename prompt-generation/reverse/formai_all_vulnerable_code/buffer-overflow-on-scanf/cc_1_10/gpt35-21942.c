//FormAI DATASET v1.0 Category: HTML beautifier ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove spaces at the beginning and end of a string
char* trim(char *str) {
    int i, j, len = strlen(str);

    // Remove spaces at the beginning of the string
    for (i = 0; str[i] == ' ' && i < len; i++);

    // Remove spaces at the end of the string
    for (j = len-1; str[j] == ' ' && j >= 0; j--);
    
    str[j+1] = '\0';   // Terminate the string after the last non-space character
    return &str[i];    // Return a pointer to the first non-space character
}

// Function to beautify an HTML file
void beautify_html(char *filename) {
    FILE *fpin, *fpout;
    char c, *line, *trimmed;
    int indent = 0, i, len, in_tag = 0, in_comment = 0;

    fpin = fopen(filename, "r");
    if (fpin == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    fpout = fopen("output.html", "w");
    if (fpout == NULL) {
        printf("Error: Unable to create output file\n");
        fclose(fpin);
        return;
    }

    line = malloc(1024);
    while (fgets(line, 1024, fpin)) {
        len = strlen(line);

        // Remove newline character at the end of the line
        if (len > 0 && line[len-1] == '\n')
            line[len-1] = '\0';

        // Trim leading and trailing spaces
        trimmed = trim(line);

        // Check if the line is a comment
        if (strncmp(trimmed, "<!--", 4) == 0)
            in_comment = 1;

        // Adjust indentation level
        if (in_tag && !in_comment && c == '>')
            indent++;

        if (indent < 0)
            indent = 0;

        // Print the line with proper indentation
        for (i = 0; i < indent; i++)
            fprintf(fpout, "\t");
        
        fprintf(fpout, "%s\n", trimmed);

        // Check if the line is the end of a comment
        if (strncmp(trimmed, "-->", 3) == 0)
            in_comment = 0;

        // Check if the line is a tag
        in_tag = (trimmed[0] == '<' && trimmed[len-1] == '>');

        // Adjust indentation level
        if (in_tag && !in_comment && trimmed[1] == '/')
            indent--;

    }

    fclose(fpin);
    fclose(fpout);
    free(line);
    printf("File %s beautified successfully.\n", filename);
}

// Main function
int main() {
    char filename[256];
    printf("Enter the name of the HTML file to beautify: ");
    scanf("%s", filename);
    beautify_html(filename);
    return 0;
}