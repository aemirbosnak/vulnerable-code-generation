//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    char translation[MAX_WORD_LEN];
} word_pair;

void load_words(word_pair words[]) {
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: cannot open words file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %s\n", words[i].word, words[i].translation) == 2) {
        i++;
        if (i >= MAX_WORDS) {
            printf("Error: too many words in file.\n");
            exit(1);
        }
    }

    fclose(fp);
}

void translate_sentence(word_pair words[], char sentence[]) {
    char *p = strtok(sentence, " ");
    while (p!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(p, words[i].word) == 0) {
                printf("%s ", words[i].translation);
                break;
            }
        }
        if (i == MAX_WORDS) {
            printf("%s ", p);
        }
        p = strtok(NULL, " ");
    }
    printf("\n");
}

int main() {
    char sentence[1000];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, sizeof(sentence), stdin);

    word_pair words[MAX_WORDS];
    load_words(words);

    translate_sentence(words, sentence);

    return 0;
}