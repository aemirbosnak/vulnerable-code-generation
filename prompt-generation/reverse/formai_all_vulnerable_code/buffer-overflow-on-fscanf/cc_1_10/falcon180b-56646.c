//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 50
#define MAX_SENTENCE_LENGTH 200

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int count;
} Word;

typedef struct {
    char sentence[MAX_SENTENCE_LENGTH + 1];
    int length;
    Word words[MAX_WORDS];
} Sentence;

void read_words(FILE *fp, Word words[]) {
    char word[MAX_WORD_LENGTH + 1];
    int count = 0;
    while (fscanf(fp, "%s", word)!= EOF) {
        if (count >= MAX_WORDS) {
            printf("Error: too many words\n");
            exit(1);
        }
        strcpy(words[count].word, word);
        words[count].count = 0;
        count++;
    }
}

void read_sentences(FILE *fp, Sentence sentence) {
    char ch;
    int i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (i >= MAX_SENTENCE_LENGTH) {
            printf("Error: sentence too long\n");
            exit(1);
        }
        if (isspace(ch)) {
            sentence.sentence[i] = '\0';
            i = 0;
        } else {
            sentence.sentence[i++] = ch;
        }
    }
    if (i > 0) {
        sentence.sentence[i] = '\0';
    }
    sentence.length = i;
}

void translate_sentence(Sentence sentence) {
    int i, j;
    for (i = 0; i < sentence.length; i++) {
        if (isalpha(sentence.sentence[i])) {
            for (j = 0; j < MAX_WORDS; j++) {
                if (strcmp(sentence.words[j].word, "") == 0) {
                    break;
                }
                if (tolower(sentence.sentence[i]) == tolower(sentence.words[j].word[0])) {
                    strcat(sentence.sentence, &sentence.words[j].word[1]);
                    sentence.words[j].count++;
                    break;
                }
            }
        } else {
            strcat(sentence.sentence, &sentence.sentence[i]);
        }
    }
}

int main() {
    FILE *fp;
    Word words[MAX_WORDS];
    Sentence sentence;
    time_t now = time(NULL);
    srand(now);
    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: cannot open words file\n");
        exit(1);
    }
    read_words(fp, words);
    fclose(fp);
    fp = fopen("sentence.txt", "r");
    if (fp == NULL) {
        printf("Error: cannot open sentence file\n");
        exit(1);
    }
    read_sentences(fp, sentence);
    fclose(fp);
    translate_sentence(sentence);
    printf("Translated sentence: %s\n", sentence.sentence);
    return 0;
}