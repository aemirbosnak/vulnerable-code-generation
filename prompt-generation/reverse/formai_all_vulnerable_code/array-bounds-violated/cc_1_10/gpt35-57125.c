//FormAI DATASET v1.0 Category: Syntax parsing ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printError(char* errorMessage) {
    printf("Error: %s\n", errorMessage);
}

int isValidVariable(char* variable) {
    if ((variable[0] >= 'a' && variable[0] <= 'z') || (variable[0] >= 'A' && variable[0] <= 'Z')) {
        return 1;
    } else {
        return 0;
    }
}

int isValidNumber(char* number) {
    int length = strlen(number);
    for (int i = 0; i < length; i++) {
        if (number[i] < '0' || number[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[100];
    printf("Enter C code: ");
    fgets(input, 100, stdin);

    // Remove newline character at end of input
    input[strlen(input)-1] = '\0';

    // Tokenize input into individual words
    char* word = strtok(input, " ");

    while (word != NULL) {
        if (isValidVariable(word)) {
            printf("%s is a valid variable.\n", word);
        } else if (isValidNumber(word)) {
            printf("%s is a valid number.\n", word);
        } else if (strcmp(word, "int") == 0) {
            printf("Variable type: int.\n");
        } else if (strcmp(word, "char") == 0) {
            printf("Variable type: char.\n");
        } else if (strcmp(word, "float") == 0) {
            printf("Variable type: float.\n");
        } else if (strcmp(word, "double") == 0) {
            printf("Variable type: double.\n");
        } else if (strcmp(word, "if") == 0) {
            printf("If statement detected.\n");
        } else if (strcmp(word, "for") == 0) {
            printf("For loop detected.\n");
        } else if (strcmp(word, "while") == 0) {
            printf("While loop detected.\n");
        } else {
            printError("Unknown token.");
            return 1;
        }
        word = strtok(NULL, " ");
    }

    printf("Parsing complete.\n");
    return 0;
}