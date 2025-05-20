//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100000

typedef struct {
    char word[100];
    int count;
} WordCount;

void read_file(FILE *file, char *filename) {
    char line[1000];
    char word[100];
    WordCount words[MAX_WORDS];
    int num_words = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            strcpy(word, token);
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                strcpy(words[num_words].word, word);
                words[num_words].count = 1;
                num_words++;
                if (num_words >= MAX_WORDS) {
                    break;
                }
            }
            token = strtok(NULL, ",.?!;:");
        }
    }

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    char filename[100];
    strcpy(filename, argv[1]);

    read_file(file, filename);

    fclose(file);
    return 0;
}