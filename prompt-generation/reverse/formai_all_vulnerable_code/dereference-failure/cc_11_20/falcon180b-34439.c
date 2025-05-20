//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    WordCount word_counts[MAX_WORDS];
    int num_words = 0;
    int i, j;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        i = 0;
        while (i < strlen(line)) {
            if (isalpha(line[i])) {
                j = 0;
                while (j < MAX_WORD_LENGTH && isalpha(line[i])) {
                    word[j] = tolower(line[i]);
                    i++;
                    j++;
                }
                word[j] = '\0';
                for (j = 0; j < num_words; j++) {
                    if (strcmp(word_counts[j].word, word) == 0) {
                        word_counts[j].count++;
                        break;
                    }
                }
                if (j == num_words) {
                    if (num_words >= MAX_WORDS) {
                        printf("Error: too many unique words\n");
                        fclose(file);
                        return 1;
                    }
                    strcpy(word_counts[num_words].word, word);
                    word_counts[num_words].count = 1;
                    num_words++;
                }
            } else {
                i++;
            }
        }
    }

    fclose(file);

    printf("Word counts:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    return 0;
}