//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_SENTENCE_LENGTH 256
#define NUM_SENTENCES 5

// Function prototypes
void display_intro();
void display_sentence(const char *sentence);
void calculate_typing_speed(time_t start_time, time_t end_time, int chars_typed);
const char* get_random_sentence();

int main() {
    display_intro();

    const char *sentence = get_random_sentence();
    display_sentence(sentence);

    time_t start_time, end_time;
    char user_input[MAX_SENTENCE_LENGTH];

    printf("\nType the above sentence (case sensitive):\n");
    start_time = time(NULL);

    // Read user input
    fgets(user_input, MAX_SENTENCE_LENGTH, stdin);

    end_time = time(NULL);

    // Strip newline character from user input
    user_input[strcspn(user_input, "\n")] = 0;

    if (strcmp(user_input, sentence) == 0) {
        int chars_typed = strlen(user_input);
        calculate_typing_speed(start_time, end_time, chars_typed);
    } else {
        printf("Oops! Your input did not match the provided sentence.\n");
    }

    return 0;
}

void display_intro() {
    printf("\n===================================\n");
    printf("      WELCOME TO TYPING TEST      \n");
    printf("===================================\n");
    sleep(1);
}

void display_sentence(const char *sentence) {
    printf("\nHere is the sentence:\n");
    printf("\"%s\"\n", sentence);
}

void calculate_typing_speed(time_t start_time, time_t end_time, int chars_typed) {
    double time_taken = difftime(end_time, start_time);
    double speed_wpm = (chars_typed / 5.0) / (time_taken / 60.0); // words per minute
    printf("\nTime taken: %.2f seconds\n", time_taken);
    printf("Typing Speed: %.2f words per minute\n", speed_wpm);
}

const char* get_random_sentence() {
    const char *sentences[NUM_SENTENCES] = {
        "The quick brown fox jumps over the lazy dog.",
        "Programming in C is both fun and challenging.",
        "Linux is an open-source operating system.",
        "Typing tests can help improve your skills.",
        "Practice makes perfect in every skill you develop."
    };

    srand(time(NULL));
    int random_index = rand() % NUM_SENTENCES;
    return sentences[random_index];
}