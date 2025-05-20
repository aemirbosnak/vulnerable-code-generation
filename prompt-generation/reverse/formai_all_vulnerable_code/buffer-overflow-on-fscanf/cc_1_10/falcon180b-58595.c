//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: modular
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

void load_words(Word words[]);
int get_random_word(Word words[]);
void display_word(Word word);
int check_input(char input[], char correct_word[]);

int main() {
    srand(time(NULL));
    Word words[MAX_WORDS];
    load_words(words);

    int num_words = 10;
    int num_correct = 0;
    int num_incorrect = 0;

    for (int i = 0; i < num_words; i++) {
        int word_index = get_random_word(words);
        char correct_word[MAX_WORD_LENGTH];
        strcpy(correct_word, words[word_index].word);
        char input[MAX_WORD_LENGTH];
        printf("Type the word: ");
        scanf("%s", input);
        if (check_input(input, correct_word)) {
            num_correct++;
        } else {
            num_incorrect++;
        }
    }

    printf("You typed %d words correctly and %d words incorrectly.\n", num_correct, num_incorrect);

    return 0;
}

void load_words(Word words[]) {
    char word_file[] = "words.txt";
    FILE *fp = fopen(word_file, "r");
    if (fp == NULL) {
        printf("Error: could not open word file.\n");
        exit(1);
    }

    int num_words = 0;
    while (fscanf(fp, "%s", words[num_words].word)!= EOF) {
        words[num_words].length = strlen(words[num_words].word);
        num_words++;
        if (num_words >= MAX_WORDS) {
            break;
        }
    }

    fclose(fp);
}

int get_random_word(Word words[]) {
    return rand() % MAX_WORDS;
}

void display_word(Word word) {
    printf("%s ", word.word);
}

int check_input(char input[], char correct_word[]) {
    int input_length = strlen(input);
    int correct_length = strlen(correct_word);

    if (input_length!= correct_length) {
        return 0;
    }

    for (int i = 0; i < input_length; i++) {
        if (input[i]!= correct_word[i]) {
            return 0;
        }
    }

    return 1;
}