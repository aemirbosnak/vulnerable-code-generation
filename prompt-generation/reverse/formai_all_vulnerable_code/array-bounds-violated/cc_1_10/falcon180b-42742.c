//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void translate(char* input);
void tokenize(char* input, char** tokens);
void print_tokens(char** tokens, int count);
void free_tokens(char** tokens, int count);

int main() {
    char input[1000];
    printf("Enter a sentence to translate into Cat Language: ");
    fgets(input, sizeof(input), stdin);
    translate(input);
    return 0;
}

void translate(char* input) {
    char* tokens[100];
    int count = 0;
    tokenize(input, tokens);

    // Replace certain words with their Cat Language equivalents
    for (int i = 0; i < count; i++) {
        if (strcmp(tokens[i], "meow") == 0) {
            strcpy(tokens[i], "mew");
        } else if (strcmp(tokens[i], "purr") == 0) {
            strcpy(tokens[i], "purrr");
        } else if (strcmp(tokens[i], "hiss") == 0) {
            strcpy(tokens[i], "hisss");
        }
    }

    // Add "meow" at the end of the sentence
    char* meow = " meow";
    strcat(tokens[count - 1], meow);
    count++;

    // Print the translated sentence
    printf("Translated sentence: ");
    print_tokens(tokens, count);
}

void tokenize(char* input, char** tokens) {
    char* token = strtok(input, " ");
    int count = 0;

    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, " ");
    }
}

void print_tokens(char** tokens, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s ", tokens[i]);
    }
}

void free_tokens(char** tokens, int count) {
    for (int i = 0; i < count; i++) {
        free(tokens[i]);
    }
}