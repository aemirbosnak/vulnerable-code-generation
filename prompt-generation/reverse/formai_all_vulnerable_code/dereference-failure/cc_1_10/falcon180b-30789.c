//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

struct word_t {
    char word[MAX_WORD_LEN];
    int len;
};

void init_words(struct word_t words[MAX_WORDS]) {
    char *words_list[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon", "mango", "nectarine", "orange", "pear", "quince", "raspberry", "strawberry", "tangerine", "watermelon", "xylophone", "yellow", "zebra"};
    int i, j;

    for (i = 0; i < MAX_WORDS; i++) {
        words[i].len = rand() % (MAX_WORD_LEN - 3) + 3;
        j = 0;
        while (j < words[i].len) {
            words[i].word[j] = words_list[i % 20][j % 20];
            j++;
        }
        words[i].word[words[i].len] = '\0';
    }
}

void print_word(struct word_t word) {
    int i;

    for (i = 0; i < word.len; i++) {
        printf("%c", word.word[i]);
    }
    printf("\n");
}

int main() {
    struct word_t words[MAX_WORDS];
    int i, j, correct = 0;
    char input[MAX_WORD_LEN];
    time_t start, end;

    srand(time(NULL));
    init_words(words);

    start = time(NULL);
    for (i = 0; i < MAX_WORDS; i++) {
        j = 0;
        while (j < words[i].len) {
            printf("*");
            j++;
        }
        printf("\n");
        fflush(stdout);
        if (scanf("%s", input)!= 1) {
            printf("Invalid input.\n");
            continue;
        }
        if (strcmp(input, words[i].word) == 0) {
            correct++;
        }
    }
    end = time(NULL);

    printf("You typed %d words correctly in %ld seconds.\n", correct, end - start);

    return 0;
}