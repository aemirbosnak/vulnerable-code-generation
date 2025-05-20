#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_WORDS 50
#define MAX_WORD_LENGTH 50

int main() {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    int count[MAX_WORDS] = {0};
    int word_count = 0;

    file = fopen("words.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fscanf(file, "%s", word) != EOF && word_count < MAX_WORDS) {
        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(word, word[i]) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(word[word_count], word);
            count[word_count]++;
            word_count++;
        }
    }

    fclose(file);

    printf("Word Frequencies:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", word[i], count[i]);
    }

    return 0;
}
