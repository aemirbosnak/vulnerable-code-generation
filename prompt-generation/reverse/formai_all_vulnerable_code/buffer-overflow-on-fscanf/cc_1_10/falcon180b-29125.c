//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOCABULARY 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
} Vocabulary;

int load_vocabulary(Vocabulary *vocabulary) {
    FILE *fp = fopen("vocabulary.txt", "r");
    if (fp == NULL) {
        printf("Error loading vocabulary\n");
        return -1;
    }

    int count = 0;
    while (fscanf(fp, "%s %s\n", vocabulary[count].english, vocabulary[count].cat)!= EOF) {
        count++;
    }

    fclose(fp);
    return count;
}

int translate(Vocabulary *vocabulary, int vocabulary_size, char *sentence) {
    int word_count = 0;
    char word[MAX_WORD_LENGTH];
    char cat_word[MAX_WORD_LENGTH];

    strcpy(cat_word, "meow ");

    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int found = 0;
        for (int i = 0; i < vocabulary_size; i++) {
            if (strcmp(token, vocabulary[i].english) == 0) {
                strcpy(word, vocabulary[i].cat);
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(word, token);
        }

        printf("%s ", word);
        word_count++;

        if (word_count == 10) {
            printf("%s\n", cat_word);
            word_count = 0;
        }

        token = strtok(NULL, " ");
    }

    return 0;
}

int main() {
    Vocabulary vocabulary[MAX_VOCABULARY];
    int vocabulary_size = load_vocabulary(vocabulary);

    if (vocabulary_size <= 0) {
        return -1;
    }

    char sentence[100];
    printf("Enter a sentence to translate: ");
    fgets(sentence, 100, stdin);

    translate(vocabulary, vocabulary_size, sentence);

    return 0;
}