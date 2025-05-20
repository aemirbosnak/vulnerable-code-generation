//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char *text;
    int frequency;
};

struct word *generate_conspiracy_theory(int num_words, int max_word_length) {
    struct word *words = malloc(num_words * sizeof(struct word));
    if (words == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    for (int i = 0; i < num_words; i++) {
        char word_text[MAX_WORD_LENGTH];
        int word_length = rand() % max_word_length + 1;
        for (int j = 0; j < word_length; j++) {
            word_text[j] = rand() % 26 + 'a';
        }
        word_text[word_length] = '\0';

        words[i].text = strdup(word_text);
        words[i].frequency = rand() % 100;
    }

    return words;
}

void print_conspiracy_theory(struct word *words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s (%d)\n", words[i].text, words[i].frequency);
    }
}

int main() {
    srand(time(NULL));

    int num_words;
    printf("Enter the number of words in the conspiracy theory: ");
    scanf("%d", &num_words);

    int max_word_length;
    printf("Enter the maximum length of each word: ");
    scanf("%d", &max_word_length);

    struct word *words = generate_conspiracy_theory(num_words, max_word_length);
    print_conspiracy_theory(words, num_words);

    for (int i = 0; i < num_words; i++) {
        free(words[i].text);
    }
    free(words);

    return 0;
}