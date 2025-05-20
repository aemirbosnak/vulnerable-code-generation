//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, char *filename) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            if (i >= MAX_WORD_LENGTH) {
                printf("Error: Word '%s' is too long.\n", filename);
                exit(1);
            }
            strncat(filename + strlen(filename), &ch, 1);
            i++;
        }
    }
}

void count_words(char *filename, WordCount *word_counts, int num_words) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File '%s' not found.\n", filename);
        exit(1);
    }
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            if (i >= MAX_WORD_LENGTH) {
                printf("Error: Word '%s' is too long.\n", filename);
                exit(1);
            }
            strncat(filename + strlen(filename), &ch, 1);
            i++;
        } else if (i > 0) {
            filename[i] = '\0';
            for (int j = 0; j < num_words; j++) {
                if (strcmp(word_counts[j].word, filename) == 0) {
                    word_counts[j].count++;
                    break;
                }
            }
        }
        i = 0;
    }
    fclose(file);
}

void print_word_counts(WordCount *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    char filename[MAX_WORD_LENGTH];
    WordCount word_counts[MAX_WORDS];
    int num_words = 0;

    // Read the file name from the user
    printf("Enter the file name: ");
    scanf("%s", filename);

    // Count the number of words in the file
    count_words(filename, word_counts, num_words);

    // Print the word counts
    printf("Word counts:\n");
    print_word_counts(word_counts, num_words);

    return 0;
}