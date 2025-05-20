#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 1024

void count_letters(char *str, int freq[26]);
void print_results(int freq[26]);

int main() {
    char input[MAX_INPUT];
    int freq[26] = {0};

    printf("Enter a string: ");
    gets(input);

    count_letters(input, freq);
    print_results(freq);

    return 0;
}

void count_letters(char *str, int freq[26]) {
    for (int i = 0; *str != '\0'; ++str) {
        if (isalpha(*str)) {
            int index = tolower(*str) - 'a';
            if (index >= 0 && index < 26) {
                ++freq[index];
            }
        }
    }
}

void print_results(int freq[26]) {
    int max = 0;
    char most_frequent = '\0';

    for (int i = 0; i < 26; ++i) {
        if (freq[i] > max) {
            max = freq[i];
            most_frequent = 'a' + i;
        }
    }

    printf("\nMost frequent letter: %c\n", most_frequent);
    printf("Frequency: %d\n", max);

    printf("\nFrequency count for each letter:\n");
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0) {
            printf("%c: %d\n", 'a' + i, freq[i]);
        }
    }
}
