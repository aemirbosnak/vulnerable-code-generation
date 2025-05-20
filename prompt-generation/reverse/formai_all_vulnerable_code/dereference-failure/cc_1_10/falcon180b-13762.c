//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 32

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, char *filename) {
    char line[MAX_LINE_LENGTH];
    WordCount words[100];
    int num_words = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                strncpy(words[num_words].word, word, MAX_WORD_LENGTH - 1);
                words[num_words].word[MAX_WORD_LENGTH - 1] = '\0';
                words[num_words].count = 1;
                num_words++;
            }
            word = strtok(NULL, " ");
        }
    }

    fclose(file);
}

void write_report(WordCount *words, int num_words) {
    printf("Word Count Report\n");
    printf("-----------------\n");
    printf("Total words: %d\n", num_words);
    printf("Most common words:\n");
    int max_count = 0;
    for (int i = 0; i < num_words; i++) {
        if (words[i].count > max_count) {
            max_count = words[i].count;
        }
    }
    for (int i = 0; i < num_words; i++) {
        if (words[i].count == max_count) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    char filename[MAX_LINE_LENGTH];
    strcpy(filename, argv[1]);
    WordCount words[100];
    int num_words = 0;

    read_file(file, filename);
    write_report(words, num_words);

    return 0;
}