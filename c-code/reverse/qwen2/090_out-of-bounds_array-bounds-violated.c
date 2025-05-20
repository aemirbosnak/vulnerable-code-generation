#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

int main() {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    int count[MAX_WORDS] = {0};
    int word_count = 0;

    file = fopen("words.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (fscanf(file, "%s", word) != EOF) {
        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(word, word[i]) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }
        if (!found && word_count < MAX_WORDS) {
            strcpy(word[word_count], word);
            count[word_count]++;
            word_count++;
        }
    }

    fclose(file);

    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", word[i], count[i]);
    }

    return EXIT_SUCCESS;
}
