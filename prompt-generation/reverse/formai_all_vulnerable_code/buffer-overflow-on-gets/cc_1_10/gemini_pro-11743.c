//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of words in a string
int count_words(char *str) {
    int count = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            in_word = 0;
        } else if (!in_word) {
            count++;
            in_word = 1;
        }
    }

    return count;
}

// Function to print a progress bar
void print_progress_bar(int progress, int total) {
    float percentage = (float)progress / (float)total * 100.0f;
    int num_bars = (int)(percentage / 10.0f);

    printf("[");
    for (int i = 0; i < num_bars; i++) {
        printf("=");
    }
    for (int i = num_bars; i < 10; i++) {
        printf(" ");
    }
    printf("] %.2f%%\r", percentage);
    fflush(stdout);
}

int main() {
    // Get the input string from the user
    char str[10000];
    printf("Enter a string: ");
    gets(str);

    // Count the number of words in the string
    int word_count = count_words(str);

    // Print the word count
    printf("The number of words in the string is: %d\n", word_count);

    // Print a progress bar
    print_progress_bar(word_count, 100);

    return 0;
}