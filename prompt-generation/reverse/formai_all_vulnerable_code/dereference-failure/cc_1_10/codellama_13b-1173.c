//Code Llama-13B DATASET v1.0 Category: Text Summarizer ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_CHARS 1000

struct word_t {
    char* word;
    int count;
};

struct word_t* words[MAX_CHARS];
int num_words = 0;

void add_word(char* word) {
    struct word_t* new_word = malloc(sizeof(struct word_t));
    new_word->word = word;
    new_word->count = 1;
    words[num_words++] = new_word;
}

void summarize() {
    int i;
    for (i = 0; i < num_words; i++) {
        struct word_t* word = words[i];
        int count = word->count;
        if (count > 1) {
            printf("%s: %d\n", word->word, count);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [text]\n", argv[0]);
        return 1;
    }
    char* text = argv[1];
    int i;
    for (i = 0; i < strlen(text); i++) {
        char* word = malloc(sizeof(char) * 100);
        int j;
        for (j = 0; j < 100; j++) {
            word[j] = '\0';
        }
        int k = 0;
        while (text[i] != ' ' && text[i] != '\0') {
            word[k++] = text[i];
            i++;
        }
        add_word(word);
    }
    summarize();
    return 0;
}