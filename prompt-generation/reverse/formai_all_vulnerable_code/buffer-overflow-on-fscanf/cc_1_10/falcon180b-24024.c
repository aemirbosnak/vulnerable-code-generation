//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN+1];
    int count;
} WordCount;

void ReadWords(FILE *fp, WordCount words[]) {
    char word[MAX_WORD_LEN+1];
    int i = 0;
    while (fscanf(fp, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words.\n");
            exit(1);
        }
        strcpy(words[i].word, word);
        words[i].count = 1;
        i++;
    }
}

void TranslateWords(WordCount words[], int num_words) {
    char vowels[] = "aeiouAEIOU";
    for (int i = 0; i < num_words; i++) {
        char *word = words[i].word;
        int len = strlen(word);
        for (int j = 0; j < len; j++) {
            if (isalpha(word[j])) {
                char c = tolower(word[j]);
                if (strchr(vowels, c)!= NULL) {
                    word[j] = 'z';
                } else {
                    word[j] = 'k';
                }
            }
        }
        printf("%s -> %s\n", words[i].word, word);
    }
}

int main() {
    FILE *fp;
    WordCount words[MAX_WORDS];
    int num_words;

    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open input file.\n");
        exit(1);
    }

    num_words = 0;
    ReadWords(fp, words);
    num_words = fclose(fp);

    TranslateWords(words, num_words);

    return 0;
}