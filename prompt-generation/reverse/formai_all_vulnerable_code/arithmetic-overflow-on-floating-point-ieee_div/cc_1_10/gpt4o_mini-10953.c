//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_WORDS 100
#define MAX_LENGTH 20
#define BUFFER_SIZE 256

// Function to generate a random word
void generate_random_word(char *word) {
    int length = rand() % (MAX_LENGTH - 1) + 1; // Random length between 1 and MAX_LENGTH
    for (int i = 0; i < length; i++) {
        word[i] = 'a' + rand() % 26; // Random lowercase letter
    }
    word[length] = '\0'; // Null terminate the string
}

// Function to generate a random sentence
void generate_random_sentence(char *sentence) {
    int words_count = rand() % (MAX_WORDS - 1) + 1; // Random number of words
    for (int i = 0; i < words_count; i++) {
        char word[MAX_LENGTH + 1];
        generate_random_word(word);
        strcat(sentence, word);
        if (i != words_count - 1) {
            strcat(sentence, " "); // Space between words
        }
    }
}

// Function to measure typing speed
void typing_test() {
    printf("Ready to test your typing speed? Press Enter to start...\n");
    getchar(); // Wait for user to press Enter

    char sentence[BUFFER_SIZE] = "";
    generate_random_sentence(sentence);
    
    printf("Try to type the following sentence as fast as you can:\n");
    printf("\"%s\"\n", sentence);
    
    char input[BUFFER_SIZE];
    time_t start_time = time(NULL);
    printf("Start typing: ");
    fgets(input, BUFFER_SIZE, stdin);
    time_t end_time = time(NULL);
    
    // Calculate elapsed time
    double elapsed_time = difftime(end_time, start_time);
    
    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';
    
    // Check if the input matches the sentence
    if (strcmp(input, sentence) == 0) {
        printf("Wow! Great job! You typed it correctly!\n");
    } else {
        printf("Oops! There was a mistake:\n");
        printf("You typed: \"%s\"\n", input);
        printf("Expected: \"%s\"\n", sentence);
    }

    // Calculate typing speed
    int words_typed = 0;
    char *token = strtok(input, " ");
    while (token != NULL) {
        words_typed++;
        token = strtok(NULL, " ");
    }

    double speed = words_typed / elapsed_time * 60; // Words per minute
    printf("Your typing speed is: %.2f words per minute.\n", speed);
}

// Function to display the instructions
void display_instructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("In this program, you'll be challenged to type a random sentence.\n");
    printf("You will be timed, and your typing speed will be calculated in words per minute.\n");
    printf("If you make any mistakes in typing the sentence, it will be displayed for comparison.\n\n");
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator
    display_instructions();
    
    char choice;
    do {
        typing_test(); // Start the typing test

        printf("Do you want to try again? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // Consume the newline character left in the buffer
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for participating! Have a great day!\n");
    return 0;
}