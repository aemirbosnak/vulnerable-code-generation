//Falcon2-11B DATASET v1.0 Category: Typing Speed Test ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read words from a file
int read_words(char *filename, int *words, int *words_per_minute) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Failed to open file '%s'\n", filename);
        return -1;
    }

    int word_count = 0;
    int words_read = 0;
    char word[100];
    while (fscanf(file, "%s", word)!= EOF) {
        if (strlen(word) > 0) {
            word_count++;
            words_read++;
        }
    }
    fclose(file);

    *words = word_count;
    *words_per_minute = words_read / 60;

    return 0;
}

// Function to count words per minute
int count_words(char *filename, int words, int words_per_minute) {
    int i = 0;
    int seconds = 0;
    char word[100];
    while (fscanf(filename, "%s", word)!= EOF) {
        if (strlen(word) > 0) {
            words_per_minute += 1;
            seconds++;
        }
    }
    printf("Typing speed: %d words per minute\n", words_per_minute);
    return 0;
}

// Function to calculate and print typing speed
int calculate_speed(char *filename, int words, int words_per_minute) {
    int i = 0;
    int seconds = 0;
    char word[100];
    while (fscanf(filename, "%s", word)!= EOF) {
        if (strlen(word) > 0) {
            words_per_minute += 1;
            seconds++;
        }
    }
    printf("Typing speed: %d words per minute\n", words_per_minute);
    return 0;
}

int main() {
    int words, words_per_minute;
    read_words("words.txt", &words, &words_per_minute);
    count_words("words.txt", words, words_per_minute);
    calculate_speed("words.txt", words, words_per_minute);
    return 0;
}