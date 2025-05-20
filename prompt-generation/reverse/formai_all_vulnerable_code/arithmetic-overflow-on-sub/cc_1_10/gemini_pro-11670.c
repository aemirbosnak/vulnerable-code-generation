//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the words for the test
char *words[] = {
    "abyss", "binary", "cipher", "decryption", "enigma",
    "frequency", "glitch", "hack", "information", "jargon",
    "kernel", "latency", "malware", "network", "oracle",
    "patch", "quantum", "rogue", "security", "trojan",
    "upload", "virus", "web", "x-ray", "zero-day"
};

// Define the number of words in the test
#define NUM_WORDS 25

// Define the time limit for the test (in seconds)
#define TIME_LIMIT 60

// Get a random word from the list
char *get_random_word() {
    return words[rand() % NUM_WORDS];
}

// Start the typing test
void start_test() {
    // Get the current time
    time_t start_time = time(NULL);

    // Print the instructions
    printf("Type the following words as quickly and accurately as possible:\n\n");

    // Loop through the words and display them one at a time
    for (int i = 0; i < NUM_WORDS; i++) {
        char *word = get_random_word();
        printf("%s\n", word);
    }

    // Get the current time again
    time_t end_time = time(NULL);

    // Calculate the time taken to complete the test
    int time_taken = end_time - start_time;

    // Calculate the typing speed (in words per minute)
    int typing_speed = (NUM_WORDS * 60) / time_taken;

    // Print the results
    printf("\n\nYour typing speed is %d words per minute.\n", typing_speed);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Start the typing test
    start_test();

    return 0;
}