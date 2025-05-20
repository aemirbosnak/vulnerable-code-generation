//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_STRING_LENGTH 1000
#define TEST_STRINGS_COUNT 10
#define BUFFER_SIZE 256

const char *test_strings[TEST_STRINGS_COUNT] = {
    "The quick brown fox jumps over the lazy dog.",
    "A journey of a thousand miles begins with a single step.",
    "To be or not to be, that is the question.",
    "All that glitters is not gold.",
    "In the middle of every difficulty lies opportunity.",
    "The only thing we have to fear is fear itself.",
    "You miss 100% of the shots you don't take.",
    "I think, therefore I am.",
    "Life is what happens when you're busy making other plans.",
    "To infinity and beyond!"
};

void print_instructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be provided with a series of sentences to type.\n");
    printf("Try to type them as quickly and accurately as possible.\n");
    printf("Press Enter to start the test.\n");
}

void scramble_string(char *str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len - 1; i++) {
        size_t j = i + rand() / (RAND_MAX / (len - i) + 1);
        char temp = str[j];
        str[j] = str[i];
        str[i] = temp;
    }
}

void conduct_test() {
    char input[BUFFER_SIZE];
    int correct_count = 0;
    time_t start_time, end_time;

    for (int i = 0; i < TEST_STRINGS_COUNT; i++) {
        printf("\nSentence %d (be quick!):\n", i + 1);
        printf("%s\n", test_strings[i]);
        printf("Type here: ");

        start_time = time(NULL);
        fgets(input, BUFFER_SIZE, stdin);
        end_time = time(NULL);

        // Strip newline character if present
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, test_strings[i]) == 0) {
            printf("Correct!\n");
            correct_count++;
        } else {
            printf("Incorrect. You typed: '%s'\n", input);
        }

        printf("Time taken: %ld seconds\n", end_time - start_time);
    }

    printf("\nYou typed %d out of %d sentences correctly.\n", correct_count, TEST_STRINGS_COUNT);
}

int main() {
    srand(time(NULL)); // Seed random number generator
    print_instructions();
    getchar(); // Wait for user to press Enter

    conduct_test();

    printf("Thank you for participating in the Typing Speed Test!\n");
    return 0;
}