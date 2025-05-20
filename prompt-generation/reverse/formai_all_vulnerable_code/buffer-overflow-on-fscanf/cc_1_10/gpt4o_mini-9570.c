//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define PROMPT_LENGTH 256

void generate_sentence(char words[MAX_WORDS][MAX_WORD_LENGTH], int word_count, char *output_sentence) {
    int i;
    for (i = 0; i < word_count; i++) {
        strcat(output_sentence, words[rand() % MAX_WORDS]);
        if (i < word_count - 1) {
            strcat(output_sentence, " ");
        }
    }
}

void load_words(const char *filename, char words[MAX_WORDS][MAX_WORD_LENGTH], int *word_count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open word list");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", words[*word_count]) != EOF) {
        (*word_count)++;
        if (*word_count >= MAX_WORDS) {
            break;
        }
    }

    fclose(file);
}

void print_instructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be presented with a sentence to type.\n");
    printf("Your goal is to type it as quickly and accurately as possible.\n");
    printf("Press Enter to start...\n");
    getchar();
}

double calculate_time_taken(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
}

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count = 0;

    // Load words from a file
    load_words("wordlist.txt", words, &word_count);

    // Prepare for the game
    print_instructions();

    int sentence_length = 10; // Number of words in the sentence
    char output_sentence[PROMPT_LENGTH] = "";
    srand(time(NULL)); // Seed the random number generator

    // Generate random sentence
    generate_sentence(words, sentence_length, output_sentence);
    printf("Type the following sentence:\n\n");
    printf("%s\n\n", output_sentence);

    // Start timing
    struct timespec start_time, end_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    // Get user input
    char user_input[PROMPT_LENGTH];
    printf("Your input: ");
    fgets(user_input, sizeof(user_input), stdin);
    // Remove newline character
    user_input[strcspn(user_input, "\n")] = 0;

    // Stop timing
    clock_gettime(CLOCK_MONOTONIC, &end_time);

    // Calculate time taken
    double time_taken = calculate_time_taken(start_time, end_time);
    printf("Time taken: %.2f seconds\n", time_taken);

    // Calculate accuracy
    int correct_chars = 0;
    int total_chars = strlen(output_sentence);
    if (strcmp(user_input, output_sentence) == 0) {
        correct_chars = total_chars;
    } else {
        for (int i = 0; i < total_chars; i++) {
            if (user_input[i] == output_sentence[i]) {
                correct_chars++;
            }
        }
    }

    printf("Your accuracy: %.2f%%\n", (correct_chars / (float)total_chars) * 100);
    printf("Words per minute: %.2f WPM\n",
           (sentence_length / (time_taken / 60.0)));

    return 0;
}