//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
    bool translated;
};

int main() {
    FILE *english_file, *alien_file;
    char english_word[MAX_WORD_LENGTH];
    char alien_word[MAX_WORD_LENGTH];
    int num_words = 0;
    struct word words[MAX_WORDS];

    english_file = fopen("english.txt", "r");
    if (english_file == NULL) {
        printf("Error opening English file.\n");
        exit(1);
    }

    alien_file = fopen("alien.txt", "r");
    if (alien_file == NULL) {
        printf("Error opening Alien file.\n");
        exit(1);
    }

    while (fscanf(english_file, "%s", english_word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            exit(1);
        }

        words[num_words].english[0] = toupper(english_word[0]);
        strncpy(words[num_words].english + 1, english_word + 1, MAX_WORD_LENGTH - 1);
        words[num_words].english[strcspn(words[num_words].english, " ")] = '\0';

        while (fscanf(alien_file, "%s", alien_word)!= EOF) {
            if (num_words >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                exit(1);
            }

            strncpy(words[num_words].alien, alien_word, MAX_WORD_LENGTH - 1);
            words[num_words].alien[strcspn(words[num_words].alien, " ")] = '\0';
            words[num_words].translated = true;

            num_words++;
        }
    }

    fclose(english_file);
    fclose(alien_file);

    printf("Enter a sentence in English:\n");
    fgets(english_word, MAX_WORD_LENGTH, stdin);

    for (int i = 0; i < strlen(english_word); i++) {
        if (isalpha(english_word[i])) {
            english_word[i] = toupper(english_word[i]);
        }
    }

    printf("Translated sentence in Alien:\n");
    for (int i = 0; i < strlen(english_word); i++) {
        if (isalpha(english_word[i])) {
            for (int j = 0; j < num_words; j++) {
                if (strcmp(words[j].english, english_word + i) == 0 && words[j].translated) {
                    printf("%s ", words[j].alien);
                    break;
                }
            }
        } else {
            printf("%c", english_word[i]);
        }
    }

    return 0;
}