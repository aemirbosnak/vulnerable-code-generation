//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score = 0;
    int correct_answers = 0;
    int total_words = 0;
    char word[100];
    char input[100];
    int length;
    int i;
    time_t start_time, end_time;
    double elapsed_time;

    // Seed the random number generator
    srand(time(NULL));

    // Get the number of words to type from the user
    printf("How many words do you want to type? ");
    scanf("%d", &length);

    // Generate a list of random words
    for (i = 0; i < length; i++) {
        sprintf(word, "word%d", i + 1);
        printf("%s ", word);
        total_words++;
    }
    printf("\n");

    // Start the timer
    start_time = time(NULL);

    // Get user input and compare to the correct answer
    while (scanf("%s", input)!= EOF) {
        if (strcmp(input, word) == 0) {
            correct_answers++;
        }
        score += strlen(input);
        total_words++;
    }

    // Stop the timer
    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    // Calculate the typing speed in words per minute
    double words_per_minute = (double)total_words / elapsed_time * 60;

    // Print the results
    printf("You typed %d words in %d seconds.\n", total_words, elapsed_time);
    printf("Your typing speed is %.2f words per minute.\n", words_per_minute);
    printf("You got %d out of %d words correct (%.2f%%).\n", correct_answers, total_words, 100.0 * correct_answers / total_words);

    return 0;
}