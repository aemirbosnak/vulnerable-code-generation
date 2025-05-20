//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_LENGTH 300
#define PROMPT_COUNT 5
#define TIME_LIMIT 60

const char *prompts[PROMPT_COUNT] = {
    "In the year 2142, humanity has merged with AI.",
    "Virtual reality has evolved into a new form of existence.",
    "The exploration of Mars has led to the discovery of ancient artifacts.",
    "Telepathy devices connect minds across vast distances.",
    "A new era of quantum computing allows instant problem solving."
};

void display_instructions() {
    printf("\n=== FUTURIST TYPING SPEED TEST ===\n");
    printf("Welcome, Typist of the Future!\n");
    printf("Type the following phrases as fast as you can within %d seconds...\n\n", TIME_LIMIT);
}

void get_time_taken(double start_time, double end_time, double *time_taken) {
    *time_taken = difftime(end_time, start_time);
}

void calculate_speed(int length, double time_taken) {
    double speed = (length / time_taken) * 60; // Words per minute
    printf("Your typing speed is: %.2f words per minute.\n", speed);
}

void show_results(int correct, int total) {
    printf("\n=== RESULTS ===\n");
    printf("Typed correctly: %d out of %d\n", correct, total);
    printf("Accuracy: %.2f%%\n", (correct / (float)total) * 100.0);
}

void clear_screen() {
    printf("\033[H\033[J"); // ANSI escape code to clear the screen
}

int main() {
    char input[MAX_LENGTH];
    int correct_count = 0;
    
    srand(time(NULL)); // seed for random selection
    
    for (int i = 0; i < PROMPT_COUNT; i++) {
        clear_screen();
        display_instructions();
        
        // Randomly select a prompt 
        int random_index = rand() % PROMPT_COUNT;
        const char *current_prompt = prompts[random_index];
        
        printf("Type this phrase:\n\n");
        printf("\"%s\"\n\n", current_prompt);
        printf("You have %d seconds to complete this task. Begin typing!\n", TIME_LIMIT);
        printf("Press Enter to start...\n");
        
        getchar(); // Wait for user to press Enter
        
        time_t start_time = time(NULL);
        time_t end_time = start_time + TIME_LIMIT;

        while (time(NULL) < end_time) {
            int r = read(STDIN_FILENO, input, sizeof(input) - 1);
            if (r > 0) {
                input[r - 1] = '\0'; // null-terminate the input, removing newline
                if (strcmp(input, current_prompt) == 0) {
                    printf("Correct!\n");
                    correct_count++;
                    break;
                } else {
                    printf("Incorrect, keep going...\n");
                }
            }
        }

        get_time_taken(start_time, end_time, &(end_time)); // Time taken until entry or timeout

        if (time(NULL) >= end_time) {
            printf("Time's up! You did not complete the phrase in time.\n");
        }
    }

    show_results(correct_count, PROMPT_COUNT);
    
    return 0;
}