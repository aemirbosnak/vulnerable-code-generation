#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>

int main() {
    char input[1000];
    int frequency[26] = {0};
    int maxFrequency = 0;
    char mostFrequentLetter;

    printf("Enter text: ");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; input[i]; i++) {
        if (isalpha(input[i])) {
            input[i] = tolower(input[i]);
            frequency[input[i] - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (frequency[i] > maxFrequency) {
            maxFrequency = frequency[i];
            mostFrequentLetter = i + 'a';
        }
    }

    printf("Most frequent letter: %c\n", mostFrequentLetter);
    printf("Count: %d\n", maxFrequency);

    return 0;
}
