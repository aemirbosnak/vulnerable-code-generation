//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STRING_SIZE 1024
#define MAX_TOKEN_SIZE 50
#define MAX_NUM_TOKENS 100

void process_string(char *input_string) {
    char tokens[MAX_NUM_TOKENS][MAX_TOKEN_SIZE];
    int token_count = 0;
    char *token = strtok(input_string, " ");

    while (token != NULL) {
        strcpy(tokens[token_count], token);
        token_count++;
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < token_count; i++) {
        int len = strlen(tokens[i]);

        // Capitalize first letter
        if (isalpha(tokens[i][0])) {
            tokens[i][0] = toupper(tokens[i][0]);
        }

        // Reverse the string
        char reversed[len];
        for (int j = 0; j < len; j++) {
            reversed[len - j - 1] = tokens[i][j];
        }
        reversed[len] = '\0';

        // Concatenate original token and reversed token
        char concatenated[len + len];
        strcpy(concatenated, tokens[i]);
        strcat(concatenated, reversed);

        printf("%s -> %s\n", tokens[i], concatenated);
    }
}

int main() {
    char input_string[MAX_STRING_SIZE];

    printf("Enter a string: ");
    fgets(input_string, MAX_STRING_SIZE, stdin);

    // Remove newline character from input_string
    input_string[strcspn(input_string, "\n")] = '\0';

    process_string(input_string);

    return 0;
}