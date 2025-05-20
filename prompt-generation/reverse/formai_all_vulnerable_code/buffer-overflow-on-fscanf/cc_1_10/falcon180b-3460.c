//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

int main() {
    char *words[MAX_WORDS];
    int word_count = 0;
    int word_length = 0;
    int correct_words = 0;
    int incorrect_words = 0;
    int total_words = 0;
    int wpm = 0;
    int accuracy = 0;
    double elapsed_time = 0;
    char input_word[MAX_WORD_LENGTH];
    char input_buffer[MAX_WORD_LENGTH];
    int i, j;

    srand(time(NULL)); // Initialize random seed

    // Load words from file
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        return 1;
    }
    while (fscanf(file, "%s", input_word)!= EOF) {
        if (word_count >= MAX_WORDS) {
            printf("Error: too many words in words.txt\n");
            fclose(file);
            return 1;
        }
        words[word_count] = strdup(input_word);
        word_count++;
    }
    fclose(file);

    // Start test
    printf("Press enter to begin...\n");
    fgets(input_buffer, MAX_WORD_LENGTH, stdin);

    elapsed_time = 0;
    while (elapsed_time < 60) {
        if (word_count == 0) {
            break;
        }

        // Choose random word
        i = rand() % word_count;
        strcpy(input_word, words[i]);

        // Display word
        printf("%s", input_word);

        // Read input
        fgets(input_buffer, MAX_WORD_LENGTH, stdin);

        // Check input
        j = 0;
        while (input_buffer[j]!= '\n') {
            if (input_buffer[j]!= input_word[j]) {
                incorrect_words++;
            } else {
                correct_words++;
            }
            j++;
        }
        total_words++;

        // Free memory
        free(words[i]);
        words[i] = NULL;
        word_count--;

        // Update elapsed time
        elapsed_time += 1;
    }

    // Calculate WPM and accuracy
    wpm = (total_words / 5) * 60;
    accuracy = ((float)correct_words / total_words) * 100;

    // Print results
    printf("\nTest complete.\n");
    printf("Words per minute: %d\n", wpm);
    printf("Accuracy: %.2f%%\n", accuracy);

    return 0;
}