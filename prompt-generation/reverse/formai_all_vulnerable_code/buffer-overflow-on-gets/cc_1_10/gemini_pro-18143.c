//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a line.
#define MAX_LINE_LENGTH 1024

// Define the maximum number of tags that can be nested.
#define MAX_NESTING_DEPTH 100

// Define the character used to indent lines.
#define INDENT_CHAR ' '

// Define the number of spaces to use for each level of indentation.
#define INDENT_SPACES 2

// Define the tags that should be indented.
char *indented_tags[] = {
    "html", "head", "body", "p", "h1", "h2", "h3", "h4", "h5", "h6",
    "ul", "ol", "li", "dl", "dt", "dd", "table", "tr", "td", "th"
};

// Define the tags that should be broken into a new line.
char *newline_tags[] = {
    "html", "head", "body", "p", "h1", "h2", "h3", "h4", "h5", "h6",
    "ul", "ol", "li", "dl", "dt", "dd", "table", "tr", "td", "th"
};

// Define the tags that should be closed with a newline.
char *newline_close_tags[] = {
    "html", "head", "body", "p", "h1", "h2", "h3", "h4", "h5", "h6",
    "ul", "ol", "li", "dl", "dt", "dd", "table", "tr", "td", "th"
};

// Define the tags that should be self-closing.
char *self_closing_tags[] = {
    "img", "br", "hr", "input", "meta"
};

// Function to indent a line.
void indent(int level) {
    for (int i = 0; i < level * INDENT_SPACES; i++) {
        printf("%c", INDENT_CHAR);
    }
}

// Function to break a line into a new line.
void newline() {
    printf("\n");
}

// Function to close a tag with a newline.
void newline_close(char *tag) {
    printf("</%s>\n", tag);
}

// Function to beautify a HTML document.
void beautify(char *html) {
    // Initialize the stack of tags.
    char *stack[MAX_NESTING_DEPTH];
    int stack_top = -1;

    // Initialize the current level of indentation.
    int level = 0;

    // Loop over each character in the HTML document.
    for (int i = 0; i < strlen(html); i++) {
        // Get the current character.
        char c = html[i];

        // If the current character is a less than sign (<), then the next character is the start of a tag.
        if (c == '<') {
            // Get the tag name.
            char *tag = malloc(MAX_LINE_LENGTH);
            int tag_length = 0;
            i++;
            while (html[i] != '>' && html[i] != ' ') {
                tag[tag_length++] = html[i++];
            }
            tag[tag_length] = '\0';

            // If the tag is an indented tag, then indent the line.
            if (strchr(indented_tags, tag) != NULL) {
                indent(level);
            }

            // If the tag is a newline tag, then break the line into a new line.
            if (strchr(newline_tags, tag) != NULL) {
                newline();
            }

            // If the tag is a self-closing tag, then close the tag.
            if (strchr(self_closing_tags, tag) != NULL) {
                printf(" />");
            }

            // If the tag is not a self-closing tag, then push the tag onto the stack.
            else {
                stack[++stack_top] = tag;
                level++;
            }
        }

        // If the current character is a greater than sign (>), then the tag is closed.
        else if (c == '>') {
            // Pop the tag from the stack.
            char *tag = stack[stack_top--];
            level--;

            // If the tag is a newline tag, then break the line into a new line.
            if (strchr(newline_close_tags, tag) != NULL) {
                newline_close(tag);
            }

            // If the tag is not a newline tag, then close the tag.
            else {
                printf("</%s>", tag);
            }
        }

        // If the current character is not a less than sign (<) or a greater than sign (>), then it is part of the content of the tag.
        else {
            // Print the character.
            printf("%c", c);
        }
    }
}

// Main function.
int main() {
    // Get the HTML document from the user.
    char *html = malloc(MAX_LINE_LENGTH);
    printf("Enter the HTML document: ");
    gets(html);

    // Beautify the HTML document.
    beautify(html);

    // Free the memory allocated for the HTML document.
    free(html);

    // Return 0 to indicate success.
    return 0;
}