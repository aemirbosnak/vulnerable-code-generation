//Code Llama-13B DATASET v1.0 Category: Typing Speed Test ; Style: random
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_WORD_LEN 100
#define MAX_WORD_COUNT 100

// Function to generate random words
char* generate_random_word(int word_len) {
    char* word = malloc(word_len + 1);
    int i;
    for (i = 0; i < word_len; i++) {
        word[i] = 'a' + (rand() % 26);
    }
    word[word_len] = '\0';
    return word;
}

// Function to calculate the typing speed
float calculate_typing_speed(int word_count, double elapsed_time) {
    return (word_count / elapsed_time) * 60;
}

// Main function
int main() {
    // Generate a random sentence
    int word_count = 0;
    char* sentence = malloc(MAX_WORD_COUNT * MAX_WORD_LEN);
    char* word;
    int i;
    for (i = 0; i < MAX_WORD_COUNT; i++) {
        word = generate_random_word(MAX_WORD_LEN);
        strcat(sentence, word);
        strcat(sentence, " ");
        word_count++;
        free(word);
    }

    // Start the timer
    clock_t start_time = clock();

    // Get the user input
    char* input = malloc(MAX_WORD_COUNT * MAX_WORD_LEN);
    scanf("%s", input);

    // Calculate the elapsed time
    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate the typing speed
    float typing_speed = calculate_typing_speed(word_count, elapsed_time);

    // Print the results
    printf("Sentence: %s\n", sentence);
    printf("Typing Speed: %f words per minute\n", typing_speed);

    // Free memory
    free(sentence);
    free(input);

    return 0;
}