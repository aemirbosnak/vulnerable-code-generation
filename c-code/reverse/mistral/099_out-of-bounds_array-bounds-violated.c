#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define ALPHABET_SIZE 26

int main() {
    FILE *file;
    char buffer[BUFFER_SIZE];
    char word[BUFFER_SIZE];
    char *p;
    int word_length;
    int frequencies[ALPHABET_SIZE] = {0};

    file = fopen("input.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(buffer, BUFFER_SIZE, file)) {
        for (p = buffer; *p; p++) {
            if (isalpha(*p)) *p = tolower(*p);
            else if (*p != '\n') *p = '\0';
        }

        word_length = strlen(buffer);
        if (word_length > 0) {
            frequencies[(int)buffer[0] - 'a']++;
            for (int i = 1; i < word_length; i++) {
                frequencies[(int)buffer[i] - 'a']--;
                frequencies[(int)buffer[i] - 'a'] += frequencies[(int)buffer[i - 1] - 'a'];
            }
        }

        memset(word, 0, BUFFER_SIZE);
    }

    fclose(file);

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        printf("%c: %d\n", 'a' + i, frequencies[i]);
    }

    return 0;
}
