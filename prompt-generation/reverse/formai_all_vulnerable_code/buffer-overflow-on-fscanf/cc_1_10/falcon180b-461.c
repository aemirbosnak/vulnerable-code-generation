//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORD_LIST_SIZE 100
#define WORD_LENGTH_MAX 20

struct word_list {
    char word[WORD_LENGTH_MAX];
    int length;
};

void generate_word_list(struct word_list *word_list) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s", word_list[count].word)!= EOF && count < WORD_LIST_SIZE) {
        word_list[count].length = strlen(word_list[count].word);
        count++;
    }

    fclose(file);
}

int main() {
    struct word_list word_list[WORD_LIST_SIZE];
    generate_word_list(word_list);

    int correct_words = 0;
    int total_words = 0;
    int total_chars = 0;
    int correct_chars = 0;

    time_t start_time = time(NULL);

    printf("Type the following words:\n");

    for (int i = 0; i < WORD_LIST_SIZE; i++) {
        printf("%s\n", word_list[i].word);
    }

    char input[WORD_LENGTH_MAX];
    while (fgets(input, WORD_LENGTH_MAX, stdin)!= NULL) {
        total_words++;
        total_chars += strlen(input);

        int correct = 1;
        for (int i = 0; i < WORD_LIST_SIZE; i++) {
            if (strcmp(word_list[i].word, input) == 0) {
                correct_words++;
                correct_chars += word_list[i].length;
                break;
            }
        }
    }

    double elapsed_time = difftime(time(NULL), start_time);
    double words_per_minute = (double)total_words / (elapsed_time / 60);
    double characters_per_minute = (double)correct_chars / (elapsed_time / 60);

    printf("You typed %d words with %d correct.\n", total_words, correct_words);
    printf("You typed %d characters with %d correct.\n", total_chars, correct_chars);
    printf("Your typing speed is %.2f words per minute.\n", words_per_minute);
    printf("Your typing speed is %.2f characters per minute.\n", characters_per_minute);

    return 0;
}