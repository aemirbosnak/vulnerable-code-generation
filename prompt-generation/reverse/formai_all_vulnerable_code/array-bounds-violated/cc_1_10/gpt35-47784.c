//FormAI DATASET v1.0 Category: HTML beautifier ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB_SIZE 4

// Function to add newline and spaces based on the indentation level
void add_indentation(char* output, int indentation_level) {
    strcat(output, "\n"); // Add newline character
    for(int i = 0; i < indentation_level; i++) {
        for(int j = 0; j < TAB_SIZE; j++) {
            strcat(output, " "); // Add spaces based on the indentation level
        }
    }
}

int main() {
    char input[10000];
    char output[10000];
    char line[1000];
    int indentation_level = 0;
    int line_length;

    // Read input from user
    printf("Enter your HTML code:\n");
    fgets(input,10000,stdin);

    // Remove any newline character from the input
    input[strlen(input)-1] = '\0';

    // Tokenize input into lines
    char* token = strtok(input, "\n");

    while (token != NULL) {
        line_length = strlen(token);

        // Check if the line is a closing tag
        if(token[0] == '<' && token[1] == '/') {
            indentation_level--;
            add_indentation(output, indentation_level);
        }

        // Add indentation before the line
        add_indentation(output, indentation_level);

        // Copy the line to the output
        strcat(output, token);

        // Check if the line is an opening tag
        if(token[0] == '<' && token[line_length-2] != '/') {
            indentation_level++;
        }

        token = strtok(NULL, "\n");
    }

    printf("\nHere is your beautified HTML code:\n%s\n", output);

    return 0;
}