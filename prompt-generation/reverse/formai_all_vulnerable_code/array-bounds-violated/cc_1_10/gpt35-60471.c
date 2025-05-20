//FormAI DATASET v1.0 Category: HTML beautifier ; Style: futuristic
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINES 1000
#define LINE_LENGTH 1000

void beautify(char* code[]);
void remove_extra_spaces(char* line);
void remove_extra_tabs(char* line);
void add_indentation(char* line, int indent_level);

int main() {
    char code[MAX_LINES][LINE_LENGTH];
    char* code_ptr[MAX_LINES];
    int i = 0, j = 0;
    bool in_string = false;

    printf("Enter the code to beautify: \n");

    // read the code and save it as a double pointer
    while (i < MAX_LINES && fgets(code[i], LINE_LENGTH, stdin)) {
        // remove the trailing newline character
        code[i][strlen(code[i]) - 1] = '\0';
        code_ptr[i] = code[i];

        // process double quotes
        while (j < LINE_LENGTH && code[i][j] != '\0') {
            if (code[i][j] == '\"') {
                in_string = !in_string;
            } else if (!in_string && code[i][j] == '#' && j == 0) {
                // skip comments
                i--;
                break;
            }
            j++;
        }
        i++;
    }

    beautify(code_ptr);

    printf("\nHere is the beautified code: \n\n");
    
    // print the beautified code
    for (int i = 0; i < MAX_LINES && code_ptr[i]; i++) {
        printf("%s\n", code_ptr[i]);
    }

    return 0;
}

// function to beautify the code
void beautify(char* code[]) {
    int indent_level = 0;

    for (int i = 0; code[i]; i++) {
        // remove extra spaces and tabs
        remove_extra_spaces(code[i]);
        remove_extra_tabs(code[i]);

        // add indentation
        if (strstr(code[i], "}") != NULL) {
            indent_level--;
        }
        add_indentation(code[i], indent_level);
        if (strstr(code[i], "{") != NULL) {
            indent_level++;
        }
    }
}

// function to remove extra spaces
void remove_extra_spaces(char* line) {
    int i = 0, j = 0;
    bool in_string = false;

    while (line[i] != '\0') {
        if (line[i] == '\"') {
            in_string = !in_string;
            line[j] = line[i];
            j++;
        } else if (!in_string && (line[i] != ' ' || (i > 0 && line[i-1] != ' '))) {
            line[j] = line[i];
            j++;
        }
        i++;
    }
    line[j] = '\0';
}

// function to remove extra tabs
void remove_extra_tabs(char* line) {
    int i = 0, j = 0;
    bool in_string = false;

    while (line[i] != '\0') {
        if (line[i] == '\"') {
            in_string = !in_string;
            line[j] = line[i];
            j++;
        } else if (!in_string && (line[i] != '\t' || (i > 0 && line[i-1] != '\t'))) {
            line[j] = line[i];
            j++;
        }
        i++;
    }
    line[j] = '\0';
}

// function to add indentation
void add_indentation(char* line, int indent_level) {
    char indentation[1000];

    for (int i = 0; i < indent_level; i++) {
        strcat(indentation, "\t");
    }

    sprintf(line, "%s%s", indentation, line);
}