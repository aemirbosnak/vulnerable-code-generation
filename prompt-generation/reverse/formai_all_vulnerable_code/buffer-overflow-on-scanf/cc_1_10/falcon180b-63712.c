//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *ebook_file;
    char ebook_filename[100];
    char line[1000];

    printf("Enter the name of the ebook file: ");
    scanf("%s", ebook_filename);

    ebook_file = fopen(ebook_filename, "r");
    if (ebook_file == NULL) {
        printf("Error: could not open ebook file.\n");
        return 1;
    }

    int word_count = 0;
    WordCount words[MAX_WORDS];

    char *word = strtok(line, " ");
    while (word!= NULL) {
        if (word_count >= MAX_WORDS) {
            printf("Error: maximum number of words reached.\n");
            return 1;
        }

        strcpy(words[word_count].word, word);
        words[word_count].count = 1;
        word_count++;

        char *next_word = strtok(NULL, " ");
        if (next_word == NULL) {
            break;
        }
        word = next_word;
    }

    fclose(ebook_file);

    int max_word_length = 0;

    for (int i = 0; i < word_count; i++) {
        int word_length = strlen(words[i].word);
        if (word_length > max_word_length) {
            max_word_length = word_length;
        }
    }

    printf("Enter the number of words to display: ");
    scanf("%d", &word_count);

    for (int i = 0; i < word_count && i < MAX_WORDS; i++) {
        printf("%-*s %d\n", max_word_length, words[i].word, words[i].count);
    }

    return 0;
}