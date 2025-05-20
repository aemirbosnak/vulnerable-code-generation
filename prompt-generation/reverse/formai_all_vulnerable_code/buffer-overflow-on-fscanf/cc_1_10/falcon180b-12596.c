//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    char buffer[MAX_WORD_LENGTH];
    WordFrequency words[MAX_WORDS];
    int num_words = 0;

    while (fscanf(file, "%s", buffer)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Maximum number of words reached: %d\n", MAX_WORDS);
            break;
        }

        char *word = strtok(buffer, " ");
        while (word!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].frequency++;
                    break;
                }
            }

            if (i == num_words) {
                strcpy(words[num_words].word, word);
                words[num_words].frequency = 1;
                num_words++;
            }

            word = strtok(NULL, " ");
        }
    }

    fclose(file);

    printf("Word\tFrequency\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", words[i].word, words[i].frequency);
    }

    return 0;
}