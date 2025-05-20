//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} word_count_t;

void print_word_counts(word_count_t *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

void count_words(char *text, word_count_t *word_counts, int num_words) {
    char *word = strtok(text, " ");
    while (word!= NULL) {
        int index = 0;
        while (index < num_words && strcmp(word, word_counts[index].word)!= 0) {
            index++;
        }
        if (index == num_words) {
            if (num_words < MAX_WORD_LENGTH) {
                strcpy(word_counts[num_words].word, word);
                num_words++;
            }
        } else {
            word_counts[index].count++;
        }
        word = strtok(NULL, " ");
    }
}

int main() {
    char text[1000];
    printf("Enter some text:\n");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    word_count_t word_counts[MAX_WORD_LENGTH];
    int num_words = 0;

    count_words(text, word_counts, num_words);

    print_word_counts(word_counts, num_words);

    return 0;
}