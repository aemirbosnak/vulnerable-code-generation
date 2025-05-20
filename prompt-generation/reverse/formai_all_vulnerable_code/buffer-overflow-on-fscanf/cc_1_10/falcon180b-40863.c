//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char english[MAX_WORD_LEN];
    char cat[MAX_WORD_LEN];
} word_t;

int main() {
    FILE *dict_file;
    char line[MAX_WORD_LEN];
    word_t words[MAX_WORDS];
    int num_words = 0;
    char input_sentence[MAX_WORD_LEN * 100];
    char *token;

    // Open dictionary file
    dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error: could not open dictionary file\n");
        exit(1);
    }

    // Read words from dictionary file
    while (fscanf(dict_file, "%s %s", line, words[num_words].cat) == 2) {
        strcpy(words[num_words].english, line);
        num_words++;
        if (num_words >= MAX_WORDS) {
            printf("Error: dictionary file too large\n");
            exit(1);
        }
    }
    fclose(dict_file);

    // Get input sentence
    printf("Enter a sentence to translate:\n");
    fgets(input_sentence, MAX_WORD_LEN * 100, stdin);

    // Tokenize input sentence
    token = strtok(input_sentence, " ");
    while (token!= NULL) {
        // Look up word in dictionary
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].cat);
                break;
            }
        }
        if (i == num_words) {
            printf("unknown ");
        }
        token = strtok(NULL, " ");
    }
    printf("\n");

    return 0;
}