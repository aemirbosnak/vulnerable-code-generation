#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int frequency;
} Word;

void bubbleSort(Word words[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (strcmp(words[j].word, words[j+1].word) > 0) {
                Word temp = words[j];
                words[j] = words[j+1];
                words[j+1] = temp;
            }
        }
    }
}

int main() {
    FILE *file;
    char filename[] = "input.txt";
    Word words[MAX_WORDS];
    int count = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " ");
        while (token != NULL) {
            int found = 0;
            for (int i = 0; i < count; i++) {
                if (strcmp(words[i].word, token) == 0) {
                    words[i].frequency++;
                    found = 1;
                    break;
                }
            }
            if (!found && count < MAX_WORDS) {
                strcpy(words[count].word, token);
                words[count].frequency = 1;
                count++;
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(file);

    bubbleSort(words, count);

    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    return EXIT_SUCCESS;
}
