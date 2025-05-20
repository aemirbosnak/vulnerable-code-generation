//Falcon-180B DATASET v1.0 Category: Data mining ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50
#define MIN_WORD_LENGTH 2

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    WordCount *word1 = (WordCount *)a;
    WordCount *word2 = (WordCount *)b;
    return strcmp(word1->word, word2->word);
}

void read_file(FILE *file, char *filename) {
    char ch;
    int in_word = 0;
    int word_length = 0;
    char word[MAX_WORD_LENGTH];

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            if (!in_word) {
                in_word = 1;
                word[0] = tolower(ch);
                word_length = 1;
            } else {
                strcat(word, &ch);
                word_length++;
            }
        } else {
            in_word = 0;
            if (word_length >= MIN_WORD_LENGTH) {
                WordCount *word_count = malloc(sizeof(WordCount));
                strcpy(word_count->word, word);
                word_count->count = 1;
                hsearch(word_count, compare);
            }
            word_length = 0;
        }
    }

    if (in_word && word_length >= MIN_WORD_LENGTH) {
        WordCount *word_count = malloc(sizeof(WordCount));
        strcpy(word_count->word, word);
        word_count->count = 1;
        hsearch(word_count, compare);
    }
}

void print_word_counts(void *key, size_t ksize, void *value, size_t vsize) {
    WordCount *word_count = (WordCount *)value;
    printf("%s: %d\n", word_count->word, word_count->count);
}

int main() {
    time_t start_time, end_time;
    double elapsed_time;
    FILE *file;
    char filename[100];

    printf("Enter filename: ");
    scanf("%s", filename);

    start_time = time(NULL);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    read_file(file, filename);
    fclose(file);

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);
    printf("Time elapsed: %.2f seconds\n", elapsed_time);

    return 0;
}