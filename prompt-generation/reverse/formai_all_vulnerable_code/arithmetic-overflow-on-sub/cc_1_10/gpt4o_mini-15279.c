//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define BUFFER_SIZE 256
#define TEXT_SIZE 512

void display_intro(const char* text) {
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following text as fast and accurately as you can:\n\n");
    printf("%s\n\n", text);
    printf("Press Enter when you are ready to start...\n");
    getchar();
}

int count_words(const char* text) {
    int count = 0;
    const char* current = text;
    
    while (*current) {
        while (*current && isspace((unsigned char)*current)) current++; // skip whitespace
        if (*current) count++;
        while (*current && !isspace((unsigned char)*current)) current++; // skip non-whitespace
    }
    
    return count;
}

double calculate_speed(int word_count, double time_taken) {
    return (double)word_count / (time_taken / 60.0); // words per minute
}

void read_input(char* buffer, size_t size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
}

int compare_texts(const char* original, const char* user_input) {
    return strcmp(original, user_input);
}

void display_results(int word_count, double time_taken, const char* original, const char* user_input) {
    double speed = calculate_speed(word_count, time_taken);
    int errors = compare_texts(original, user_input);

    printf("\n===== Results =====\n");
    printf("Total Words: %d\n", word_count);
    printf("Time Taken: %.2f seconds\n", time_taken);
    printf("Typing Speed: %.2f WPM\n", speed);
    printf("Errors: %d\n", errors);
    
    if (errors == 0) {
        printf("Perfect match! Great job!\n");
    } else {
        printf("Keep practicing to reduce typos!\n");
    }
}

int main() {
    const char* sample_text = "The quick brown fox jumps over the lazy dog.";
    char user_input[TEXT_SIZE];
    clock_t start_time, end_time;
    
    display_intro(sample_text);
    
    start_time = clock();
    read_input(user_input, TEXT_SIZE);
    end_time = clock();
    
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    int word_count = count_words(sample_text);
    
    display_results(word_count, time_taken, sample_text, user_input);
    
    return 0;
}