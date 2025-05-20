//FormAI DATASET v1.0 Category: HTML beautifier ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB_SIZE 4

int main(int argc, char **argv) {

    if(argc <= 1) {
        printf("Usage: %s filename\n", argv[0]);
        return 0;
    }

    FILE *fp = fopen(argv[1], "r");

    if(fp == NULL) {
        printf("Unable to open file %s\n", argv[1]);
        return 0;
    }

    // Get file size
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for file contents
    char *contents = (char*)malloc(size + 1);

    if(contents == NULL) {
        printf("Memory allocation failed\n");
        fclose(fp);
        return 0;
    }

    // Read file contents into memory
    fread(contents, size, 1, fp);
    fclose(fp);
    contents[size] = '\0';

    // Count number of lines and allocate memory for line contents
    int lines = 0;
    char **lineContents = (char**)malloc(sizeof(char*) * (lines + 1));
    char *line = strtok(contents, "\n");

    while(line != NULL) {
        lines++;
        lineContents = (char**)realloc(lineContents, sizeof(char*) * (lines + 1));
        lineContents[lines - 1] = line;
        line = strtok(NULL, "\n");
    }

    // Beautify HTML
    int indentationLevel = 0;

    for(int i=0; i<lines; i++) {

        // Check if opening tag
        if(lineContents[i][0] == '<' && lineContents[i][1] != '/') {

            // Indent current line
            for(int j=0; j<TAB_SIZE * indentationLevel; j++) {
                putchar(' ');
            }

            // Print current line
            printf("%s\n", lineContents[i]);

            // Increase indentation level
            indentationLevel++;
        }

        // Check if closing tag
        else if(lineContents[i][0] == '<' && lineContents[i][1] == '/') {

            // Decrease indentation level
            indentationLevel--;

            // Indent current line
            for(int j=0; j<TAB_SIZE * indentationLevel; j++) {
                putchar(' ');
            }

            // Print current line
            printf("%s\n", lineContents[i]);
        }

        // Otherwise, no tag
        else {

            // Indent current line
            for(int j=0; j<TAB_SIZE * indentationLevel; j++) {
                putchar(' ');
            }

            // Print current line
            printf("%s\n", lineContents[i]);
        }
    }

    // Free memory
    free(contents);
    free(lineContents);

    return 0;
}