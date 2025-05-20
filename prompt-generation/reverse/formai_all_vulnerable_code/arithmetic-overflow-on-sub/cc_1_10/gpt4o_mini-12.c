//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_SENTENCES 10
#define MAX_LENGTH 256

const char* sentences[MAX_SENTENCES] = {
    "The quick brown fox jumps over the lazy dog.",
    "A journey of a thousand miles begins with a single step.",
    "To be or not to be, that is the question.",
    "All that glitters is not gold.",
    "In the middle of difficulty lies opportunity.",
    "Life is 10% what happens to us and 90% how we react to it.",
    "Success is not final, failure is not fatal: It is the courage to continue that counts.",
    "The only limit to our realization of tomorrow is our doubts of today.",
    "The future belongs to those who believe in the beauty of their dreams.",
    "You must be the change you wish to see in the world."
};

// Function to calculate typing speed in WPM
double calculate_wpm(int word_count, double seconds) {
    return (word_count / seconds) * 60;
}

// Function to count words in a string
int count_words(const char *str) {
    int count = 0;
    int in_word = 0;
    while (*str) {
        if (isspace(*str)) {
            in_word = 0;
        } else if (in_word == 0) {
            in_word = 1;
            count++;
        }
        str++;
    }
    return count;
}

// Function to handle the typing test
void typing_test() {
    char input[MAX_LENGTH];
    int random_index = rand() % MAX_SENTENCES;
    
    printf("Type the following sentence:\n");
    printf("\"%s\"\n\n", sentences[random_index]);

    clock_t start_time = clock();
    fgets(input, sizeof(input), stdin);
    clock_t end_time = clock();

    double seconds = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    
    // Ensure the input matches
    if (strcmp(input, sentences[random_index]) == 0) {
        int word_count = count_words(input);
        double wpm = calculate_wpm(word_count, seconds);
        printf("Congratulations! You typed it correctly.\n");
        printf("Time taken: %.2f seconds\n", seconds);
        printf("Your typing speed is: %.2f WPM\n", wpm);
    } else {
        printf("Oops! There were some mistakes in your typing.\n");
        printf("Please try again.\n");
    }
}

// Main function
int main() {
    srand(time(NULL));
    
    printf("Welcome to the Typing Speed Test!\n");
    while (1) {
        typing_test();
        
        char choice;
        printf("\nDo you want to try again? (y/n): ");
        scanf(" %c", &choice);
        getchar();  // To consume the newline character left in buffer
        if (choice != 'y') {
            printf("Thank you for playing! Goodbye!\n");
            break;
        }
    }
    
    return 0;
}