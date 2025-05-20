//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_LENGTH 1000  // maximum length of the sentence
#define NUM_OF_WORDS 20  // number of words to type

char *get_sentence();
void shuffle_array(int *arr, int size);
void print_sentence(char *sentence, int *word_idx, int idx, float wpm, float accuracy);
int calculate_wpm(float elapsed, int num_of_words);
float calculate_accuracy(char *sentence, char *typed, int num_of_words);

int main(void) {
    srand(time(NULL));
    char *sentence = get_sentence();
    int word_idx[NUM_OF_WORDS];
    for (int i = 0; i < NUM_OF_WORDS; i++) {
        word_idx[i] = i;
    }
    shuffle_array(word_idx, NUM_OF_WORDS);
    printf("Welcome to the typing speed test!\n\n");
    printf("Type the following sentence as fast and accurately as possible:\n\n");
    printf("\"%s\"\n\n", sentence);
    char typed[MAX_LENGTH];
    clock_t start_time = clock();
    fgets(typed, MAX_LENGTH, stdin);  // read a line of text from user
    clock_t end_time = clock();
    float elapsed_time = (float)(end_time - start_time) / CLOCKS_PER_SEC;  // in seconds
    printf("\n");
    int wpm = calculate_wpm(elapsed_time, NUM_OF_WORDS);
    float accuracy = calculate_accuracy(sentence, typed, NUM_OF_WORDS);
    print_sentence(sentence, word_idx, NUM_OF_WORDS, (float)wpm, accuracy);
    return 0;
}

char *get_sentence() {
    return "The quick brown fox jumps over the lazy dog";
}

void shuffle_array(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int j = i + rand() % (size - i);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void print_sentence(char *sentence, int *word_idx, int idx, float wpm, float accuracy) {
    printf("Here is your result:\n\n");
    printf("Words in sentence:\n");
    char *word = strtok(sentence, " ");
    int i = 0;
    while (word) {
        if (i == word_idx[idx]) {
            printf("\033[1;31m%s\033[0m ", word);  // highlight the word to type
            idx++;
        } else {
            printf("%s ", word);
        }
        word = strtok(NULL, " ");
        i++;
    }
    printf("\n\n");
    printf("Typing speed: %.0f words per minute\n", wpm);
    printf("Accuracy: %.1f%%\n", accuracy * 100);
}

int calculate_wpm(float elapsed, int num_of_words) {
    float minutes = elapsed / 60;
    return (int)(num_of_words / minutes);
}

float calculate_accuracy(char *sentence, char *typed, int num_of_words) {
    int typo_count = 0;  // number of characters that were mistyped
    int word_idx = 0;
    int is_word = 0;
    for (int i = 0; i < MAX_LENGTH; i++) {
        // check if a new word is being processed
        if (isspace(sentence[i])) {  
            is_word = 0;
            if (i + 1 < MAX_LENGTH && !isspace(sentence[i + 1])) {
                word_idx++;
            }
        } else {
            is_word = 1;
        }
        // check if a mistake was made
        if (typed[i] != sentence[i] && is_word) {
            typo_count++;
        }
        // check if all words have been typed
        if (word_idx == num_of_words) {
            break;
        }
    }
    return 1 - (float)typo_count / strlen(sentence);
}