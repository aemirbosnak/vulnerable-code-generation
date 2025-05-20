//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Function to get a random word from a file
char *get_random_word(FILE *fp) {
    // Get the file size
    fseek(fp, 0L, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    // Generate a random number between 0 and file_size
    srand(time(NULL));
    long random_number = rand() % file_size;

    // Seek to the random position in the file
    fseek(fp, random_number, SEEK_SET);

    // Read the word from the file
    char *word = malloc(100);
    fscanf(fp, "%s", word);

    // Return the word
    return word;
}

// Function to test the user's typing speed
void test_typing_speed() {
    // Get the list of words from the file
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    // Get the user's input
    char input[100];
    printf("Type the following word as fast as you can:\n");
    char *word = get_random_word(fp);
    printf("%s\n", word);
    scanf("%s", input);

    // Calculate the time taken to type the word
    clock_t start_time = clock();
    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate the typing speed
    double typing_speed = strlen(word) / time_taken;

    // Print the typing speed
    printf("Your typing speed is: %.2f words per minute\n", typing_speed * 60);
}

// Main function
int main() {
    // Test the user's typing speed
    test_typing_speed();

    return 0;
}