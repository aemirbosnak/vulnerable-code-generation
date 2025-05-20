//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: irregular
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main() {
    FILE *file;
    struct word *words = NULL;
    int num_words = 0;
    int i;

    file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        return 1;
    }

    while (fscanf(file, "%s", words[num_words].word)!= EOF) {
        num_words++;
        if (num_words == MAX_WORDS) {
            printf("Error: too many words in words.txt\n");
            return 1;
        }
    }

    fclose(file);

    printf("Enter text to spell check:\n");
    char *text = NULL;
    size_t text_size = 0;
    if (getline(&text, &text_size, stdin) == -1) {
        printf("Error: could not read input\n");
        return 1;
    }

    char *word = strtok(text, ",.?!;:");
    while (word!= NULL) {
        int found = 0;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].word) == 0) {
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Possible spelling error: %s\n", word);
        }

        word = strtok(NULL, ",.?!;:");
    }

    free(text);
    for (i = 0; i < num_words; i++) {
        free(words[i].word);
    }
    free(words);

    return 0;
}