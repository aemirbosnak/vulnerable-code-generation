//FormAI DATASET v1.0 Category: Syntax parsing ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char token_name[20];
    char token_value[50];
} Token;

int main() {
    char input_string[100];
    printf("Enter an expression to parse: ");
    fgets(input_string, 100, stdin);

    int len = strlen(input_string);
    if (input_string[len-1] == '\n') {
        input_string[len-1] = '\0';
    }

    Token tokens[10];
    int token_count = 0;
    char current_token_value[50];
    int current_token_count = 0;

    for (int i = 0; i < strlen(input_string); i++) {
        if (isdigit(input_string[i])) {
            current_token_value[current_token_count++] = input_string[i];
        } else if (isspace(input_string[i])) {
            if (current_token_count > 0) { // Create token
                current_token_value[current_token_count] = '\0';
                strcpy(tokens[token_count].token_name, "Number");
                strcpy(tokens[token_count].token_value, current_token_value);
                token_count++;
                current_token_count = 0;
            }
        } else {
            printf("Syntax error! Invalid character: %c\n", input_string[i]);
            return 0;
        }
    }

    if (current_token_count > 0) { // Create token for last set of digits
        current_token_value[current_token_count] = '\0';
        strcpy(tokens[token_count].token_name, "Number");
        strcpy(tokens[token_count].token_value, current_token_value);
        token_count++;
    }

    printf("Tokens:\n");
    for (int i = 0; i < token_count; i++) {
        printf("%s %s\n", tokens[i].token_name, tokens[i].token_value);
    }

    return 0;
}