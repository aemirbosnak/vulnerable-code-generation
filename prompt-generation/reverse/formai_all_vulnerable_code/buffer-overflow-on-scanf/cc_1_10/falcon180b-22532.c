//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

struct sentence {
    char sentence[100];
    int word_count;
    struct word words[MAX_WORD_LENGTH];
};

int is_word(char c) {
    if (isalpha(c)) {
        return 1;
    }
    return 0;
}

void add_word(struct sentence *sentence, char word[MAX_WORD_LENGTH]) {
    int i;
    for (i = 0; i < sentence->word_count; i++) {
        if (strcmp(word, sentence->words[i].word) == 0) {
            sentence->words[i].count++;
            return;
        }
    }
    strcpy(sentence->words[sentence->word_count].word, word);
    sentence->words[sentence->word_count].count = 1;
    sentence->word_count++;
}

void add_sentence(struct sentence *sentence, char sentence_str[100]) {
    int i, j;
    char word[MAX_WORD_LENGTH];
    for (i = 0, j = 0; sentence_str[i]!= '\0'; i++) {
        if (is_word(sentence_str[i])) {
            word[j++] = sentence_str[i];
        }
        if (j == MAX_WORD_LENGTH - 1) {
            add_word(sentence, word);
            j = 0;
        }
    }
    if (j > 0) {
        add_word(sentence, word);
    }
}

void print_sentence(struct sentence *sentence) {
    int i;
    for (i = 0; i < sentence->word_count; i++) {
        printf("%s %d\n", sentence->words[i].word, sentence->words[i].count);
    }
}

int main() {
    char sentence_str[100];
    struct sentence sentence;
    int i;

    for (i = 0; i < 10; i++) {
        printf("Enter sentence %d:\n", i + 1);
        scanf("%s", sentence_str);
        add_sentence(&sentence, sentence_str);
    }

    for (i = 0; i < 10; i++) {
        printf("Sentence %d:\n", i + 1);
        print_sentence(&sentence);
    }

    return 0;
}