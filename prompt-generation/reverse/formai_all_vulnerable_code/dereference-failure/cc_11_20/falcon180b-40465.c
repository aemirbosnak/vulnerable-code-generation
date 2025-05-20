//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

// Alien language dictionary
struct word {
    char alien[MAX_WORD_LEN];
    char english[MAX_WORD_LEN];
};

int main() {
    FILE *dict;
    char line[MAX_WORD_LEN];
    int num_words = 0;
    struct word *words = malloc(MAX_WORDS * sizeof(struct word));

    // Open dictionary file
    dict = fopen("dictionary.txt", "r");
    if (dict == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    // Read words from file
    while (fscanf(dict, "%s %s", words[num_words].alien, words[num_words].english)!= EOF) {
        num_words++;
        if (num_words >= MAX_WORDS) {
            printf("Error: dictionary is too large.\n");
            exit(1);
        }
    }

    // Close dictionary file
    fclose(dict);

    // Get user input
    printf("Enter a sentence in alien language: ");
    fgets(line, MAX_WORD_LEN, stdin);

    // Convert to uppercase
    for (int i = 0; i < strlen(line); i++) {
        line[i] = toupper(line[i]);
    }

    // Tokenize input
    char *token;
    int num_tokens = 0;
    char *tokens[MAX_WORD_LEN];
    token = strtok(line, " ");
    while (token!= NULL) {
        if (num_tokens >= MAX_WORD_LEN) {
            printf("Error: sentence is too long.\n");
            exit(1);
        }
        tokens[num_tokens] = token;
        num_tokens++;
        token = strtok(NULL, " ");
    }

    // Translate tokens
    int num_translated = 0;
    for (int i = 0; i < num_tokens; i++) {
        for (int j = 0; j < num_words; j++) {
            if (strcmp(tokens[i], words[j].alien) == 0) {
                printf("%s ", words[j].english);
                num_translated++;
                break;
            }
        }
    }

    // Print remaining tokens
    for (int i = num_translated; i < num_tokens; i++) {
        printf("%s ", tokens[i]);
    }

    return 0;
}