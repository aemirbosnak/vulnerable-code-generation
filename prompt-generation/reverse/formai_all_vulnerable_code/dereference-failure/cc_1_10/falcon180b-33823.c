//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20
#define MIN_WORD_LEN 3

typedef struct {
    char *word;
    int count;
} Word;

void add_word(Word *words, int num_words, char *word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            return;
        }
    }
    if (num_words >= MAX_WORDS) {
        printf("Error: Maximum number of words reached.\n");
        exit(1);
    }
    words[num_words].word = strdup(word);
    words[num_words].count = 1;
    num_words++;
}

int is_spam(char *text) {
    int i;
    int num_words = 0;
    Word words[MAX_WORDS];
    memset(words, 0, sizeof(words));
    char *word = strtok(text, " ");
    while (word!= NULL) {
        if (strlen(word) >= MIN_WORD_LEN && strlen(word) <= MAX_WORD_LEN) {
            add_word(words, num_words, word);
        }
        word = strtok(NULL, " ");
    }
    regex_t regex;
    regcomp(&regex, "\\b(viagra|cialis|levitra|spam|scam|pharmacy|pills)\\b", REG_ICASE);
    for (i = 0; i < num_words; i++) {
        if (regexec(&regex, words[i].word, 0, NULL, 0) == 0) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }
    char *text = argv[1];
    if (is_spam(text)) {
        printf("Spam detected.\n");
    } else {
        printf("No spam detected.\n");
    }
    return 0;
}