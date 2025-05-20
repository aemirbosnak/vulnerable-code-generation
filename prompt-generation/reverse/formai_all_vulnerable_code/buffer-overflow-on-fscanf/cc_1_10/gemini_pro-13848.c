//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20
#define MAX_WORDS 100

typedef struct {
    char word[MAX_WORD_LEN];
    char translation[MAX_WORD_LEN];
} word_t;

word_t dictionary[MAX_WORDS];
int dictionary_size = 0;

int main() {
    // Load the dictionary
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        perror("Error opening dictionary file");
        return EXIT_FAILURE;
    }

    while (fscanf(fp, "%s %s", dictionary[dictionary_size].word, dictionary[dictionary_size].translation) != EOF) {
        dictionary_size++;
    }

    fclose(fp);

    // Get the input text
    char input[1000];
    printf("Enter the alien text: ");
    fgets(input, sizeof(input), stdin);

    // Tokenize the input text
    char *tokens[100];
    int num_tokens = 0;
    char *token = strtok(input, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }

    // Translate the input text
    for (int i = 0; i < num_tokens; i++) {
        int found = 0;
        for (int j = 0; j < dictionary_size; j++) {
            if (strcmp(tokens[i], dictionary[j].word) == 0) {
                printf("%s ", dictionary[j].translation);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("%s ", tokens[i]);
        }
    }

    printf("\n");

    return EXIT_SUCCESS;
}