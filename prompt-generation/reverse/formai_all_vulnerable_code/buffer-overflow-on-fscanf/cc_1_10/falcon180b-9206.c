//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char text[MAX_WORD_LENGTH];
    int length;
};

struct word words[MAX_WORDS];

int main() {
    int num_words, i, j, correct_words = 0;
    char input[MAX_WORD_LENGTH];
    double start_time, end_time, elapsed_time;

    printf("Welcome to the Typing Speed Test!\n");

    // Load words from file
    FILE *file = fopen("words.txt", "r");
    if (!file) {
        printf("Error: unable to open words.txt.\n");
        exit(1);
    }

    num_words = 0;
    while (fscanf(file, "%s", words[num_words].text)!= EOF) {
        words[num_words].length = strlen(words[num_words].text);
        num_words++;
    }

    fclose(file);

    // Shuffle words
    srand(time(NULL));
    for (i = 0; i < num_words; i++) {
        j = rand() % num_words;
        struct word temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }

    // Start timer
    start_time = clock();

    // Test
    for (i = 0; i < num_words; i++) {
        printf("%s\n", words[i].text);
        fgets(input, MAX_WORD_LENGTH, stdin);
        if (strcmp(input, words[i].text) == 0) {
            correct_words++;
        }
    }

    // Stop timer
    end_time = clock();
    elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;

    // Print results
    printf("\nTest complete!\n");
    printf("You typed %d words correctly out of %d.\n", correct_words, num_words);
    printf("Your typing speed is %.2f words per minute.\n", num_words / elapsed_time);

    return 0;
}