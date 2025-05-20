//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_STRING_LENGTH 200
#define NUM_TESTS 5

void print_instructions() {
    printf("\nWelcome to the C Typing Speed Test!\n");
    printf("You will be provided with a series of random sentences to type.\n");
    printf("Your typing speed will be measured in words per minute (WPM).\n\n");
    printf("Press Enter to start the test...\n");
    getchar(); // Wait for user to press Enter
}

void generate_random_sentence(char *sentence) {
    const char *samples[NUM_TESTS] = {
        "The quick brown fox jumps over the lazy dog.",
        "A journey of a thousand miles begins with a single step.",
        "To be or not to be, that is the question.",
        "All that glitters is not gold.",
        "In the end, we will remember not the words of our enemies, but the silence of our friends."
    };
  
    int index = rand() % NUM_TESTS; // Get a random index for the sentence
    strcpy(sentence, samples[index]);
}

int calculate_wpm(int num_words, double time_taken) {
    return (int)((num_words / time_taken) * 60); // Calculate WPM
}

int count_words(const char *str) {
    int count = 0;
    const char *p = str;

    while (*p) {
        while (*p == ' ' || *p == '\t' || *p == '\n') p++; // Skip spaces
        if (*p) {
            count++; // Found a word
            while (*p && *p != ' ' && *p != '\t' && *p != '\n') p++;
        }
    }
    return count; // Return total word count
}

void conduct_test() {
    char sentence[MAX_STRING_LENGTH];
    char user_input[MAX_STRING_LENGTH];
    
    generate_random_sentence(sentence); // Get random sentence
    printf("\nType the following sentence:\n");
    printf("\"%s\"\n", sentence);

    clock_t start_time = clock(); // Start timer
    fgets(user_input, sizeof(user_input), stdin); // Get user input
    clock_t end_time = clock(); // End timer

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC; // Time in seconds
    
    // Count words in user input and the sentence
    int num_words_original = count_words(sentence);
    int num_words_typed = count_words(user_input);

    int wpm = calculate_wpm(num_words_typed, time_taken); // Calculate WPM

    // Feedback
    printf("\nYour result:\n");
    printf("You typed %d words out of %d in %.2f seconds.\n", num_words_typed, num_words_original, time_taken);
    printf("Your typing speed is %d WPM.\n\n", wpm);
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    print_instructions(); // Print instructions for the user

    // Conduct multiple tests
    for (int i = 0; i < 3; i++) {
        printf("\nTest %d:\n", i + 1);
        conduct_test();
        printf("Press Enter to proceed to the next test...\n");
        getchar(); // Wait for user to press Enter
    }
    
    printf("Thank you for participating in the C Typing Speed Test!\n");
    return 0;
}