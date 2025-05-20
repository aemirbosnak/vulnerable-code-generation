//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256

void print_instructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a line of text to type as quickly as possible.\n");
    printf("Press Enter to start the test.\n");
    getchar();
}

const char *get_random_text() {
    static const char *texts[] = {
        "The quick brown fox jumps over the lazy dog.",
        "Hello, world! This is a typing speed test.",
        "Programming is like riding a bike: you never forget how.",
        "To be or not to be, that is the question.",
        "In the middle of difficulty lies opportunity.",
        "Success usually comes to those who are too busy to be looking for it.",
        "The only limit to our realization of tomorrow is our doubts of today."
    };
    return texts[rand() % (sizeof(texts) / sizeof(texts[0]))];
}

void measure_typing_speed(const char *text) {
    char input[MAX_LINE_LENGTH];
    time_t start_time, end_time;
    
    printf("Type the following text:\n");
    printf("\"%s\"\n", text);
    printf("Start typing now...\n");
    
    start_time = time(NULL);
    
    if (fgets(input, MAX_LINE_LENGTH, stdin) == NULL) {
        perror("Input error");
        return;
    }
    
    end_time = time(NULL);
    double time_taken = difftime(end_time, start_time);
    
    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    if (strcmp(input, text) == 0) {
        printf("Well done! You typed the text correctly.\n");
    } else {
        printf("Your input was incorrect. Try again!\n");
    }
    
    // Calculate speed
    double speed = (strlen(text) / time_taken) * 60; // words per minute calculation
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Typing speed: %.2f characters per minute\n", speed);
}

int main() {
    srand(time(NULL));
    
    print_instructions();
    
    const char *text = get_random_text();
    
    measure_typing_speed(text);
    
    return 0;
}