//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_WORDS 100
#define MAX_LENGTH 50

void generate_random_sentence(char *sentence, int word_count) {
    const char *word_pool[] = {
        "life", "is", "a", "journey", "filled", "with", "unexpected", "twists", "and", "turns",
        "you", "never", "know", "what", "lies", "ahead", "but", "embrace", "the", "adventure",
        "each", "day", "new", "possibilities", "arise", "dream", "imagine", "create", 
        "make", "a", "difference", "in", "the", "world", "beyond", "your", "wildest", "dreams"
    };
    srand((unsigned int)time(NULL));
    
    for (int i = 0; i < word_count; i++) {
        strcat(sentence, word_pool[rand() % (sizeof(word_pool) / sizeof(word_pool[0]))]);
        if (i < word_count - 1) {
            strcat(sentence, " ");
        }
    }
    strcat(sentence, ".");
}

void print_instructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a sentence to type. Once you finish, press Enter to submit.\n");
    printf("Let's see how fast you can type!\n\n");
}

double get_typing_speed(double time_taken, int character_count) {
    double minutes = time_taken / 60.0;
    return character_count / 5.0 / minutes; // Words are generally measured as 5 characters per word
}

void wait_for_user() {
    printf("Press Enter to start...");
    getchar();
}

int main() {
    char sentence[256] = "";
    int word_count = rand() % 10 + 5; // Random word count between 5 and 15

    char user_input[256];
    time_t start_time, end_time;

    print_instructions();
    wait_for_user();

    generate_random_sentence(sentence, word_count);
    printf("\nType the following sentence:\n\n");
    printf("%s\n", sentence);

    start_time = time(NULL);
    fgets(user_input, sizeof(user_input), stdin);
    end_time = time(NULL);

    // Remove the new line character that fgets appends
    user_input[strcspn(user_input, "\n")] = 0;

    int character_count = strlen(user_input);
    printf("\nYou typed: %s\n", user_input);
    
    // Check for correctness of typing
    if (strcmp(user_input, sentence) == 0) {
        double time_taken = difftime(end_time, start_time);
        double speed = get_typing_speed(time_taken, character_count);
        printf("Congratulations! You typed it correctly.\n");
        printf("Time taken: %.2f seconds\n", time_taken);
        printf("Typing speed: %.2f words per minute\n", speed);
    } else {
        printf("Oops! Your input did not match the sentence.\n");
        printf("Try again to improve your speed and accuracy!\n");
        printf("Your input: %s\n", user_input);
        printf("Correct sentence: %s\n", sentence);
    }

    printf("Thank you for participating in the Typing Speed Test!\n");
    return 0;
}