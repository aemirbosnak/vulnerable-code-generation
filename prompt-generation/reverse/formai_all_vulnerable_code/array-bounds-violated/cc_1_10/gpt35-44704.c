//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

typedef struct {
    char* tag_name;
    char* content;
} Element;

void parse_xml(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    char line[MAX_LENGTH];
    Element stack[MAX_LENGTH];
    int top = -1;

    while (fgets(line, MAX_LENGTH, fp)) {
        // Removing trailing newline character from line
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        if (line[0] == '<' && line[1] != '/') {
            // This is an opening tag
            char* tag_name = strtok(line + 1, ">");
            Element new_element = { .tag_name = strdup(tag_name), .content = NULL };
            stack[++top] = new_element;
        } else if (line[0] == '<' && line[1] == '/') {
            // This is a closing tag
            char* tag_name = strtok(line + 2, ">");
            if (strcmp(stack[top].tag_name, tag_name) == 0) {
                // Matching closing tag found, print the element content
                printf("%s: %s\n", stack[top].tag_name, stack[top].content);
                free(stack[top].tag_name);
                free(stack[top].content);
                top--;
            } else {
                printf("Error: mismatched tag found.\n");
                exit(1);
            }
        } else {
            // This is the content inside an element
            if (top != -1) {
                if (stack[top].content == NULL) {
                    stack[top].content = strdup(line);
                } else {
                    char* tmp = malloc(strlen(stack[top].content) + strlen(line) + 1);
                    strcpy(tmp, stack[top].content);
                    strcat(tmp, line);
                    free(stack[top].content);
                    stack[top].content = tmp;
                }
            } else {
                printf("Error: content found outside of element.\n");
                exit(1);
            }
        }
    }

    fclose(fp);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename.xml\n", argv[0]);
        return 1;
    }

    parse_xml(argv[1]);

    return 0;
}