//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 10

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void generate_words(Word words[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        char ch;
        int length = rand() % MAX_WORD_LENGTH + 1;
        words[i].length = length;
        for (int j = 0; j < length; j++) {
            ch = rand() % 26 + 'a';
            words[i].word[j] = ch;
        }
        words[i].word[length] = '\0';
    }
}

int main() {
    Word words[MAX_WORDS];
    int num_words;

    printf("Enter the number of words to type: ");
    scanf("%d", &num_words);

    generate_words(words, num_words);

    clock_t start_time, end_time;
    double cpu_time_used;

    start_time = clock();

    for (int i = 0; i < num_words; i++) {
        printf("%s\n", words[i].word);
        fflush(stdout);

        char input[MAX_WORD_LENGTH];
        scanf("%s", input);

        if (strcmp(input, words[i].word)!= 0) {
            printf("Incorrect word.\n");
        }
    }

    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Your typing speed is %.2f words per minute.\n", num_words / cpu_time_used);

    return 0;
}