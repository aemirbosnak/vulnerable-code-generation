//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_LENGTH 1024
#define SAMPLE_TEXT_LENGTH 5

const char *sample_texts[SAMPLE_TEXT_LENGTH] = {
    "My love for you is like the ocean, endless and deep.",
    "In the garden of your heart, I find my home.",
    "Your laughter is the melody that dances in my soul.",
    "With every heartbeat, I whisper your name.",
    "You are the stars that light up my darkest nights."
};

void display_welcome_message() {
    printf("***************************************\n");
    printf("*          A Romantic Typing Test     *\n");
    printf("***************************************\n");
    printf("Type the following romantic phrases as fast as you can:\n\n");
}

const char *get_random_sample() {
    srand(time(NULL));
    return sample_texts[rand() % SAMPLE_TEXT_LENGTH];
}

void ask_for_ready() {
    printf("Are you ready to begin? (Press Enter to continue)... ");
    getchar();
    printf("\nLet the typing begin...\n\n");
}

void start_typing_test(const char *text) {
    char user_input[MAX_LENGTH];
    printf("Type this:\n\"%s\"\n\n", text);

    clock_t start_time = clock();
    fgets(user_input, MAX_LENGTH, stdin);
    clock_t end_time = clock();

    double elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    if (elapsed_time == 0) {
        printf("You need to type a little faster, darling!\n");
        return;
    }

    // Removing newline character from user_input
    user_input[strcspn(user_input, "\n")] = 0;

    int correct_chars = 0;
    for (int i = 0; i < strlen(user_input); i++) {
        if (user_input[i] == text[i]) {
            correct_chars++;
        }
    }

    int total_chars = strlen(text);
    printf("\nYour time: %.2f seconds\n", elapsed_time);
    printf("You typed %d out of %d characters correctly.\n", correct_chars, total_chars);

    double accuracy = ((double) correct_chars / total_chars) * 100;
    printf("Your typing accuracy: %.2f%%\n\n", accuracy);
}

void display_farewell_message() {
    printf("***************************************\n");
    printf("*          Thank You, Sweetheart!    *\n");
    printf("***************************************\n");
    printf("May your fingers always dance gracefully on the keys!\n");
}

int main() {
    display_welcome_message();
    
    for (int i = 0; i < 3; i++) { // Three rounds of test
        const char *sample_text = get_random_sample();
        ask_for_ready();
        start_typing_test(sample_text);
    }

    display_farewell_message();
    
    return 0;
}