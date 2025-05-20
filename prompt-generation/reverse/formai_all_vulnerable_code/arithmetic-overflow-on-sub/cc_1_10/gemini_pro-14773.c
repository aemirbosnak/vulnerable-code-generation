//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

char *words[] = {
    "the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog", "and",
    "the", "slow", "turtle", "races", "alongside", "the", "fast", "hare", "and",
    "the", "small", "mouse", "scurries", "under", "the", "large", "elephant", "and",
    "the", "tall", "giraffe", "stretches", "above", "the", "short", "frog", "and",
    "the", "wide", "river", "flows", "beside", "the", "narrow", "stream", "and"
};

void print_instructions() {
    printf("Instructions:\n");
    printf("1. You will be given a list of words to type.\n");
    printf("2. Type each word as quickly and accurately as possible.\n");
    printf("3. Your typing speed and accuracy will be calculated.\n");
    printf("\n");
}

void print_words(int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

int get_input(char *input, int max_length) {
    int length = 0;
    char c;
    while ((c = getchar()) != EOF && c != '\n') {
        if (length < max_length) {
            input[length++] = c;
        }
    }
    input[length] = '\0';
    return length;
}

int calculate_speed(int num_words, int time_taken) {
    return (num_words * 60) / time_taken;
}

int calculate_accuracy(int num_words, int num_correct) {
    return (num_correct * 100) / num_words;
}

void print_results(int speed, int accuracy) {
    printf("Your typing speed is %d words per minute.\n", speed);
    printf("Your typing accuracy is %d%%.\n", accuracy);
}

int main() {
    int num_words = 10;
    int num_correct = 0;
    int time_taken;

    print_instructions();

    printf("Number of words: %d\n", num_words);

    time_t start_time = time(NULL);

    print_words(num_words);

    char input[MAX_WORD_LENGTH];
    for (int i = 0; i < num_words; i++) {
        int length = get_input(input, MAX_WORD_LENGTH);
        if (strcmp(input, words[i]) == 0) {
            num_correct++;
        }
    }

    time_t end_time = time(NULL);

    time_taken = end_time - start_time;

    int speed = calculate_speed(num_words, time_taken);
    int accuracy = calculate_accuracy(num_words, num_correct);

    print_results(speed, accuracy);

    return 0;
}