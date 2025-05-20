//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORDS 50
#define MAX_WORD_LENGTH 10

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void generate_random_word(Word *word);
int is_valid_word(char *word);
int compare_words(const void *a, const void *b);

int main() {
    srand(time(NULL));

    int num_words;
    printf("Enter the number of words: ");
    scanf("%d", &num_words);

    Word *words = malloc(num_words * sizeof(Word));

    for (int i = 0; i < num_words; i++) {
        generate_random_word(&words[i]);
    }

    qsort(words, num_words, sizeof(Word), compare_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s (%d)\n", words[i].word, words[i].length);
    }

    free(words);
    return 0;
}

void generate_random_word(Word *word) {
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    int length = rand() % 5 + 5;

    for (int i = 0; i < length; i++) {
        word->word[i] = letters[rand() % strlen(letters)];
    }

    word->length = length;
}

int is_valid_word(char *word) {
    for (int i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }

    return 1;
}

int compare_words(const void *a, const void *b) {
    Word *word1 = (Word *)a;
    Word *word2 = (Word *)b;

    if (word1->length > word2->length) {
        return -1;
    } else if (word1->length < word2->length) {
        return 1;
    } else {
        return 0;
    }
}