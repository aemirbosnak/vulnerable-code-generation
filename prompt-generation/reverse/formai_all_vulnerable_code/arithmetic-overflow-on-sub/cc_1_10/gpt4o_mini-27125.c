//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_SENTENCES 5
#define MAX_LENGTH 256

char *sentences[MAX_SENTENCES] = {
    "The quick brown fox jumps over the lazy dog.",
    "A journey of a thousand miles begins with a single step.",
    "To be, or not to be, that is the question.",
    "All that glitters is not gold.",
    "In the end, we will remember not the words of our enemies, but the silence of our friends."
};

int get_random_sentence_index() {
    return rand() % MAX_SENTENCES;
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

float calculate_wpm(int typed_words, double duration) {
    return (typed_words / duration) * 60; // Convert to words per minute
}

void display_results(int total_words, int correct_words, double time_taken) {
    float wpm = calculate_wpm(total_words, time_taken);
    float accuracy = ((float) correct_words / total_words) * 100;

    printf("\n\n--- Results ---\n");
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Words typed: %d\n", total_words);
    printf("Correct words: %d\n", correct_words);
    printf("Speed: %.2f WPM\n", wpm);
    printf("Accuracy: %.2f%%\n", accuracy);
}

int main() {
    srand(time(NULL));
    int sentence_index = get_random_sentence_index();
    char input[MAX_LENGTH];

    printf("Typing Speed Test\n");
    printf("Type the following sentence:\n\n");
    printf("\"%s\"\n\n", sentences[sentence_index]);

    printf("Press Enter to start...\n");
    clear_input_buffer();

    clock_t start_time = clock();
    fgets(input, MAX_LENGTH, stdin); // Read user input

    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Compare input with the sentence and calculate words and accuracy
    int total_words = 0;
    int correct_words = 0;
    char *token;

    // Tokenize the reference sentence
    char *reference = strtok(sentences[sentence_index], " ");
    while (reference != NULL) {
        total_words++;
        reference = strtok(NULL, " ");
    }

    // Tokenize the user's input
    token = strtok(input, " \n");
    while (token != NULL) {
        if (strcmp(token, sentences[sentence_index]) == 0) {
            correct_words++;
        }
        token = strtok(NULL, " \n");
    }

    // Display finalize results
    display_results(total_words, correct_words, time_taken);

    return 0;
}