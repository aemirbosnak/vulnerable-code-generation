#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *input = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Enter text: ");
    if ((read = getline(&input, &len, stdin)) != -1) {
        int freq[26] = {0};
        for (size_t i = 0; i < read; i++) {
            if (input[i] >= 'a' && input[i] <= 'z') {
                freq[input[i] - 'a']++;
            } else if (input[i] >= 'A' && input[i] <= 'Z') {
                freq[input[i] - 'A']++;
            }
        }

        int max_freq = 0;
        char most_frequent = '\0';
        for (int i = 0; i < 26; i++) {
            if (freq[i] > max_freq) {
                max_freq = freq[i];
                most_frequent = i + 'a';
            }
        }

        printf("Most frequent letter: %c\n", most_frequent);
    }

    free(input);
    return 0;
}
