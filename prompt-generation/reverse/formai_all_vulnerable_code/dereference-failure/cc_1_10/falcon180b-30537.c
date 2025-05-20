//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct {
    char *word;
    int count;
} WordCount;

int main() {
    FILE *file;
    char line[1024];
    char *word;
    WordCount words[MAX_WORDS];
    int num_words = 0;

    file = fopen("cyberpunk.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        word = strtok(line, " ");
        while (word!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                if (num_words >= MAX_WORDS) {
                    printf("Error: Maximum number of words reached.\n");
                    return 1;
                }
                words[num_words].word = strdup(word);
                words[num_words].count = 1;
                num_words++;
            }
            word = strtok(NULL, " ");
        }
    }

    fclose(file);

    printf("Word Count:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    for (int i = 0; i < num_words; i++) {
        free(words[i].word);
    }

    return 0;
}