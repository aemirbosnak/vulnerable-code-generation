//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

int main() {
    int num_words, i, j;
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    double time_elapsed;
    int total_chars, correct_chars;

    // Load words from file
    FILE *fp;
    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    num_words = 0;
    while (fscanf(fp, "%s", words[num_words])!= EOF) {
        num_words++;
    }
    fclose(fp);

    // Shuffle the words
    for (i = 0; i < num_words; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (rand() % 2 == 0) {
                char temp[MAX_WORD_LENGTH];
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }

    // Start the test
    printf("Typing Speed Test\n");
    printf("-----------------\n");
    printf("Press enter to start.\n");
    scanf("%*c");
    clock_t start_time = clock();

    // Display the words one by one
    for (i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
        fflush(stdout);
        usleep(50000); // Pause for 50ms
    }

    // Stop the test
    clock_t end_time = clock();
    time_elapsed = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate accuracy
    total_chars = 0;
    correct_chars = 0;
    for (i = 0; i < num_words; i++) {
        total_chars += strlen(words[i]);
        if (strcmp(words[i], "") == 0) {
            correct_chars += strlen(words[i]);
        }
    }
    printf("\nTest complete.\n");
    printf("Time elapsed: %.2f seconds\n", time_elapsed);
    printf("Number of words: %d\n", num_words);
    printf("Total characters: %d\n", total_chars);
    printf("Correct characters: %d\n", correct_chars);
    printf("Accuracy: %.2f%%\n", 100.0 * correct_chars / total_chars);

    return 0;
}