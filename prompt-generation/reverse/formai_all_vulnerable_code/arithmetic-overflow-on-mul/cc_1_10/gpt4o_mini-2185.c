//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void display_instructions() {
    printf("========================================\n");
    printf("          Typing Speed Test              \n");
    printf("========================================\n");
    printf("Type the following sentence as fast as you can:\n");
}

char* get_random_sentence(){
    char* sentences[] = {
        "The quick brown fox jumps over the lazy dog.",
        "Pack my box with five dozen liquor jugs.",
        "How razorback-jumping frogs can level six piqued gymnasts!",
        "Bright vixens jump; dozy fowl quack.",
        "Sphinx of black quartz, judge my vow."
    };
    int n = sizeof(sentences) / sizeof(sentences[0]);
    return sentences[rand() % n];
}

int calculate_time_diff(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;
}

void get_user_input(char* input, int max_length) {
    fgets(input, max_length, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character
}

int main() {
    srand(time(NULL)); // Seed random number generator
    char user_input[256];
    char* random_sentence;
    struct timespec start_time, end_time;

    display_instructions();
    random_sentence = get_random_sentence();
    printf(">> %s <<\n\n", random_sentence);

    printf("Press Enter to start...\n");
    getchar();

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    get_user_input(user_input, sizeof(user_input));
    
    clock_gettime(CLOCK_MONOTONIC, &end_time);

    int time_taken = calculate_time_diff(start_time, end_time);
    
    // Results
    printf("\nYou typed: %s\n", user_input);
    
    if (strcmp(user_input, random_sentence) == 0) {
        printf("Perfect! \n");
    } else {
        printf("Mismatch! Try again.\n");
    }

    int words = 0;
    char* token = strtok(user_input, " ");
    while (token != NULL) {
        words++;
        token = strtok(NULL, " ");
    }

    double speed = (words / (time_taken / 1000.0)) * 60; // words per minute
    printf("Time taken: %d ms\n", time_taken);
    printf("Typing speed: %.2f words per minute\n", speed);

    return 0;
}