//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORDS_PER_MINUTE 200
#define MIN_WPM 20
#define MAX_WPM 80
#define MAX_WORDS 50
#define MAX_TIME 60

int main() {
    int i, j, correct = 0;
    int total_words = 0;
    int wpm = 0;
    int start_time, end_time;
    char *words[MAX_WORDS];
    int word_lengths[MAX_WORDS];

    srand(time(NULL));

    // Load words from file
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error loading words\n");
        exit(1);
    }

    for (i = 0; i < MAX_WORDS; i++) {
        char buffer[50];
        fscanf(file, "%s", buffer);
        words[i] = strdup(buffer);
        word_lengths[i] = strlen(buffer);
        total_words += word_lengths[i];
    }

    fclose(file);

    // Shuffle words
    for (i = 0; i < total_words; i++) {
        int rand_index = rand() % total_words;
        char *temp = words[i];
        words[i] = words[rand_index];
        words[rand_index] = temp;
    }

    // Start timer
    start_time = clock();

    // Main loop
    for (i = 0; i < total_words; i++) {
        printf("%s ", words[i]);
        for (j = 0; j < word_lengths[i]; j++) {
            char c = getchar();
            if (c == words[i][j]) {
                correct++;
            }
        }
    }

    // Stop timer
    end_time = clock();

    // Calculate WPM
    wpm = (int) (total_words / (double) (end_time - start_time) * CLOCKS_PER_SEC);

    printf("\nYou typed %d words correctly out of %d\n", correct, total_words);
    if (wpm >= MIN_WPM && wpm <= MAX_WPM) {
        printf("Your typing speed is %d WPM\n", wpm);
    } else {
        printf("Your typing speed is too slow or too fast\n");
    }

    return 0;
}