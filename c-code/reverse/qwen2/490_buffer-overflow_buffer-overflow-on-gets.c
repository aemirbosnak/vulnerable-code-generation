#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1024

int main() {
    char input[MAX_INPUT_SIZE];
    int frequency[26] = {0};
    int max_frequency = 0;
    char most_frequent_letter = '\0';

    printf("Enter text: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            char lower_input = tolower(input[i]);
            frequency[lower_input - 'a']++;
            if (frequency[lower_input - 'a'] > max_frequency) {
                max_frequency = frequency[lower_input - 'a'];
                most_frequent_letter = lower_input;
            }
        }
    }

    printf("Frequency of each letter:\n");
    for (int i = 0; i < 26; i++) {
        if (frequency[i] > 0) {
            printf("%c: %d\n", 'a' + i, frequency[i]);
        }
    }

    if (most_frequent_letter != '\0') {
        printf("Most frequent letter: %c with %d occurrences\n", most_frequent_letter, max_frequency);
    } else {
        printf("No letters found in input.\n");
    }

    return 0;
}
