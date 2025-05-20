//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int main() {
    FILE *input_file;
    char line[MAX_WORD_LEN];
    char *word;
    char *saveptr;
    WordCount word_counts[MAX_WORDS];
    int num_words = 0;

    input_file = fopen("movie_reviews.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LEN, input_file)!= NULL) {
        word = strtok_r(line, " \t\n\r", &saveptr);
        while (word!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Error: Too many unique words.\n");
                fclose(input_file);
                return 1;
            }
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                strcpy(word_counts[num_words].word, word);
                word_counts[num_words].count = 1;
                num_words++;
            }
            word = strtok_r(NULL, " \t\n\r", &saveptr);
        }
    }

    fclose(input_file);

    int total_words = 0;
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        total_words += word_counts[i].count;
    }

    printf("\nTotal words: %d\n", total_words);

    return 0;
}