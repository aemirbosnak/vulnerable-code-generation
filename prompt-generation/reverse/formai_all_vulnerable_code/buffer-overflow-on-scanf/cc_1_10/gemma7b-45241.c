//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: expert-level
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 100

char words[MAX_WORDS][20] = {
    "The quick brown fox jumps over the lazy dog.",
    "A bright copper kettle sits on the table.",
    "The early bird gets the worm.",
    "The cat sat on the mat.",
    "The wind blew through the trees.",
    // Add more words here...
};

int main() {
    int i, j, score = 0, time_start, time_end;
    char user_word[20];

    // Seed the random number generator
    srand(time(NULL));

    // Select a random word from the list
    i = rand() % MAX_WORDS;
    printf("Word: %s", words[i]);

    // Start the timer
    time_start = clock();

    // Get the user's word
    scanf("%s", user_word);

    // Stop the timer
    time_end = clock();

    // Calculate the time taken
    int time_taken = (time_end - time_start) / CLOCKS_PER_SEC;

    // Check if the user's word is correct
    for (j = 0; words[i][j] != '\0'; j++) {
        if (user_word[j] != words[i][j]) {
            score--;
        }
    }

    // Calculate the user's score
    score = MAX_WORDS - time_taken - score;

    // Display the user's score
    printf("Your score: %d", score);

    return 0;
}