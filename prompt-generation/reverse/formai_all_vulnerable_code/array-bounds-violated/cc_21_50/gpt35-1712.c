//FormAI DATASET v1.0 Category: Syntax parsing ; Style: statistical
#include <stdio.h>

int main() {

    // Welcome to our C Syntax Parsing Program!
    printf("Welcome to our C Syntax Parsing Program!\n\n");

    // Declare and initialize variables
    char code[1000];
    int i, brackets = 0, parenthesis = 0, curlyBraces = 0, doubleQuotes = 0, singleQuotes = 0, lineCount = 0, charCount = 0, keywordCount = 0, operationCount = 0, variableCount = 0;

    // Prompt the user to enter C code
    printf("Please enter C code to be parsed:\n");
    fgets(code, 1000, stdin);

    // Iterate through code to check for syntax errors and gather statistics
    for (i = 0; i < strlen(code); i++) {
        // Count lines and characters
        if (code[i] == '\n') {
            lineCount++;
            charCount++;
        } else {
            charCount++;
        }
        // Check for double quotes
        if (code[i] == '"') {
            doubleQuotes++;
        }
        // Check for single quotes
        if (code[i] == '\'') {
            singleQuotes++;
        }
        // Check for brackets
        if (code[i] == '(') {
            parenthesis++;
        } else if (code[i] == ')') {
            parenthesis--;
        } else if (code[i] == '[') {
            brackets++;
        } else if (code[i] == ']') {
            brackets--;
        } else if (code[i] == '{') {
            curlyBraces++;
        } else if (code[i] == '}') {
            curlyBraces--;
        }
        // Check for keywords and variables
        if (isalpha(code[i]) && !(isalpha(code[i-1]) || isdigit(code[i-1]) || code[i-1] == '_')) {
            char word[30];
            int j = 0;
            while (isalpha(code[i])) {
                word[j] = code[i];
                i++;
                j++;
            }
            word[j] = '\0';
            if (strcmp(word, "int") == 0 || strcmp(word, "char") == 0 || strcmp(word, "float") == 0 || strcmp(word, "double") == 0) {
                keywordCount++;
            } else {
                variableCount++;
            }
        }
        // Check for arithmetic and logical operations
        if (code[i] == '+' || code[i] == '-' || code[i] == '*' || code[i] == '/' || code[i] == '%' || code[i] == '>' || code[i] == '<' || code[i] == '=' || code[i] == '!' || code[i] == '&' || code[i] == '|') {
            if (code[i+1] == '=') {
                i++;
            }
            operationCount++;
        }
    }

    // Print statistics
    printf("\n-----STATISTICS-----\n");
    printf("Lines: %d\n", lineCount);
    printf("Characters: %d\n", charCount);
    printf("Number of double quotes: %d\n", doubleQuotes);
    printf("Number of single quotes: %d\n", singleQuotes);
    printf("Number of brackets: %d\n", brackets);
    printf("Number of parenthesis: %d\n", parenthesis);
    printf("Number of curly braces: %d\n", curlyBraces);
    printf("Number of keywords: %d\n", keywordCount);
    printf("Number of variables: %d\n", variableCount);
    printf("Number of operations: %d\n", operationCount);

    return 0;
}