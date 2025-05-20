//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_LINE_LEN 1000
#define MAX_FILE_NAME 100
#define MAX_WORD_COUNT 10000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int main(int argc, char **argv) {
    FILE *file;
    char line[MAX_LINE_LEN];
    char filename[MAX_FILE_NAME];
    char word[MAX_WORD_LEN];
    WordCount word_count[MAX_WORD_COUNT];
    int num_words = 0;
    int i;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    strcpy(filename, argv[1]);
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(2);
    }

    while (fgets(line, MAX_LINE_LEN, file)!= NULL) {
        char *c = line;
        while (*c!= '\0') {
            if (isspace(*c)) {
                *c = '\0';
            }
            c++;
        }

        if (strlen(line) == 0) {
            continue;
        }

        char *word_start = line;
        while (isalnum(*word_start)) {
            strcpy(word, word_start);
            word_start += strlen(word);

            if (num_words == MAX_WORD_COUNT) {
                printf("Error: maximum number of words reached (%d)\n", num_words);
                exit(3);
            }

            for (i = 0; i < num_words; i++) {
                if (strcmp(word, word_count[i].word) == 0) {
                    word_count[i].count++;
                    break;
                }
            }

            if (i == num_words) {
                strcpy(word_count[num_words].word, word);
                word_count[num_words].count = 1;
                num_words++;
            }
        }
    }

    fclose(file);

    printf("Word count:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_count[i].word, word_count[i].count);
    }

    return 0;
}