//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char* word;
    int count;
} WordCount;

void print_word_counts(WordCount* counts, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", counts[i].word, counts[i].count);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    WordCount counts[MAX_WORD_LENGTH];
    int count = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char* word = strtok(line, " ");
        while (word!= NULL) {
            int i;
            for (i = 0; i < count; i++) {
                if (strcmp(word, counts[i].word) == 0) {
                    counts[i].count++;
                    break;
                }
            }
            if (i == count) {
                if (count >= MAX_WORD_LENGTH) {
                    printf("Error: Too many unique words\n");
                    return 1;
                }
                counts[count].word = strdup(word);
                counts[count].count = 1;
                count++;
            }
            word = strtok(NULL, " ");
        }
    }

    print_word_counts(counts, count);

    fclose(file);
    return 0;
}