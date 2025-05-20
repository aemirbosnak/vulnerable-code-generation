#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 256
#define MAX_WORDS 1000

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int counts[MAX_WORDS] = {0};
    int word_count = 0;

    while (word_count < MAX_WORDS && fscanf(file, "%s", words[word_count]) != EOF) {
        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(words[i], words[word_count]) == 0) {
                counts[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[word_count], words[word_count]);
            counts[word_count] = 1;
            word_count++;
        }
    }

    fclose(file);

    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i], counts[i]);
    }

    return 0;
}
