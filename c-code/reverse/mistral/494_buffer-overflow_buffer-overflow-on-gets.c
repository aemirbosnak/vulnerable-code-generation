#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

void analyzeText(char *input) {
    int i, vowels = 0, consonants = 0, words = 1;

    for (i = 0; i < MAX_INPUT_SIZE && input[i] != '\0'; ++i) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') {
                ++vowels;
            } else {
                ++consonants;
            }
            if (i > 0 && (input[i - 1] == ' ' || input[i - 1] == '\n')) {
                ++words;
            }
        }
    }

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Words: %d\n", words);
}

int main() {
    char input[MAX_INPUT_SIZE];

    printf("Enter text: ");
    gets(input);

    analyzeText(input);

    return 0;
}
