//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int count;
} Word;

bool is_alphanumeric(char c) {
    return (isalpha(c) || isdigit(c) || c == '_');
}

void split_word(const char *input, char output[]) {
    int i = 0;
    bool in_word = false;

    while (*input != '\0') {
        if (is_alphanumeric(*input)) {
            if (!in_word) {
                in_word = true;
                output[i] = tolower(*input);
                i++;
            }
            output[i] = tolower(*input);
            i++;
        } else if (in_word) {
            output[i] = '_';
            i++;
        }

        input++;
    }

    output[i] = '\0';
}

int main() {
    Word words[MAX_WORDS];
    int num_words = 0;

    printf("Exciting C Word Frequency Counter!\n");
    printf("---------------------------------\n");

    while (true) {
        char input[100];
        char word[WORD_LENGTH];
        int i;

        printf("Enter a word starting with 'C' or type 'quit' to exit: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "quit") == 0) {
            break;
        }

        split_word(input, word);

        for (i = 0; i < num_words; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                break;
            }
        }

        if (i == num_words) {
            for (i = 0; i < MAX_WORDS; i++) {
                if (words[i].count == 0) {
                    strcpy(words[i].word, word);
                    words[i].count = 1;
                    num_words++;
                    break;
                }
            }

            if (i == MAX_WORDS) {
                printf("Word limit reached! Please consider upgrading to a larger array.\n");
                return 1;
            }
        }
    }

    printf("\nWord Frequencies:\n");
    printf("-----------------\n");

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}