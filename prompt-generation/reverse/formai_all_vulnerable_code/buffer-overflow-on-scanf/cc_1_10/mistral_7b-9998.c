//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define WORD_LENGTH 40
#define WORDS_PER_LINE 10

typedef struct Word {
    char text[WORD_LENGTH];
    struct Word *next;
} Word;

Word *words[MAX_WORDS];
Word *current_word = NULL;

void generate_words(int num_words) {
    Word *word, *temp;
    int i;

    for (i = 0; i < num_words; i++) {
        word = (Word *)malloc(sizeof(Word));
        word->next = NULL;

        snprintf(word->text, WORD_LENGTH, "%.*s%c", WORD_LENGTH - 1, "Ephemeral typist's", (i % 5 == 0 ? ' ' : '_') + 64);

        if (i == 0) {
            current_word = word;
            words[0] = word;
        } else {
            temp = words[rand() % MAX_WORDS];
            word->next = temp;
            words[rand() % MAX_WORDS] = word;
        }
    }
}

void print_line(int num_words) {
    Word *word;
    int i;

    for (i = 0; i < num_words; i++) {
        word = current_word;
        current_word = current_word->next;
        printf("%s%s", word->text, i < num_words - 1 ? "\t|\t" : "\n");
    }
}

int main() {
    int num_words, attempts, elapsed_time;
    clock_t start, end;

    srand(time(NULL));

    printf("Ephemeral Typing Speed Test\n");
    printf("-----------------------------\n");
    printf("Enter the number of words to type: ");
    scanf("%d", &num_words);

    generate_words(num_words);

    start = clock();

    for (attempts = 0; attempts < num_words; attempts++) {
        print_line(WORDS_PER_LINE);
        fflush(stdout);

        while (current_word != NULL) {
            getchar();
            current_word = current_word->next;
        }

        print_line(WORDS_PER_LINE);
        fflush(stdout);
    }

    end = clock();
    elapsed_time = (end - start) * 1000 / CLOCKS_PER_SEC;

    printf("Typing %d words in %d ms\n", num_words, elapsed_time);

    return 0;
}