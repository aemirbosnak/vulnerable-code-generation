//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50

typedef struct {
    char *english;
    char *alien;
} word_pair;

void load_words(word_pair words[], int num_words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s %s\n", words[i].english, words[i].alien) == 2) {
        i++;
        if (i >= num_words) {
            printf("Too many words in file\n");
            exit(1);
        }
    }

    fclose(file);
}

void translate_sentence(char *sentence, word_pair words[], int num_words) {
    int i = 0;
    while (i < strlen(sentence)) {
        char word[MAX_WORD_LENGTH];
        memset(word, 0, MAX_WORD_LENGTH);

        while (isalpha(sentence[i]) && i < strlen(sentence)) {
            strncat(word, &sentence[i], 1);
            i++;
        }

        int word_index = -1;
        for (int j = 0; j < num_words; j++) {
            if (strcmp(word, words[j].english) == 0) {
                word_index = j;
                break;
            }
        }

        if (word_index == -1) {
            printf("%s not found in dictionary\n", word);
        } else {
            printf("%s ", words[word_index].alien);
        }

        i += strlen(word) - 1;
    }

    printf("\n");
}

int main() {
    word_pair words[100];
    load_words(words, 100);

    char sentence[1000];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, 1000, stdin);

    translate_sentence(sentence, words, 100);

    return 0;
}