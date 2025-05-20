//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define TEXT_LENGTH 100
#define MAX_TRIALS 5

const char *sample_texts[MAX_TRIALS] = {
    "The quick brown fox jumps over the lazy dog.",
    "A journey of a thousand miles begins with a single step.",
    "To be or not to be, that is the question.",
    "All that glitters is not gold.",
    "In the end, we will remember not the words of our enemies, but the silence of our friends."
};

void display_welcome_message() {
    printf("====================================\n");
    printf("        Typing Speed Test           \n");
    printf("====================================\n");
}

void display_instructions() {
    printf("Instructions:\n");
    printf("1. A sample text will be displayed.\n");
    printf("2. Type the text as quickly and accurately as possible.\n");
    printf("3. Press 'Enter' when you're done.\n");
}

void generate_statistics(int times[], int number_of_trials) {
    int total_time = 0;
    int min_time = times[0];
    int max_time = times[0];
    
    for (int i = 0; i < number_of_trials; i++) {
        total_time += times[i];
        if (times[i] < min_time) {
            min_time = times[i];
        }
        if (times[i] > max_time) {
            max_time = times[i];
        }
    }

    double average_time = (double)total_time / number_of_trials;
    
    printf("\n===== Results =====\n");
    printf("Total Trials: %d\n", number_of_trials);
    printf("Average Time: %.2f seconds\n", average_time / 1000);
    printf("Minimum Time: %d milliseconds\n", min_time);
    printf("Maximum Time: %d milliseconds\n", max_time);
    printf("===================\n");
}

int main() {
    display_welcome_message();
    display_instructions();

    char input_text[TEXT_LENGTH];
    int times[MAX_TRIALS];

    for (int i = 0; i < MAX_TRIALS; i++) {
        printf("\nTrial %d:\n", i + 1);
        printf("Type the following text:\n");
        printf("\"%s\"\n", sample_texts[i]);
        
        clock_t start_time = clock();
        
        fgets(input_text, TEXT_LENGTH, stdin);
        
        clock_t end_time = clock();
        times[i] = (int)(end_time - start_time);

        // Clean the input to compare
        for (int j = 0; j < TEXT_LENGTH; j++) {
            input_text[j] = tolower(input_text[j]); // Convert to lower case
        }

        // Check if input matches the sample text
        if (strcmp(input_text, sample_texts[i]) == 0) {
            printf("Correct! Time taken: %d milliseconds\n", times[i]);
        } else {
            printf("Incorrect! Time taken: %d milliseconds\n", times[i]);
        }
    }

    generate_statistics(times, MAX_TRIALS);
    
    return 0;
}