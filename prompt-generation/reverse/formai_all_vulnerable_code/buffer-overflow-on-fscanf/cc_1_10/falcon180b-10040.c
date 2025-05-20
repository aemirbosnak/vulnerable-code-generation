//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} word_pair;

bool load_words(word_pair words[MAX_WORDS]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        return false;
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].english, words[count].alien) == 2) {
        count++;
        if (count >= MAX_WORDS) {
            printf("Too many words in file.\n");
            fclose(file);
            return false;
        }
    }

    fclose(file);
    return true;
}

void translate_sentence(const char *sentence, word_pair words[MAX_WORDS]) {
    char word[MAX_WORD_LENGTH];
    char alien_word[MAX_WORD_LENGTH];
    int i = 0;
    while (*sentence!= '\0') {
        if (isalpha(*sentence)) {
            word[i] = tolower(*sentence);
            i++;
            if (i >= MAX_WORD_LENGTH) {
                printf("Word too long.\n");
                return;
            }
        } else if (isspace(*sentence)) {
            word[i] = '\0';
            i = 0;

            bool found = false;
            for (int j = 0; j < MAX_WORDS; j++) {
                if (strcmp(word, words[j].english) == 0) {
                    strcpy(alien_word, words[j].alien);
                    found = true;
                    break;
                }
            }

            if (!found) {
                printf("Word not found.\n");
                return;
            }

            printf("%s ", alien_word);
        }
        sentence++;
    }
}

int main() {
    word_pair words[MAX_WORDS];
    if (!load_words(words)) {
        return 1;
    }

    char sentence[1000];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, sizeof(sentence), stdin);

    translate_sentence(sentence, words);

    return 0;
}