//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LEN 20

struct word_t {
    char word[MAX_WORD_LEN + 1];
    int freq;
};

int compare_words(const void *a, const void *b) {
    struct word_t *word_a = (struct word_t *) a;
    struct word_t *word_b = (struct word_t *) b;

    return strcmp(word_a->word, word_b->word);
}

int main() {
    FILE *file;
    char word[MAX_WORD_LEN + 1];
    struct word_t words[MAX_WORDS];
    int num_words = 0;
    int i, j;

    file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error opening dictionary file.\n");
        return 1;
    }

    while (fscanf(file, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Dictionary is full.\n");
            break;
        }

        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        words[num_words].word[0] = word[0];
        strncat(words[num_words].word, word + 1, strlen(word) - 1);
        words[num_words].word[MAX_WORD_LEN] = '\0';
        words[num_words].freq = 1;

        num_words++;
    }

    fclose(file);

    qsort(words, num_words, sizeof(struct word_t), compare_words);

    char input_word[MAX_WORD_LEN + 1];
    printf("Enter a word to spell check: ");
    scanf("%s", input_word);

    for (i = 0; i < num_words; i++) {
        if (strcmp(input_word, words[i].word) == 0) {
            printf("%s is spelled correctly.\n", input_word);
            return 0;
        }
    }

    printf("%s is spelled incorrectly.\n", input_word);

    return 0;
}