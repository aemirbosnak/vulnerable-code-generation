//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to check if a string is a valid HTML tag
int is_valid_tag(char* tag) {
    int len = strlen(tag);
    if (len < 3) {
        return 0;
    }
    if (tag[0]!= '<') {
        return 0;
    }
    if (tag[len - 1]!= '>') {
        return 0;
    }
    return 1;
}

// Function to beautify a single line of HTML code
void beautify_line(char* line, int* indent, int* current_tag_depth) {
    int len = strlen(line);
    int i = 0;

    // Check if the line contains a valid HTML tag
    if (is_valid_tag(line)) {
        // Increment the current tag depth
        if (line[0] == '<') {
            (*current_tag_depth)++;
        } else {
            (*current_tag_depth)--;
        }

        // Calculate the indentation level for the line
        int indent_level = (*current_tag_depth) * 4;
        if (indent_level > (*indent)) {
            (*indent) = indent_level;
        }

        // Add the indentation to the line
        char* new_line = malloc(MAX_LINE_LENGTH);
        sprintf(new_line, "%*s%s", indent_level, "", line);
        strcpy(line, new_line);
        free(new_line);
    }

    // Check if the line contains a comment
    if (line[0] == '<' && line[1] == '!') {
        // Add the comment to a new line
        char* new_line = malloc(MAX_LINE_LENGTH);
        sprintf(new_line, "<!-- %s -->\n", line);
        strcat(line, new_line);
        free(new_line);
    }

    // Check if the line contains a closing tag
    if (line[len - 2] == '<' && line[len - 1] == '/') {
        (*current_tag_depth)--;
    }
}

// Function to beautify a block of HTML code
void beautify_code(char* code, int indent) {
    int current_tag_depth = 0;
    char* line = strtok(code, "\n");
    while (line!= NULL) {
        beautify_line(line, &indent, &current_tag_depth);
        printf("%s", line);
        line = strtok(NULL, "\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    char* code = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&code, &len, file))!= -1) {
        code[read - 1] = '\0';
        beautify_code(code, 0);
        printf("\n");
    }

    free(code);
    fclose(file);

    return 0;
}