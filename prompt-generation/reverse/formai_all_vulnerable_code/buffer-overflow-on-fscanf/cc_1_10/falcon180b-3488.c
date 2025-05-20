//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} word_t;

int load_words(word_t words[]) {
    FILE *file = fopen("words.txt", "r");
    if (!file) {
        printf("Error opening file\n");
        return -1;
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].english, words[count].alien) == 2) {
        count++;
        if (count >= MAX_WORDS) {
            printf("Too many words\n");
            fclose(file);
            return -1;
        }
    }

    fclose(file);
    return count;
}

int translate_sentence(char sentence[], word_t words[], int num_words) {
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
            printf("unknown word: %s\n", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");
    return 0;
}

int main() {
    word_t words[MAX_WORDS];
    int num_words = load_words(words);

    if (num_words <= 0) {
        return -1;
    }

    char sentence[1000];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, sizeof(sentence), stdin);

    translate_sentence(sentence, words, num_words);

    return 0;
}