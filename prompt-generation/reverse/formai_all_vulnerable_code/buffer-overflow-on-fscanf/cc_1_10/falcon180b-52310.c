//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

void read_words(Word words[], int num_words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    int i = 0;
    while (i < num_words && fscanf(file, "%s", words[i].word)!= EOF) {
        i++;
    }
    fclose(file);
}

bool is_correct(const char *word) {
    if (strlen(word) > MAX_WORD_LENGTH) {
        return false;
    }
    for (int i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    Word words[MAX_WORDS];
    int num_words = 0;

    read_words(words, MAX_WORDS);
    num_words = MAX_WORDS;

    char input[MAX_WORD_LENGTH];
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        char *word = strtok(input, ",.?!;:");
        while (word!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].is_correct = is_correct(word);
                    break;
                }
            }
            if (i == num_words) {
                if (is_correct(word)) {
                    printf("%s is spelled correctly.\n", word);
                } else {
                    printf("%s is not spelled correctly.\n", word);
                }
            }
            word = strtok(NULL, ",.?!;:");
        }
    }

    return 0;
}