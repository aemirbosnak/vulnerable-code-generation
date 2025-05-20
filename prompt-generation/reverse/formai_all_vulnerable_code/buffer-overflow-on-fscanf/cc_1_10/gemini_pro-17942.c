//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20
#define MAX_TEST_TIME 60

// Function prototypes
void print_instructions();
void generate_words(char words[][MAX_WORD_LENGTH], int *num_words);
void start_test(char words[][MAX_WORD_LENGTH], int num_words);
void calculate_results(int num_correct, int num_incorrect, int test_time);

int main() {
    // Print the instructions
    print_instructions();

    // Generate the words
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int num_words;
    generate_words(words, &num_words);

    // Start the test
    start_test(words, num_words);

    return 0;
}

void print_instructions() {
    printf("Welcome to the typing speed test!\n");
    printf("Instructions:\n");
    printf("1. You will be given a list of words to type.\n");
    printf("2. Type the words as quickly and accurately as possible.\n");
    printf("3. The test will end after 60 seconds.\n");
    printf("4. Your typing speed will be calculated based on the number of words you type correctly.\n");
    printf("\nPress any key to start the test.\n");
    getchar();
}

void generate_words(char words[][MAX_WORD_LENGTH], int *num_words) {
    // Open the file containing the word list
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error opening the word list file.\n");
        exit(1);
    }

    // Read the words from the file
    int i = 0;
    while (fscanf(file, "%s", words[i]) != EOF) {
        i++;
    }

    // Close the file
    fclose(file);

    // Set the number of words
    *num_words = i;
}

void start_test(char words[][MAX_WORD_LENGTH], int num_words) {
    // Start the timer
    clock_t start_time = clock();

    // Get the current time
    time_t current_time = time(NULL);

    // Loop through the words
    int i;
    int num_correct = 0;
    int num_incorrect = 0;
    for (i = 0; i < num_words; i++) {
        // Get the user's input
        char input[MAX_WORD_LENGTH];
        printf("%s: ", words[i]);
        scanf("%s", input);

        // Check if the user's input is correct
        if (strcmp(input, words[i]) == 0) {
            num_correct++;
        } else {
            num_incorrect++;
        }

        // Check if the time is up
        time_t new_time = time(NULL);
        if (new_time - current_time >= MAX_TEST_TIME) {
            break;
        }

        // Update the current time
        current_time = new_time;
    }

    // Stop the timer
    clock_t end_time = clock();

    // Calculate the results
    calculate_results(num_correct, num_incorrect, end_time - start_time);
}

void calculate_results(int num_correct, int num_incorrect, int test_time) {
    // Calculate the typing speed
    double typing_speed = (double)num_correct / test_time * 60;

    // Print the results
    printf("\nYour typing speed is %.2f words per minute.\n", typing_speed);
    printf("You typed %d words correctly and %d words incorrectly.\n", num_correct, num_incorrect);
}