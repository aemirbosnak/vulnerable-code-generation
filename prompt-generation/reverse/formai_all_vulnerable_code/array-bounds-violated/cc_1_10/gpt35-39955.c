//FormAI DATASET v1.0 Category: String manipulation ; Style: thoughtful
#include <stdio.h>
#include <string.h>

/* This program calculates the frequency of each character in a given string
and prints them in descending order of their frequency. */

void sort_freq(int freq[], char chars[], int n) {
    /* Bubble sorting the frequency of characters in descending order */
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (freq[j] < freq[j + 1]) {
                int temp_freq = freq[j];
                freq[j] = freq[j + 1];
                freq[j + 1] = temp_freq;
                char temp_char = chars[j];
                chars[j] = chars[j + 1];
                chars[j + 1] = temp_char;
            }
        }
    }
}

int main() {
    char string[100];
    int frequency[256] = {0};
    char characters[256];

    printf("Enter a string: ");
    fgets(string, 100, stdin);

    /* Calculating frequency of each character */
    int len = strlen(string);
    for (int i = 0; i < len; i++) {
        char c = string[i];
        if (c != '\n') {
            frequency[c]++;
            characters[c] = c;
        }
    }

    sort_freq(frequency, characters, 256);

    /* Printing the result */
    printf("\n==> Frequency of each character in the string:\n");
    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            printf("'%c' appears %d times\n", characters[i], frequency[i]);
        }
    }

    return 0;
}