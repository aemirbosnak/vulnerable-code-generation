//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CONSPIRACY_LENGTH 1024
#define MAX_CONSPIRACY_WORDS 50
#define MAX_WORD_LENGTH 20

typedef struct {
    char *word;
    int length;
} ConspiracyWord;

ConspiracyWord *generate_conspiracy_words(int num_words);
void print_conspiracy(ConspiracyWord *words, int num_words);

int main(void) {
    int num_words;

    printf("Enter the number of words in the conspiracy theory: ");
    scanf("%d", &num_words);

    ConspiracyWord *words = generate_conspiracy_words(num_words);
    print_conspiracy(words, num_words);

    free(words);

    return 0;
}

ConspiracyWord *generate_conspiracy_words(int num_words) {
    ConspiracyWord *words = malloc(num_words * sizeof(ConspiracyWord));

    srand(time(NULL));

    for (int i = 0; i < num_words; i++) {
        char *word = malloc(MAX_WORD_LENGTH * sizeof(char));
        strcpy(word, "");

        int length = rand() % MAX_WORD_LENGTH + 1;
        for (int j = 0; j < length; j++) {
            char c = rand() % 26 + 'a';
            strcat(word, &c);
        }

        words[i].word = word;
        words[i].length = length;
    }

    return words;
}

void print_conspiracy(ConspiracyWord *words, int num_words) {
    printf("The %d-word conspiracy theory:\n", num_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i].word);
    }

    printf("\n");
}