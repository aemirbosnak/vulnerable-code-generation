//MISTRAL-7B DATASET v1.0 Category: Text Summarizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50
#define MIN_FREQ 5

typedef struct {
    char word[WORD_LENGTH];
    int freq;
} Word;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int isStopWord(char *word) {
    static char *stopWords[] = {"a", "an", "and", "are", "as", "at", "be", "but", "by", "for", "from", "how", "in", "is", "it", "its", "of", "on", "or", "such", "that", "the", "their", "then", "there", "these", "they", "this", "to", "was", "will", "with"};
    for (int i = 0; i < sizeof(stopWords) / sizeof(char*); i++) {
        if (!strcasecmp(word, stopWords[i])) {
            return 1;
        }
    }
    return 0;
}

void processText(char *text) {
    char word[WORD_LENGTH];
    int pos = 0, len;
    int wordsCount = 0;
    Word words[MAX_WORDS];

    toLowerCase(text);

    do {
        len = 0;
        while (isalnum(text[pos])) {
            word[len++] = text[pos++];
            if (len >= WORD_LENGTH - 1) {
                word[len] = '\0';
                if (wordsCount >= MAX_WORDS) {
                    printf("Error: too many words\n");
                    exit(1);
                }

                if (strlen(word) > 0 && isalpha(word[0])) {
                    int exists = 0;
                    for (int i = 0; i < wordsCount; i++) {
                        if (!strcasecmp(words[i].word, word)) {
                            words[i].freq++;
                            exists = 1;
                            break;
                        }
                    }

                    if (!exists) {
                        strcpy(words[wordsCount++].word, word);
                        words[wordsCount - 1].freq = 1;
                    }
                }

                len = 0;
                pos--;
                break;
            }
            word[len++] ++;
            word[len] = ' ';
        }
        pos++;
    } while (text[pos] != '\0');

    printf("Total words: %d\n", wordsCount);
    printf("Summary:\n");

    for (int i = 0; i < wordsCount; i++) {
        if (words[i].freq >= MIN_FREQ) {
            printf("%s: %d\n", words[i].word, words[i].freq);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        exit(1);
    }

    processText(argv[1]);
    return 0;
}