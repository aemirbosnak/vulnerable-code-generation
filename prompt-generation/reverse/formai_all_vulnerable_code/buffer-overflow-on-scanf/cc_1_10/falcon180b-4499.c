//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 10

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

Word words[MAX_WORDS];
int num_words;

void generate_words(int num_words) {
    srand(time(NULL));

    for (int i = 0; i < num_words; i++) {
        char word[MAX_WORD_LENGTH];
        int length = rand() % MAX_WORD_LENGTH + 1;

        for (int j = 0; j < length; j++) {
            word[j] = rand() % 26 + 'a';
        }

        strcpy(words[i].word, word);
        words[i].length = length;
    }
}

void print_words() {
    for (int i = 0; i < num_words; i++) {
        printf("%s (%d)\n", words[i].word, words[i].length);
    }
}

void run_test(int num_words) {
    int total_time = 0;

    for (int i = 0; i < num_words; i++) {
        char input_word[MAX_WORD_LENGTH];
        printf("Type the word '%s' in 10 seconds:\n", words[i].word);

        time_t start_time = time(NULL);
        fgets(input_word, MAX_WORD_LENGTH, stdin);

        time_t end_time = time(NULL);
        total_time += difftime(end_time, start_time);
    }

    printf("Total time: %d seconds\n", total_time);
}

int main() {
    int num_words;

    printf("Enter the number of words for the test (1-1000):\n");
    scanf("%d", &num_words);

    if (num_words < 1 || num_words > MAX_WORDS) {
        printf("Invalid number of words.\n");
        return 1;
    }

    generate_words(num_words);
    print_words();
    run_test(num_words);

    return 0;
}