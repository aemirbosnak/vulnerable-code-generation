//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define NUM_TESTS 5

char *sample_texts[NUM_TESTS] = {
    "The quick brown fox jumps over the lazy dog.",
    "C programming is fun and exciting!",
    "Typing speed tests are a great way to practice.",
    "Always strive for improvement, consistency is key.",
    "Code is like humor. When you have to explain it, it’s bad."
};

void clear_screen() {
    printf("\033[H\033[J"); // ANSI escape code to clear the screen
}

void display_welcome() {
    clear_screen();
    printf("🌟 Welcome to the Ultimate Typing Speed Test! 🌟\n");
    printf("Ready to show off your typing skills? Let's get started!\n\n");
    printf("You will be given a series of sentences to type.\n");
    printf("Press ENTER when you are ready to begin!\n\n");
    getchar();
}

void start_typing_test(int test_number) {
    char user_input[MAX_LENGTH];
    clock_t start, end;
    double time_taken;

    clear_screen();
    printf("Type the following sentence:\n\n");
    printf("\"%s\"\n\n", sample_texts[test_number]);
    printf("Start typing now...\n");

    start = clock();
    fgets(user_input, MAX_LENGTH, stdin);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nYou took %.2f seconds to type the sentence.\n", time_taken);

    // Compare the input with the original text
    if (strcmp(sample_texts[test_number], user_input) == 0) {
        printf("🎉 Perfect! You typed it correctly! 🎉\n");
    } else {
        printf("🔴 Oops! There were some mistakes. Keep practicing! 🔴\n");
        printf("Your input: \"%s\"\n", user_input);
        printf("Expected: \"%s\"\n", sample_texts[test_number]);
    }

    printf("\nPress ENTER to continue to the next test!\n");
    getchar();
}

void show_final_scores(int scores[], int num_tests) {
    clear_screen();
    printf("🏆 Final Scores! 🏆\n");

    for (int i = 0; i < num_tests; i++) {
        printf("Test %d: %.2f seconds\n", i + 1, scores[i]);
    }

    printf("🎉 Thank you for participating in the Typing Speed Test! 🎉\n");
}

int main() {
    int scores[NUM_TESTS];
    display_welcome();

    for (int i = 0; i < NUM_TESTS; i++) {
        double time_taken;
        start_typing_test(i);
        printf("How fast were you? Enter your seconds for Test %d: ", i + 1);
        scanf("%lf", &time_taken);
        scores[i] = time_taken;
        getchar(); // Clear the newline character from buffer
    }

    show_final_scores(scores, NUM_TESTS);
    return 0;
}