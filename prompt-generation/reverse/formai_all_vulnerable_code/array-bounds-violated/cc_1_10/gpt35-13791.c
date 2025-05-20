//FormAI DATASET v1.0 Category: HTML beautifier ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 256

// helper function to push a new indentation level onto the stack
void push_indent(int *stack, int *top, int indent) {
    stack[++(*top)] = indent;
}

// helper function to pop the most recent indentation level off the stack
int pop_indent(int *stack, int *top) {
    return stack[(*top)--];
}

// main function, reads input file and outputs formatted HTML code
int main(void) {
    // create a stack to keep track of current indentation level
    int indent_stack[MAX_LINE_LEN] = {0};
    int indent_top = -1;
    int curr_indent = 0;
    
    // open input file for reading
    FILE *input_file = fopen("input.html", "r");
    if (!input_file) {
        printf("Error: could not open input file\n");
        return 1;
    }

    // open output file for writing
    FILE *output_file = fopen("output.html", "w");
    if (!output_file) {
        printf("Error: could not open output file\n");
        return 1;
    }

    // read input file line by line
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, input_file) != NULL) {
        // check if line is a closing tag, pop indentation level if so
        if (line[1] == '/') {
            curr_indent = pop_indent(indent_stack, &indent_top);
        }

        // print current indentation level
        for (int i = 0; i < curr_indent; i++) {
            fprintf(output_file, "    ");
        }

        // print the current line
        fprintf(output_file, "%s", line);

        // check if line is an opening tag that doesn't immediately close
        if (line[strlen(line)-2] != '/') {
            // push new indentation level onto stack
            push_indent(indent_stack, &indent_top, curr_indent + 1);
            curr_indent++;
        }
    }

    // close input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}