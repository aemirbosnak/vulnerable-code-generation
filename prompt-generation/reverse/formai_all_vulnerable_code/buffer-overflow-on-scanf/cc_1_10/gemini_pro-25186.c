//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototypes
int get_random_number(int min, int max);
void print_random_words(int num_words);
void print_instructions();
void get_user_input(char *buffer);
void calculate_wpm(int num_words, double time_taken);
void print_results(int wpm);

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Print the instructions
    print_instructions();

    // Get the user's input
    char buffer[1024];
    get_user_input(buffer);

    // Calculate the time taken
    clock_t start = clock();
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate the WPM
    int num_words = 0;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == ' ') {
            num_words++;
        }
    }
    calculate_wpm(num_words, time_taken);

    // Print the results
    print_results(num_words);

    return 0;
}

int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void print_random_words(int num_words) {
    for (int i = 0; i < num_words; i++) {
        int word_length = get_random_number(3, 10);
        for (int j = 0; j < word_length; j++) {
            int letter = get_random_number('a', 'z');
            printf("%c", letter);
        }
        printf(" ");
    }
}

void print_instructions() {
    printf("Welcome to the typing speed test!\n");
    printf("Instructions:\n");
    printf("1. Start typing as soon as the words appear on the screen.\n");
    printf("2. Type the words exactly as they appear, including spaces and punctuation.\n");
    printf("3. Press the Enter key when you have finished typing.\n");
    printf("\nPress any key to start the test...");
    getchar();
}

void get_user_input(char *buffer) {
    printf("\nStart typing:\n");
    scanf("%[^\n]s", buffer);
}

void calculate_wpm(int num_words, double time_taken) {
    double wpm = (double)num_words / time_taken * 60;
}

void print_results(int wpm) {
    printf("\nYour typing speed is %d WPM.\n", wpm);
}