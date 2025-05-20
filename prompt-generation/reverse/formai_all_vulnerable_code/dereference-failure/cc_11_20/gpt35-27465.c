//FormAI DATASET v1.0 Category: HTML beautifier ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB_SIZE 4  // Number of spaces for each tab

int main(int argc, char* argv[]) {
    // Read file path from command-line arguments
    if(argc < 2) {
        printf("Please specify file path as argument\n");
        return 1;
    }
    char* file_path = argv[1];

    // Open file
    FILE* fp = fopen(file_path, "r");
    if(fp == NULL) {
        printf("Unable to open file\n");
        return 1;
    }

    // Read file contents into a buffer
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char* buffer = (char*)malloc(file_size + 1);
    fread(buffer, file_size, 1, fp);
    fclose(fp);
    buffer[file_size] = '\0';

    // Initialize indentation level to 0
    int indent_level = 0;

    // Parse HTML code and beautify it
    char* token = strtok(buffer, "\n");
    while(token != NULL) {
        // Remove leading and trailing white spaces
        int len = strlen(token);
        while(len > 0 && (token[len-1] == ' ' || token[len-1] == '\t')) {
            token[len-1] = '\0';
            len--;
        }
        while(*token == ' ' || *token == '\t') {
            token++;
            len--;
        }

        if(*token == '<') {
            // HTML tag
            if(token[len-1] == '>') {
                // One-line tag
                for(int i = 0; i < indent_level; i++)
                    printf(" ");
                printf("%s\n", token);
            }
            else {
                // Multi-line tag
                for(int i = 0; i < indent_level; i++)
                    printf(" ");
                printf("%s\n", token);
                indent_level += TAB_SIZE;
            }
        }
        else if(*token == '<' && token[len-2] == '/') {
            // Self-closing tag
            indent_level -= TAB_SIZE;
            for(int i = 0; i < indent_level; i++)
                printf(" ");
            printf("%s\n", token);
        }
        else {
            // Inner text
            for(int i = 0; i < indent_level; i++)
                printf(" ");
            printf("%s\n", token);
        }

        // Get next token
        token = strtok(NULL, "\n");
    }

    // Free memory
    free(buffer);

    return 0;
}