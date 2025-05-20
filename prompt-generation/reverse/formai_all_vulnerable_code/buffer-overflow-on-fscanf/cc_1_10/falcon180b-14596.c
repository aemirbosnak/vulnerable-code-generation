//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *file;
    char input[MAX_WORD_LENGTH];
    char *filename = argv[1];
    int num_words = 0;
    WordCount words[MAX_WORDS] = {0};
    int i;

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    // Read in file contents
    while (fscanf(file, "%s", input)!= EOF) {
        input[strcspn(input, "\n")] = '\0'; // Remove newline character from end of input
        num_words++;
        if (num_words > MAX_WORDS) {
            printf("Error: too many words in file\n");
            exit(1);
        }
        strcpy(words[num_words - 1].word, input);
        words[num_words - 1].count = 1;
    }

    fclose(file);

    // Sort words alphabetically
    for (i = 0; i < num_words - 1; i++) {
        int j;
        for (j = i + 1; j < num_words; j++) {
            if (strcmp(words[i].word, words[j].word) > 0) {
                WordCount temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Print word counts
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}