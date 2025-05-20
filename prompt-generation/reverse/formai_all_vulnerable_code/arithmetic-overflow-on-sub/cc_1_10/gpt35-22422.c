//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int words_per_minute, error_rate;
    int i, j, k, len, words, letters = 0;
    double time_taken, accuracy;

    char *text = "The quick brown fox jumps over the lazy dog. This sentence is just here to add some extra words. ";
    char user_input[1000];

    printf("Welcome to the typing speed test!\n");
    printf("You will be given a paragraph to type, and then your typing speed and accuracy will be calculated.\n");
    printf("Please type the following paragraph, press enter when you're finished:\n\n");
    printf("%s", text);

    clock_t start = clock();

    // Reading user input
    fgets(user_input, 1000, stdin);

    clock_t end = clock();
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Counting number of words and letters in target text
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ') {
            words++;
        }
        letters++;
    }

    // Counting number of errors in user input
    len = strlen(user_input);
    for (i =0; i < len; i++) {
        if (user_input[i] != text[i]) {
            error_rate++;
        }
    }

    // Calculating words per minute
    words_per_minute = (words / time_taken) * 60;

    // Calculating accuracy percentage
    accuracy = ((letters - error_rate) / (double) letters) * 100;

    printf("\nTime taken to complete: %.2lf seconds\n", time_taken);
    printf("Your typing speed is: %d words per minute\n", words_per_minute);
    printf("Your accuracy is: %.2lf percent\n", accuracy);
    printf("Thank you for taking the typing speed test!\n");

    return 0;
}