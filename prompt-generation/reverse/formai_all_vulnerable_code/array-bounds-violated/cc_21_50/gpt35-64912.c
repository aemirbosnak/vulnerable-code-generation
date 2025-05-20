//FormAI DATASET v1.0 Category: Syntax parsing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    printf("Enter a C statement: ");
    fgets(input, 100, stdin);

    // Check if the statement ends with a semicolon
    if(input[strlen(input)-2] != ';') {
        printf("Error: Statement does not end with a semicolon.\n");
        return 0;
    }

    // Remove semicolon
    input[strlen(input)-2] = '\0';

    char *token = strtok(input, " ");
    int count = 0;
    while(token != NULL) {
        if(count == 0) {
            // Check if the first word is a data type
            if(strcmp(token, "int") != 0 && strcmp(token, "float") != 0 && strcmp(token, "char") != 0) {
                printf("Error: Invalid data type.\n");
                return 0;
            }
        } else if(count == 1) {
            // Check if the second word is a variable name
            if(token[0] < 'a' || token[0] > 'z') {
                printf("Error: Invalid variable name.\n");
                return 0;
            }
            for(int i = 1; i < strlen(token); i++) {
                if((token[i] < 'a' || token[i] > 'z') && (token[i] < '0' || token[i] > '9')) {
                    printf("Error: Invalid variable name.\n");
                    return 0;
                }
            }
        } else if(count == 2) {
            // Check if the third word is an equals sign
            if(strcmp(token, "=") != 0) {
                printf("Error: Missing equals sign.\n");
                return 0;
            }
        } else if(count == 3) {
            // Check if the fourth word is a value
            for(int i = 0; i < strlen(token); i++) {
                if((token[i] < '0' || token[i] > '9') && token[i] != '.') {
                    printf("Error: Invalid value.\n");
                    return 0;
                }
            }
        }
        token = strtok(NULL, " ");
        count++;
    }
    printf("Statement is valid.\n");
    return 0;
}