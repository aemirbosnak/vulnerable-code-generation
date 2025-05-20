//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_SENTENCES 5
#define MAX_LENGTH 256

// Sample sentences to choose from
const char *sentences[MAX_SENTENCES] = {
    "The quick brown fox jumps over the lazy dog.",
    "A journey of a thousand miles begins with a single step.",
    "To be or not to be, that is the question.",
    "All that glitters is not gold.",
    "In the end, we will remember not the words of our enemies, but the silence of our friends."
};

// Function to clear the input buffer
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to get a random sentence
const char *get_random_sentence() {
    return sentences[rand() % MAX_SENTENCES];
}

// Function to calculate typing speed
double calculate_wpm(int word_count, double time_taken) {
    return (word_count / time_taken) * 60; // converting to WPM
}

// Function to count words
int count_words(const char *input) {
    int count = 0;
    char *token = strtok((char *)input, " ");
    while (token != NULL) {
        if (strlen(token) > 0) {
            count++;
        }
        token = strtok(NULL, " ");
    }
    return count;
}

int main() {
    char user_input[MAX_LENGTH];
    int word_count;
    double time_taken;
    clock_t start, end;

    // Seeding the random number generator
    srand(time(NULL));
    
    // Display instructions
    printf("Typing Speed Test\n");
    printf("==================\n");
    printf("You will be given a sentence to type.\n");
    printf("Type the sentence as quickly and accurately as possible.\n");

    // Get a random sentence
    const char *sentence_to_type = get_random_sentence();
    printf("\nYour sentence:\n\"%s\"\n", sentence_to_type);
    printf("\nPress Enter to start typing...\n");
    clear_input_buffer(); // Clear input before starting

    // Start the timer
    start = clock();
    
    // Get user input
    printf("\nStart typing: ");
    fgets(user_input, sizeof(user_input), stdin);
    
    // Stop the timer
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC; // time in seconds

    // Count the words in user input and actual sentence
    word_count = count_words(user_input);
    int original_word_count = count_words(sentence_to_type);

    // Calculate words per minute
    double wpm = calculate_wpm(word_count, time_taken);
    
    // Output results
    printf("\nResults:\n");
    printf("You typed %d words in %.2f seconds.\n", word_count, time_taken);
    printf("Your typing speed: %.2f WPM\n", wpm);
    
    if (strcmp(user_input, sentence_to_type) == 0) {
        printf("Congratulations! You typed the sentence correctly.\n");
    } else {
        printf("Your input did not match the original sentence.\n");
        printf("Original: \"%s\"\n", sentence_to_type);
        printf("Your: \"%s\"\n", user_input);
    }

    return 0;
}