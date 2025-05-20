//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define MAX_SENTENCE_LENGTH 200

struct word {
    char *english;
    char *alien;
};

struct sentence {
    int num_words;
    struct word *words;
};

void load_words(struct word *words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    int num_words = 0;
    while (fscanf(file, "%s %s\n", words[num_words].english, words[num_words].alien)!= EOF) {
        num_words++;
    }

    fclose(file);
}

int main() {
    struct word words[MAX_WORDS];
    load_words(words);

    char input_sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence to translate:\n");
    fgets(input_sentence, MAX_SENTENCE_LENGTH, stdin);

    int num_words = 0;
    char *token = strtok(input_sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].alien);
                break;
            }
        }

        if (i == num_words) {
            printf("Unknown word: %s\n", token);
        }

        num_words++;
        token = strtok(NULL, " ");
    }

    printf("\n");
    return 0;
}