//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100
#define MAX_STRINGS 100
#define MAX_STRING_LENGTH 100

typedef struct {
    int token[MAX_TOKENS];
    char string[MAX_STRINGS][MAX_STRING_LENGTH];
} Tokenizer;

void tokenize(char *input, Tokenizer *tokenizer) {
    int count = 0;
    char *token = strtok(input, " ");
    while (token!= NULL) {
        strcpy(tokenizer->string[count], token);
        tokenizer->token[count] = atoi(token);
        count++;
        token = strtok(NULL, " ");
    }
    tokenizer->token[count] = 0;
}

int main() {
    Tokenizer tokenizer;
    char input[MAX_TOKEN_LENGTH];
    int choice;
    int result;

    do {
        printf("Enter a string to tokenize: ");
        fgets(input, MAX_TOKEN_LENGTH, stdin);
        tokenize(input, &tokenizer);

        printf("Enter the operation to perform:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            result = tokenizer.token[0] + tokenizer.token[1];
            printf("Result: %d\n", result);
            break;
        case 2:
            result = tokenizer.token[0] - tokenizer.token[1];
            printf("Result: %d\n", result);
            break;
        case 3:
            result = tokenizer.token[0] * tokenizer.token[1];
            printf("Result: %d\n", result);
            break;
        case 4:
            if (tokenizer.token[1] == 0) {
                printf("Error: Division by zero\n");
            } else {
                result = tokenizer.token[0] / tokenizer.token[1];
                printf("Result: %d\n", result);
            }
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}