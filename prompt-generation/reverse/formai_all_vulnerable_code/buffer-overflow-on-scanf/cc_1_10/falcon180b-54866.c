//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main() {
    char input[1000];
    int length = 0, correct = 0, incorrect = 0, words_typed = 0, wpm = 0;
    double avg_wpm = 0;
    FILE *file;
    char filename[100];

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Start timer
    time_t start_time = time(NULL);

    // Read file and count words
    while (fgets(input, sizeof(input), file)!= NULL) {
        length += strlen(input);
        words_typed += count_words(input);
    }

    // Calculate WPM
    avg_wpm = (double)words_typed / ((double)(time(NULL) - start_time) / 60);

    // Print results
    printf("Words typed: %d\n", words_typed);
    printf("Correct words: %d\n", correct);
    printf("Incorrect words: %d\n", incorrect);
    printf("WPM: %.2f\n", avg_wpm);

    return 0;
}

int count_words(char *input) {
    int count = 0;
    int word_length = 0;
    int in_word = 0;

    for (int i = 0; input[i]!= '\0'; i++) {
        if (isspace(input[i])) {
            if (in_word) {
                count++;
                in_word = 0;
            }
        } else {
            in_word = 1;
            word_length++;
        }
    }

    if (in_word) {
        count++;
    }

    return count;
}