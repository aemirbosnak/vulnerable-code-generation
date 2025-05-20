#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define MAX_WORD_LENGTH 256

void translate_word(char *word) {
    if (word[0] == 'a') {
        word[0] = 'b';
    }
}

int main() {
    FILE *file;
    char word[MAX_WORD_LENGTH];

    file = fopen("words.txt", "r");
    if (file == NULL) {
        return 1;
    }

    while (fscanf(file, "%s", word) != EOF) {
        translate_word(word);
        printf("%s\n", word);
    }

    fclose(file);
    return 0;
}
