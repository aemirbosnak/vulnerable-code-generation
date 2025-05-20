//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char* english;
    char* cat;
} Word;

int main() {
    // Load dictionary
    Word dictionary[MAX_WORDS];
    int num_words = 0;
    FILE* fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        char* english_word = strtok(line, ",");
        char* cat_word = strtok(NULL, ",");
        if (english_word == NULL || cat_word == NULL) {
            printf("Error: malformed line in dictionary file.\n");
            return 1;
        }
        dictionary[num_words].english = strdup(english_word);
        dictionary[num_words].cat = strdup(cat_word);
        num_words++;
    }
    fclose(fp);

    // Translate input
    char input[MAX_WORD_LENGTH];
    printf("Enter a sentence to translate:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character
    int num_tokens = 0;
    char* tokens[MAX_WORDS];
    char* token = strtok(input, " ");
    while (token!= NULL && num_tokens < MAX_WORDS) {
        tokens[num_tokens] = token;
        num_tokens++;
        token = strtok(NULL, " ");
    }

    // Output translation
    for (int i = 0; i < num_tokens; i++) {
        char* english_word = tokens[i];
        int english_len = strlen(english_word);
        for (int j = 0; j < num_words; j++) {
            int cat_len = strlen(dictionary[j].english);
            if (english_len == cat_len && strncmp(english_word, dictionary[j].english, cat_len) == 0) {
                printf("%s ", dictionary[j].cat);
                break;
            }
        }
    }
    printf("\n");

    return 0;
}