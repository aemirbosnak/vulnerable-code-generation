//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void count_words(char *file_name, WordCount *word_counts, int num_word_counts)
{
    FILE *file;
    char line[1024];
    char *word;
    int i;

    file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", file_name);
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        word = strtok(line, " \t\n\r\f");
        while (word!= NULL) {
            for (i = 0; i < num_word_counts; i++) {
                if (strcmp(word, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == num_word_counts) {
                if (num_word_counts == MAX_WORD_LENGTH) {
                    printf("Error: Too many words\n");
                    exit(1);
                }
                strcpy(word_counts[num_word_counts].word, word);
                word_counts[num_word_counts].count = 1;
                num_word_counts++;
            }
            word = strtok(NULL, " \t\n\r\f");
        }
    }

    fclose(file);
}

void print_word_counts(WordCount *word_counts, int num_word_counts)
{
    int i;

    for (i = 0; i < num_word_counts; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[])
{
    WordCount word_counts[MAX_WORD_LENGTH];
    int num_word_counts = 0;

    if (argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        exit(1);
    }

    while (num_word_counts < MAX_WORD_LENGTH) {
        printf("Enter word to count: ");
        scanf("%s", word_counts[num_word_counts].word);
        num_word_counts++;
    }

    count_words(argv[1], word_counts, num_word_counts);
    print_word_counts(word_counts, num_word_counts);

    return 0;
}