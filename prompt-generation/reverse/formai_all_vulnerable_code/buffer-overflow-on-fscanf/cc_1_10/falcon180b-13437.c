//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word {
    char *english;
    char *alien;
};

void load_words(struct word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open words file.\n");
        exit(1);
    }

    int num_words = 0;
    while (fscanf(file, "%s %s", words[num_words].english, words[num_words].alien)!= EOF) {
        num_words++;
    }

    fclose(file);
}

bool is_valid_sentence(char sentence[]) {
    int i = 0;
    while (sentence[i]!= '\0') {
        if (!isalpha(sentence[i])) {
            return false;
        }
        i++;
    }

    return true;
}

void translate_sentence(struct word words[], char sentence[]) {
    int i = 0;
    while (sentence[i]!= '\0') {
        if (isalpha(sentence[i])) {
            char word[MAX_WORD_LENGTH];
            int j = 0;
            while (isalpha(sentence[i]) && j < MAX_WORD_LENGTH - 1) {
                word[j++] = tolower(sentence[i++]);
            }
            word[j] = '\0';

            int num_matches = 0;
            for (int k = 0; k < MAX_WORDS; k++) {
                if (strcmp(word, words[k].english) == 0) {
                    printf("%s ", words[k].alien);
                    num_matches++;
                }
            }

            if (num_matches == 0) {
                printf("unknown ");
            }
        } else {
            printf("%c ", sentence[i]);
        }
        i++;
    }
}

int main() {
    struct word words[MAX_WORDS];
    load_words(words);

    char sentence[1000];
    printf("Enter a sentence to translate: ");
    fgets(sentence, sizeof(sentence), stdin);

    if (is_valid_sentence(sentence)) {
        translate_sentence(words, sentence);
        printf("\n");
    } else {
        printf("Invalid sentence.\n");
    }

    return 0;
}