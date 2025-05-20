#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    Word words[MAX_WORDS] = {0};
    char buffer[MAX_WORD_LENGTH + 1];

    while (fscanf(file, "%s", buffer) == 1) {
        int found = 0;
        for (int i = 0; i < MAX_WORDS && words[i].word[0]; ++i) {
            if (strcmp(words[i].word, buffer) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }
        if (!found && words[MAX_WORDS - 1].word[0]) {
            // Replace the least frequent word
            int min_index = 0;
            for (int i = 1; i < MAX_WORDS; ++i) {
                if (words[i].count < words[min_index].count) {
                    min_index = i;
                }
            }
            strcpy(words[min_index].word, buffer);
            words[min_index].count = 1;
        } else if (!found) {
            strcpy(words[MAX_WORDS - 1].word, buffer);
            words[MAX_WORDS - 1].count = 1;
        }
    }

    fclose(file);

    for (int i = 0; i < MAX_WORDS && words[i].word[0]; ++i) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
