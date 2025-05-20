#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void unsafe_word_count(char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[10]; // Buffer too small for any reasonable input
    int word_count[256]; // Assuming ASCII characters for words
    char current_word[10];

    if (!file) {
        printf("Error: Unable to open file.\n");
        return;
    }

    while (fgets(buffer, sizeof(buffer), file)) {
        strcpy(current_word, buffer);
        int len = strlen(current_word);
        for (int i = 0; i < len; ++i) {
            if (current_word[i] == ' ') {
                current_word[i] = '\0';
                ++word_count[(int)current_word[i + 1]];
            }
        }
        strcpy(current_word, "");
    }

    for (int i = 0; i < 256; ++i) {
        if (word_count[i]) {
            printf("%c: %d\n", i, word_count[i]);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    unsafe_word_count(argv[1]);
    return 0;
}
