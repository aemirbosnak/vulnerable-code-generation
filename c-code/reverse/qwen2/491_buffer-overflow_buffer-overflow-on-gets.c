#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

void findMostFrequentLetter(char *input) {
    int frequency[26] = {0};
    int maxFrequency = 0;
    char mostFrequentLetter = '\0';

    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            input[i] = tolower(input[i]);
            frequency[input[i] - 'a']++;
            if (frequency[input[i] - 'a'] > maxFrequency) {
                maxFrequency = frequency[input[i] - 'a'];
                mostFrequentLetter = input[i];
            }
        }
    }

    printf("The most frequent letter is '%c' with %d occurrences.\n", mostFrequentLetter, maxFrequency);
}

int main() {
    char input[MAX_INPUT_SIZE];

    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    findMostFrequentLetter(input);

    return 0;
}
