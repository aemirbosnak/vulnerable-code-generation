#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int main() {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    char word[MAX_WORD_LENGTH];
    int frequencies[100] = {0};
    int count = 0;

    while (fscanf(file, "%s", word) != EOF) {
        for (int i = 0; i < count; i++) {
            if (strcmp(word, word[i]) == 0) {
                frequencies[i]++;
                goto next_word;
            }
        }
        strcpy(word[count], word);
        frequencies[count]++;
        count++;
next_word:
        ;
    }

    fclose(file);

    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", word[i], frequencies[i]);
    }

    return EXIT_SUCCESS;
}
