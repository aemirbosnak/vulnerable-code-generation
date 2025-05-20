//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_of_words, i, j, correct_words = 0, wrong_words = 0, total_chars, correct_chars = 0, wrong_chars = 0, net_speed, gross_speed;
    float wpm;
    char *words[] = {"mathematics", "programming", "algorithms", "data structures", "computer science", "software engineering", "artificial intelligence", "machine learning", "deep learning", "neural networks"};
    char input[100];

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Prompt the user for the number of words they want to type
    printf("How many words do you want to type? ");
    scanf("%d", &num_of_words);

    // Shuffle the array of words using the Fisher-Yates shuffle algorithm
    for (i = num_of_words - 1; i > 0; i--) {
        j = rand() % (i + 1);
        char *temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }

    // Display the words for the user to type
    printf("Type the following words:\n");
    for (i = 0; i < num_of_words; i++) {
        printf("%s\n", words[i]);
    }

    // Get the user's input and compare it to the correct words
    for (i = 0; i < num_of_words; i++) {
        printf("Type %s: ", words[i]);
        fgets(input, 100, stdin);
        total_chars += strlen(input);

        // Remove the newline character from the input
        input[strcspn(input, "\n")] = '\0';

        // Check if the input is correct
        if (strcmp(input, words[i]) == 0) {
            correct_words++;
            correct_chars += strlen(input);
        } else {
            wrong_words++;
            wrong_chars += strlen(input);
        }
    }

    // Calculate the user's typing speed
    net_speed = (float)correct_chars / 5;
    gross_speed = (float)total_chars / 5;
    wpm = (float)net_speed * 60;

    // Display the results
    printf("\nYou typed %d words correctly and %d words incorrectly.\n", correct_words, wrong_words);
    printf("Your net typing speed is %.2f wpm and your gross typing speed is %.2f wpm.\n", net_speed, gross_speed);

    return 0;
}