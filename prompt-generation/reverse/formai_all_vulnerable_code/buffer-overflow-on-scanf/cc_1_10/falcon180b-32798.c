//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: medieval
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_words(struct word *words, int count) {
    char word[MAX_WORD_LENGTH];
    printf("Enter %d words:\n", count);
    for (int i = 0; i < count; i++) {
        scanf("%s", word);
        strcpy(words[i].word, word);
        words[i].count = 0;
    }
}

void count_words(struct word *words, int count, char *text) {
    char *token = strtok(text, ",.?!;:");
    while (token!= NULL) {
        int i = 0;
        while (i < count && strcasecmp(token, words[i].word)!= 0) {
            i++;
        }
        if (i < count) {
            words[i].count++;
        }
        token = strtok(NULL, ",.?!;:");
    }
}

void print_misspelled_words(struct word *words, int count) {
    printf("Misspelled words:\n");
    for (int i = 0; i < count; i++) {
        if (words[i].count == 0) {
            printf("%s\n", words[i].word);
        }
    }
}

int main() {
    struct word words[MAX_WORDS];
    int count;

    printf("Enter the number of words to check: ");
    scanf("%d", &count);

    read_words(words, count);

    char text[1000];
    printf("Enter the text to check: ");
    scanf("%s", text);

    count_words(words, count, text);

    print_misspelled_words(words, count);

    return 0;
}