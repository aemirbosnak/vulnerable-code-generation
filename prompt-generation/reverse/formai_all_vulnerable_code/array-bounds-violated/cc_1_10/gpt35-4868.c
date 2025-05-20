//FormAI DATASET v1.0 Category: Syntax parsing ; Style: detailed
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

// function to check if given string is a valid C variable name
bool isValidVariable(char *str) {
    int len = strlen(str);
    if(len == 0)
        return false;
    if(!isalpha(str[0]) && str[0] != '_')
        return false;
    for(int i=1; i<len; i++) {
        if(!isalnum(str[i]) && str[i] != '_')
            return false;
    }
    return true;
}

// Function to parse a C statement
void parseStatement(char *statement) {
    char *words[50];
    int count = 0;
    // Split the statement into individual words
    char *word = strtok(statement, " ");
    while(word != NULL) {
        words[count++] = word;
        word = strtok(NULL, " ");
    }
    // Check if the first word is a valid C keyword
    if(strcmp(words[0], "int") == 0 || strcmp(words[0], "char") == 0 || strcmp(words[0], "float") == 0 || strcmp(words[0], "double") == 0 || strcmp(words[0], "void") == 0) {
        printf("Valid C keyword detected: %s\n", words[0]);
        // Check if the second word is a valid variable name
        if(isValidVariable(words[1])) {
            printf("Valid variable name detected: %s\n", words[1]);
            // Check if the third word is an assignment operator
            if(strcmp(words[2], "=") == 0) {
                printf("Valid assignment operator detected\n");
                // Check if the fourth word is a valid number or variable name
                if(isdigit(words[3][0]) || isValidVariable(words[3])) {
                    printf("Valid value detected: %s\n", words[3]);
                    // Check if the statement ends with a semicolon
                    if(words[count-1][strlen(words[count-1])-1] == ';')
                        printf("Syntax is valid!\n");
                    else
                        printf("Statement is missing ';' at the end\n");
                }
                else
                    printf("Invalid value detected\n");
            }
            else
                printf("Invalid assignment operator detected\n");
        }
        else
            printf("Invalid variable name detected\n");
    }
    else
        printf("Invalid C keyword detected\n");
}

int main() {
    char statement[1000];
    printf("Enter a C statement: ");
    fgets(statement, sizeof(statement), stdin);
    statement[strlen(statement)-1] = '\0'; // remove the newline character from the input
    parseStatement(statement);
    return 0;
}