//FormAI DATASET v1.0 Category: Syntax parsing ; Style: brave
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// Declare global variables
char input[1000];
int i = 0;
int error_flag = 0;

// Declare functions
void program();
void block();
void statement();
void expression();
void term();
void factor();

int main() {
    printf("Enter a C-syntax program:\n");
    scanf("%[^\n]s", input);
    program();
    if (error_flag == 0) {
        printf("Syntax is correct.\n");
    }
    return 0;
}

void program() {
    block();
    if (input[i] != '.') {
        printf("Error: Missing '.' at the end of the program.\n");
        error_flag = 1;
    }
}

void block() {
    if (input[i] == '{') {
        i++;
        statement();
        while (input[i] == ';') {
            i++;
            statement();
        }
        if (input[i] == '}') {
            i++;
        } else {
            printf("Error: Missing '}' at the end of the statement.\n");
            error_flag = 1;
        }
    } else {
        printf("Error: Missing '{' at the beginning of the statement.\n");
        error_flag = 1;
    }
}

void statement() {
    expression();
}

void expression() {
    term();
    while (input[i] == '+' || input[i] == '-') {
        i++;
        term();
    }
}

void term() {
    factor();
    while (input[i] == '*' || input[i] == '/') {
        i++;
        factor();
    }
}

void factor() {
    if (isalpha(input[i])) {
        i++;
        if (!isalnum(input[i])) {
            return;
        } else {
            printf("Error: Invalid variable name.\n");
            error_flag = 1;
        }
    } else if (isdigit(input[i])) {
        i++;
        while (isdigit(input[i])) {
            i++;
        }
        return;
    } else if (input[i] == '(') {
        i++;
        expression();
        if (input[i] == ')') {
            i++;
            return;
        } else {
            printf("Error: Missing ')' at the end of expression.\n");
            error_flag = 1;
        }
    } else {
        printf("Error: Invalid character.\n");
        error_flag = 1;
    }
}