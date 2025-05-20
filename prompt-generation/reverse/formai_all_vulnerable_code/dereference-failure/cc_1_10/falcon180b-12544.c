//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char *english;
    char *alien;
};

int main() {
    struct word words[MAX_WORDS];
    int num_words = 0;
    int i;

    FILE *english_file = fopen("english.txt", "r");
    if (english_file == NULL) {
        printf("Error: could not open english.txt\n");
        exit(1);
    }

    FILE *alien_file = fopen("alien.txt", "r");
    if (alien_file == NULL) {
        printf("Error: could not open alien.txt\n");
        exit(1);
    }

    char english_word[MAX_WORD_LENGTH];
    char alien_word[MAX_WORD_LENGTH];

    while (fscanf(english_file, "%s", english_word)!= EOF) {
        fscanf(alien_file, "%s", alien_word);

        if (num_words >= MAX_WORDS) {
            printf("Error: too many words\n");
            exit(1);
        }

        words[num_words].english = strdup(english_word);
        words[num_words].alien = strdup(alien_word);
        num_words++;
    }

    fclose(english_file);
    fclose(alien_file);

    printf("Enter a sentence to translate:\n");
    char sentence[1000];
    fgets(sentence, sizeof(sentence), stdin);

    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].alien);
                break;
            }
        }

        if (i == num_words) {
            printf("%s ", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");

    for (i = 0; i < num_words; i++) {
        free(words[i].english);
        free(words[i].alien);
    }

    return 0;
}