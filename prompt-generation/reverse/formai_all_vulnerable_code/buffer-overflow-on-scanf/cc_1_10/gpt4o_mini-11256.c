//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_SENTENCES 5
#define MAX_LENGTH 256

const char *sentences[MAX_SENTENCES] = {
    "The quick brown fox jumps over the lazy dog.",
    "A journey of a thousand miles begins with a single step.",
    "To be or not to be, that is the question.",
    "In the end, we will remember not the words of our enemies, but the silence of our friends.",
    "Write it on your heart that every day is the best day in the year."
};

void clear_buffer() {
    while (getchar() != '\n');
}

void calculate_performance(const char *original, const char *typed, double time_taken) {
    int correct = 0;
    int total_characters = strlen(original);
    
    // Calculate number of correct characters
    for (int i = 0; i < total_characters; i++) {
        if (original[i] == typed[i]) {
            correct++;
        }
    }

    // Calculate words per minute (WPM)
    int typed_word_count = 0;
    char *token = strtok(typed, " ");
    while (token != NULL) {
        typed_word_count++;
        token = strtok(NULL, " ");
    }

    double wpm = (typed_word_count / time_taken) * 60;
    double accuracy = ((double)correct / total_characters) * 100;

    printf("Typing Speed: %.2f WPM\n", wpm);
    printf("Accuracy: %.2f%%\n", accuracy);
}

void start_typing_test() {
    srand(time(NULL));
    int idx = rand() % MAX_SENTENCES;
    const char *original_sentence = sentences[idx];
    
    char typed_sentence[MAX_LENGTH];

    printf("Type the following sentence:\n");
    printf("\"%s\"\n", original_sentence);

    printf("Press Enter to start...\n");
    clear_buffer();

    time_t start_time = time(NULL);
    fgets(typed_sentence, sizeof(typed_sentence), stdin);
    time_t end_time = time(NULL);

    // Remove newline character if present
    size_t len = strlen(typed_sentence);
    if (len > 0 && typed_sentence[len - 1] == '\n') {
        typed_sentence[len - 1] = '\0';
    }

    double time_taken = difftime(end_time, start_time);
    calculate_performance(original_sentence, typed_sentence, time_taken);
}

int main() {
    char choice;

    do {
        start_typing_test();
        
        printf("\nDo you want to try again? (y/n): ");
        scanf(" %c", &choice);
        clear_buffer();

    } while (tolower(choice) == 'y');

    printf("Thank you for participating in the typing speed test!\n");
    return 0;
}