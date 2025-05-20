//Falcon-180B DATASET v1.0 Category: Text processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 50

// Function to remove leading and trailing whitespace from a string
char* trim(char* str) {
    char* end = str + strlen(str) - 1;
    while (isspace(*end)) {
        end--;
        *end = '\0';
    }
    return str;
}

// Function to tokenize a string into an array of strings
int tokenize(char* input, char* tokens[]) {
    int count = 0;
    char* token = strtok(input, " \t\n");
    while (token!= NULL && count < MAX_TOKENS) {
        tokens[count] = trim(token);
        count++;
        token = strtok(NULL, " \t\n");
    }
    if (count >= MAX_TOKENS) {
        printf("Error: Too many tokens.\n");
        exit(1);
    }
    return count;
}

// Function to reverse the order of tokens in an array
void reverse_tokens(char* tokens[], int count) {
    for (int i = 0; i < count / 2; i++) {
        char* temp = tokens[i];
        tokens[i] = tokens[count - i - 1];
        tokens[count - i - 1] = temp;
    }
}

// Function to print an array of strings
void print_tokens(char* tokens[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s ", tokens[i]);
    }
    printf("\n");
}

int main() {
    char input[MAX_TOKEN_LENGTH];
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    printf("Enter a string: ");
    fgets(input, MAX_TOKEN_LENGTH, stdin);
    int count = tokenize(input, tokens);
    reverse_tokens(tokens, count);
    print_tokens(tokens, count);
    return 0;
}