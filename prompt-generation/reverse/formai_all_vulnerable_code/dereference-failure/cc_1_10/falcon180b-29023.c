//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

struct word {
    char word[MAX_WORD_LENGTH];
    int length;
};

void generate_word(struct word *word) {
    int i;
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        word->word[i] = 'a' + rand() % 26;
    }
    word->length = rand() % MAX_WORD_LENGTH + 1;
}

void print_word(struct word *word) {
    int i;
    for (i = 0; i < word->length; i++) {
        printf("%c", word->word[i]);
    }
    printf(" ");
}

int main() {
    int num_words, i;
    struct word *words = malloc(MAX_WORDS * sizeof(struct word));
    srand(time(NULL));

    printf("Enter the number of words to type: ");
    scanf("%d", &num_words);

    printf("Enter the words:\n");
    for (i = 0; i < num_words; i++) {
        generate_word(&words[i]);
        print_word(&words[i]);
    }

    printf("\nStart typing:\n");
    for (i = 0; i < num_words; i++) {
        printf("Word %d: ", i + 1);
        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, words[i].word) == 0) {
            printf("Correct!\n");
        } else {
            printf("Incorrect.\n");
        }
    }

    free(words);
    return 0;
}