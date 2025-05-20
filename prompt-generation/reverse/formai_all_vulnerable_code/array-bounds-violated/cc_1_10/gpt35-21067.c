//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 10000

char code[MAX_SIZE];

// Function to remove all comments from code
void removeComments() {
    int insideString = 0;
    int insideComment = 0;
    int modifiedIndex = 0;
    for (int i = 0; code[i] != '\0'; i++) {
        if (insideString) {
            if (code[i] == '\"') {
                insideString = 0;
            }
            code[modifiedIndex++] = code[i];
        } else if (insideComment) {
            if (code[i] == '\n') {
                insideComment = 0;
                // Remove the preceding space if there is one
                if (code[modifiedIndex-1] == ' ') {
                    modifiedIndex--;
                }
            }
        } else {
            if (code[i] == '\"') {
                insideString = 1;
            } else if (code[i] == '/') {
                if (code[i+1] == '/') {
                    // A single line comment, skip to next line
                    i++;
                    while (code[i] != '\n') {
                        i++;
                    }
                    // If there was a space before the comment, remove it
                    if (code[modifiedIndex-1] == ' ') {
                        modifiedIndex--;
                    }
                } else if (code[i+1] == '*') {
                    // Start of a multi-line comment, skip to the end
                    i += 2;
                    insideComment = 1;
                } else {
                    // Not a comment, just a division symbol
                    code[modifiedIndex++] = code[i];
                }
            } else {
                code[modifiedIndex++] = code[i];
            }
        }
    }
    code[modifiedIndex] = '\0';
}

// Function to add a space before and after keywords
void addSpaces() {
    char keywords[][20] = {"if", "else", "for", "while", "switch", "case", "default", "break", "return"};
    int numKeywords = 9;
    int modifiedIndex = 0;
    for (int i = 0; code[i] != '\0'; i++) {
        int foundKeyword = 0;
        for (int j = 0; j < numKeywords; j++) {
            int len = strlen(keywords[j]);
            if (strncmp(code+i, keywords[j], len) == 0 && !isalnum(code[i+len])) {
                foundKeyword = 1;
                // Add a space before keyword if there isn't one already
                if (i > 0 && !isspace(code[i-1])) {
                    code[modifiedIndex++] = ' ';
                }
                // Copy the keyword
                for (int k = 0; k < len; k++) {
                    code[modifiedIndex++] = code[i+k];
                }
                // Add a space after keyword if there isn't one already
                if (!isspace(code[i+len])) {
                    code[modifiedIndex++] = ' ';
                }
                // Move i to the end of the keyword
                i += len;
                break;
            }
        }
        if (!foundKeyword) {
            code[modifiedIndex++] = code[i];
        }
    }
    code[modifiedIndex] = '\0';
}

// Main function to read input and call other functions
int main() {
    printf("Enter your code:\n");
    fgets(code, MAX_SIZE, stdin);
    removeComments();
    addSpaces();
    printf("\nCleaned up code:\n%s", code);
    return 0;
}