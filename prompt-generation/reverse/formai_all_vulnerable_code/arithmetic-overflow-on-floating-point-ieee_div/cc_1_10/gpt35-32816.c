//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: scalable
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 100
#define NUM_SENTENCES 3

const char* sentences[NUM_SENTENCES] = {
    "The quick brown fox jumps over the lazy dog",
    "Sphinx of black quartz, judge my vow",
    "Pack my box with five dozen liquor jugs"
};

int main() {
    int sentence_num, i, j, mistakes=0;
    char typed_sentence[MAX_SENTENCE_LENGTH];
    time_t start_time, end_time;
    double elapsed_time, wpm;
    
    // Get random sentence
    srand(time(NULL));
    sentence_num = rand() % NUM_SENTENCES;
    
    // Get start time
    printf("Type the following sentence and then press Enter:\n\n%s\n", sentences[sentence_num]);
    start_time = time(NULL);
    
    // Get user input
    fgets(typed_sentence, MAX_SENTENCE_LENGTH, stdin);
    typed_sentence[strcspn(typed_sentence, "\r\n")] = '\0'; // Trim newline characters
    
    // Calculate elapsed time
    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);
    
    // Calculate typing speed
    for (i = 0, j = 0; typed_sentence[i] != '\0' && sentences[sentence_num][j] != '\0'; i++, j++) {
        if (typed_sentence[i] != sentences[sentence_num][j]) {
            mistakes++;
        }
    }
    wpm = ((strlen(sentences[sentence_num]) / 5) / (elapsed_time / 60.0)) - (2 * mistakes);
    
    // Display results
    printf("\nElapsed time: %.2f seconds\n", elapsed_time);
    printf("Number of mistakes: %d\n", mistakes);
    printf("Typing speed: %.2f WPM\n", wpm);
    
    return 0;
}