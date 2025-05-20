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
    int freq[26] = {0};
    int max_freq = 0;
    char most_frequent;

    printf("Enter text: ");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            char lower = tolower(input[i]);
            freq[lower - 'a']++;
            if (freq[lower - 'a'] > max_freq) {
                max_freq = freq[lower - 'a'];
                most_frequent = lower;
            }
        }
    }

    printf("Most frequent letter: %c\n", most_frequent);
    printf("Frequency: %d\n", max_freq);

    return 0;
}
