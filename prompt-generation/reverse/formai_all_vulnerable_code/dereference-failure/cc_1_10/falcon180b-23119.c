//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_WORD_SIZE 50
#define MAX_TOKENS 20

typedef struct {
    char *name;
    int count;
} Token;

Token tokens[MAX_TOKENS];
int num_tokens = 0;

void add_token(char *name) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        return;
    }

    Token *token = &tokens[num_tokens];
    token->name = strdup(name);
    token->count = 0;

    num_tokens++;
}

int main() {
    FILE *file;
    char line[MAX_LINE_SIZE];
    char *word;

    // Open the file
    file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    // Read the file line by line
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        // Tokenize the line
        word = strtok(line, " ");
        while (word!= NULL) {
            // Convert the word to lowercase
            char *lowercase_word = malloc(strlen(word) + 1);
            strcpy(lowercase_word, word);
            for (int i = 0; i < strlen(lowercase_word); i++) {
                lowercase_word[i] = tolower(lowercase_word[i]);
            }

            // Check if the word is a keyword
            int keyword_found = 0;
            for (int i = 0; i < num_tokens; i++) {
                if (strcmp(lowercase_word, tokens[i].name) == 0) {
                    tokens[i].count++;
                    keyword_found = 1;
                    break;
                }
            }

            // If the word is not a keyword, add it as a new token
            if (!keyword_found) {
                add_token(lowercase_word);
            }

            word = strtok(NULL, " ");
        }
    }

    // Close the file
    fclose(file);

    // Print the token counts
    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %d\n", tokens[i].name, tokens[i].count);
    }

    return 0;
}