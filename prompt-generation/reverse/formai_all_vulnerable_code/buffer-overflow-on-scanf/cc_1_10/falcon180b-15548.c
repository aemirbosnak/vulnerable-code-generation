//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void generate_words(Word words[], int num_words) {
    const char *const words_list[] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog", "the", "cat", "sat", "on", "the", "mat", "the", "dog", "chased", "the", "cat", "the", "end"};

    for (int i = 0; i < num_words; i++) {
        int rand_index = rand() % (sizeof(words_list) / sizeof(words_list[0]));
        strcpy(words[i].word, words_list[rand_index]);
        words[i].length = strlen(words[i].word);
    }
}

void print_words(Word words[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s (%d)\n", words[i].word, words[i].length);
    }
}

int main(void) {
    srand(time(NULL));

    int num_words;
    printf("Enter the number of words to type (max %d): ", MAX_WORDS);
    scanf("%d", &num_words);

    Word words[MAX_WORDS];
    generate_words(words, num_words);

    printf("Words to type:\n");
    print_words(words, num_words);

    char input[MAX_WORD_LENGTH];
    int correct_words = 0;
    int total_words = 0;
    int num_mistakes = 0;

    printf("Start typing:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: ", words[i].word);
        fgets(input, MAX_WORD_LENGTH, stdin);
        total_words++;

        if (strcmp(input, words[i].word) == 0) {
            correct_words++;
        } else {
            num_mistakes++;
        }
    }

    printf("Results:\n");
    printf("Correct words: %d\n", correct_words);
    printf("Total words: %d\n", total_words);
    if (total_words > 0) {
        printf("Accuracy: %.2f%%\n", (100.0 * correct_words) / total_words);
    }

    return 0;
}