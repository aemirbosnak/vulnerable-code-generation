//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define SENTENCE_SIZE 100

char *get_sentence()
{
    char *sentence = malloc(SENTENCE_SIZE * sizeof(char));
    // You can add more sentences or make it an array to store multiple random sentences.
    const char *sentences[] = { "The quick brown fox jumps over the lazy dog.", 
                                "Pack my box with five dozen liquor jugs.",
                                "How vexingly quick daft zebras jump!",
                                "Sphinx of black quartz, judge my vow.",
                                "Jackdaws love my big sphinx of quartz.",
                                "Waltz, bad nymph, for quick jigs vex.",
                                "1234567890 qwertyuiop asdfghjkl zxcvbnm" };

    srand(time(NULL)); // Random seed based on current time
    int random_index = rand() % (sizeof(sentences) / sizeof(char *)); // Get a random index for sentence array
    char *random_sentence = (char *)sentences[random_index];
    for (int i = 0; i < SENTENCE_SIZE - 1 && random_sentence[i] != '\0'; i++)
    {
        sentence[i] = random_sentence[i];
    }
    return sentence;
}

void show_score(double wpm)
{
    printf("\n----------------------------\n");
    printf("Your typing speed: %.2f WPM\n", wpm);
    printf("----------------------------\n");
}

int main()
{
    char *sentence = get_sentence();
    printf("\nWelcome to the Typing Speed Test!\n\nType the following sentence as fast as you can:\n\n%s\n", sentence);
    int i = 0;
    int correct_count = 0;
    char input;
    clock_t start_time = clock(); // Start the timer
    while (sentence[i] != '\0')
    {
        input = tolower(getchar()); // Get input and convert to lowercase
        if (input == sentence[i])
        {
            correct_count++;
        }
        i++;
    }
    clock_t end_time = clock(); // End the timer
    double time_elapsed = ((double)(end_time - start_time)) / CLOCKS_PER_SEC; // Calculate time elapsed in seconds
    double wpm = (((double)correct_count / 5) / time_elapsed) * 60; // Calculate words per minute (assuming an average word length of 5 letters)
    free(sentence); // Free allocated memory
    show_score(wpm); // Show typing speed score
    return 0;
}