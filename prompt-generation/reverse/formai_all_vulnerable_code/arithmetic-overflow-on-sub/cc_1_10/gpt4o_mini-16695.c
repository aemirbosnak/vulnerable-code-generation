//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 256

void display_instructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a sentence to type.\n");
    printf("Type it exactly as shown and press Enter to submit your input.\n");
    printf("Let's see how fast you can type!\n");
}

void get_current_time(struct timespec *start_time) {
    clock_gettime(CLOCK_MONOTONIC, start_time);
}

double calculate_time_elapsed(struct timespec start_time) {
    struct timespec end_time;
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    return (end_time.tv_sec - start_time.tv_sec) + 
           (end_time.tv_nsec - start_time.tv_nsec) / 1e9;
}

void typing_speed_test(const char *sentence) {
    char input[MAX_LEN];
    struct timespec start_time;
    
    printf("\nHere is your sentence:\n");
    printf("\"%s\"\n", sentence);
    printf("Start typing now...\n");

    get_current_time(&start_time);
    fgets(input, sizeof(input), stdin);
    
    // Remove trailing newline character from input
    input[strcspn(input, "\n")] = 0;

    double elapsed_time = calculate_time_elapsed(start_time);
    
    if(strcmp(input, sentence) == 0) {
        printf("Well done! Your input matches perfectly.\n");
    } else {
        printf("Your input did not match. Please try again!\n");
    }

    // Calculate typing speed in words per minute (WPM)
    int word_count = 0;
    char *token = strtok(input, " ");
    while (token) {
        word_count++;
        token = strtok(NULL, " ");
    }

    double wpm = (word_count / elapsed_time) * 60;
    printf("Time taken: %.2f seconds\n", elapsed_time);
    printf("Your typing speed: %.2f WPM\n", wpm);
}

int main() {
    const char *sentence = "The quick brown fox jumps over the lazy dog.";
    
    display_instructions();
    typing_speed_test(sentence);
    
    return 0;
}