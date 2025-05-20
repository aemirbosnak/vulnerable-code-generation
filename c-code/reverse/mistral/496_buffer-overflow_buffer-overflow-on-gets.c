#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 256

int main() {
    char input[MAX_INPUT];
    char *words[MAX_INPUT];
    int word_count = 0, max_count = 0, current_letter, i, j;
    char most_frequent_letter;

    printf("Enter text: ");
    gets(input);

    for (i = 0; input[i] != '\0'; ++i) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            current_letter = input[i] - 'a';
            words[word_count][0] = input[i];
            ++word_count;
            words[word_count] = malloc((word_count + 1) * sizeof(char));
        }
        for (j = 0; j < word_count; ++j) {
            if (words[j][0] == input[i]) {
                words[j][word_count - j] = input[i];
                words[j][word_count - j + 1] = '\0';
                ++*(words[j] + word_count - j + 1);
                break;
            }
        }
    }

    for (i = 0; i < word_count; ++i) {
        if (*(words[i] + 1) > max_count) {
            max_count = *(words[i] + 1);
            most_frequent_letter = 'a' + i;
        }
    }

    printf("Most frequent letter: %c, count: %d\n", most_frequent_letter, max_count);

    for (i = 0; i < word_count; ++i) {
        free(words[i]);
    }

    return 0;
}
