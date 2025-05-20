//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 30

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
    int correct;
} Word;

void generate_words(Word words[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        int length = rand() % MAX_WORD_LENGTH + 1;
        words[i].length = length;
        for (int j = 0; j < length; j++) {
            char c = 'a' + rand() % 26;
            words[i].word[j] = c;
        }
        words[i].word[length] = '\0';
    }
}

void print_words(Word words[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i].word);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int num_words;
    printf("Enter number of words: ");
    scanf("%d", &num_words);

    Word words[MAX_WORDS];
    generate_words(words, num_words);

    int correct = 0;
    for (int i = 0; i < num_words; i++) {
        printf("Word %d: ", i+1);
        char input[MAX_WORD_LENGTH];
        scanf("%s", input);

        int length = strlen(input);
        if (length == words[i].length && strcmp(input, words[i].word) == 0) {
            correct++;
        }
    }

    printf("Correct: %d/%d\n", correct, num_words);

    return 0;
}