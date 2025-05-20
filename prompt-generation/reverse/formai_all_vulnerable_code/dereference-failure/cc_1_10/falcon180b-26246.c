//Falcon-180B DATASET v1.0 Category: Text processing ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void process_text(char* text) {
    int i, j, k;
    char word[MAX_WORD_LEN];
    WordCount words[MAX_WORDS];
    int num_words = 0;

    for (i = 0; i < strlen(text); i++) {
        if (isspace(text[i])) {
            word[k] = '\0';
            for (j = 0; j < k; j++) {
                text[i - k + j] = tolower(text[i - k + j]);
            }
            if (k > 0 && num_words < MAX_WORDS) {
                strcpy(words[num_words].word, word);
                words[num_words].count = 1;
                num_words++;
            }
            k = 0;
        } else {
            word[k++] = text[i];
        }
    }

    if (k > 0 && num_words < MAX_WORDS) {
        strcpy(words[num_words].word, word);
        words[num_words].count = 1;
        num_words++;
    }

    printf("Total number of words: %d\n", num_words);
    printf("Top 10 most frequent words:\n");
    for (i = 0; i < num_words && i < 10; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char text[1000];

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    process_text(text);

    return 0;
}