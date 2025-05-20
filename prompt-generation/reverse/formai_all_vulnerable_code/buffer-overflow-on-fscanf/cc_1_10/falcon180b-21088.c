//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

int main() {
    int num_words = 0;
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    char input_word[MAX_WORD_LENGTH];
    int i, j, word_length, correct_words = 0;
    double time_taken, wpm;

    // Read words from file
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", input_word)!= EOF) {
        num_words++;
        strcpy(words[num_words - 1], input_word);
    }

    fclose(fp);

    // Shuffle the words
    for (i = 0; i < num_words; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (strcmp(words[j], words[i]) < 0) {
                strcpy(words[j], words[i]);
                strcpy(words[i], words[j]);
            }
        }
    }

    // Start the test
    printf("Enter the words as they appear on the screen.\n");
    printf("Press Enter after each word.\n");
    printf("You have %d words to type.\n", num_words);

    time_taken = 0;
    for (i = 0; i < num_words; i++) {
        word_length = strlen(words[i]);
        correct_words += 1;
        printf("%s ", words[i]);
        fflush(stdout);
        usleep(word_length * 1000000 / 10); // Pause for 1/10th of a second per character
        time_taken += word_length * 1000000 / 10;
    }

    printf("\nTest complete.\n");
    printf("You typed %d words correctly.\n", correct_words);
    printf("Your typing speed is %.2f words per minute.\n", (double) correct_words / (time_taken / 60000));

    return 0;
}