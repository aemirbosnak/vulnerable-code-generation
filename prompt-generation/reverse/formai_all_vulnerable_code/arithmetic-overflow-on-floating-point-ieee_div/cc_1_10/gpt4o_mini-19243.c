//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_LEN 256
#define TIME_LIMIT 60

void display_instructions() {
    printf("Welcome to the C Typing Speed Test!\n");
    printf("You will be given a sentence to type as fast as you can.\n");
    printf("You have %d seconds to complete it.\n", TIME_LIMIT);
    printf("Press Enter to start...\n");
    getchar();
}

char* get_random_sentence() {
    char *sentences[] = {
        "The quick brown fox jumps over the lazy dog.",
        "A journey of a thousand miles begins with a single step.",
        "To be or not to be, that is the question.",
        "All that glitters is not gold.",
        "In the middle of difficulty lies opportunity.",
        "Life is what happens when you're busy making other plans.",
        "You miss 100% of the shots you don’t take.",
        "The only limit to our realization of tomorrow is our doubts of today.",
        "Success is not how high you have climbed, but how you make a positive difference to the world.",
        "What lies behind us and what lies before us are tiny matters compared to what lies within us."
    };

    int randIndex = rand() % (sizeof(sentences) / sizeof(sentences[0]));
    return sentences[randIndex];
}

void calculate_speed(int typed_chars, double time_taken) {
    double speed = (typed_chars / 5.0) / (time_taken / 60.0); // words per minute
    printf("Your typing speed is: %.2f words per minute.\n", speed);
}

void start_typing_test() {
    char *sentence = get_random_sentence();
    char input[MAX_LEN];
    int typed_chars = 0;

    printf("\nType the following sentence:\n");
    printf("\"%s\"\n\n", sentence);
    printf("Starting in 3 seconds...\n");
    sleep(3);

    time_t start_time = time(NULL);
    fgets(input, MAX_LEN, stdin);
    
    time_t end_time = time(NULL);
    double time_taken = difftime(end_time, start_time);

    if (time_taken > TIME_LIMIT) {
        printf("Time's up! You took too long to type the sentence.\n");
    }

    // Calculate characters typed
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == sentence[i]) {
            typed_chars++;
        } else {
            break; // stop counting at first incorrect character
        }
    }

    calculate_speed(typed_chars, time_taken);
}

int main() {
    srand(time(NULL)); // Seed random number generator
    display_instructions();
    start_typing_test();
    
    printf("\nThanks for playing!\n");
    return 0;
}