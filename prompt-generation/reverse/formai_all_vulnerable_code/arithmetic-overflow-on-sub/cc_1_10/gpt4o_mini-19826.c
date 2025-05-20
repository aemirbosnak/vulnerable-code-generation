//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSAGES 5
#define MAX_LENGTH 256

const char *passages[MAX_PASSAGES] = {
    "The quick brown fox jumps over the lazy dog.",
    "To be or not to be, that is the question.",
    "All that glitters is not gold.",
    "In the middle of difficulty lies opportunity.",
    "The only thing we have to fear is fear itself."
};

void display_passage(const char *passage) {
    printf("\nType the following passage:\n");
    printf("\"%s\"\n", passage);
}

double calculate_time_taken(clock_t start_time, clock_t end_time) {
    return ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
}

void get_user_input(char *user_input) {
    printf("Your input: ");
    fgets(user_input, MAX_LENGTH, stdin);
    user_input[strcspn(user_input, "\n")] = 0; // Remove newline character
}

int calculate_typing_speed(char *user_input, double time_taken) {
    int length = strlen(user_input);
    return (length / time_taken) * 60; // words per minute
}

void display_results(const char *passage, const char *user_input, double time_taken, int speed) {
    printf("\nResults:\n");
    if (strcmp(passage, user_input) == 0) {
        printf("Congratulations! You've typed the passage correctly.\n");
    } else {
        printf("The passage was not typed correctly. Keep practicing!\n");
    }
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Typing speed: %d words per minute\n", speed);
}

int main() {
    srand(time(NULL));
    int index = rand() % MAX_PASSAGES;

    char user_input[MAX_LENGTH];
    clock_t start_time, end_time;

    display_passage(passages[index]);

    start_time = clock();
    get_user_input(user_input);
    end_time = clock();

    double time_taken = calculate_time_taken(start_time, end_time);
    int typing_speed = calculate_typing_speed(user_input, time_taken);

    display_results(passages[index], user_input, time_taken, typing_speed);
    
    return 0;
}