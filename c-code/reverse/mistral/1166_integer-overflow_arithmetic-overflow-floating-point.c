#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define WORD_SIZE 256

int main() {
    char buffer[BUFFER_SIZE];
    char words[WORD_SIZE][WORD_SIZE];
    int word_count = 0, char_count = 0, special_count = 0, i, j, k;
    double avg_word_length;

    while (fgets(buffer, BUFFER_SIZE, stdin)) {
        char_count += strlen(buffer);
        for (i = 0; buffer[i]; ++i) {
            if (!isalnum(buffer[i]) && buffer[i] != '\n')
                ++special_count;
            if (i > 0 && !isalnum(buffer[i - 1]) && isalnum(buffer[i]) && buffer[i] != '\n') {
                words[word_count][k++] = buffer[i];
                if (k >= WORD_SIZE) {
                    word_count++;
                    k = 0;
                }
            }
        }
        if (k > 0) {
            words[word_count][k] = '\0';
            word_count++;
            k = 0;
        }
    }

    avg_word_length = (double)word_count > 0 ? (double)char_count / word_count : 0;

    printf("Word count: %d\n", word_count);
    printf("Character count: %d\n", char_count);
    printf("Special character count: %d\n", special_count);
    printf("Average word length: %.2f\n", avg_word_length);

    return 0;
}
