//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_log_file(char *filename, struct word_count *word_counts, int num_words) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open log file %s\n", filename);
        exit(1);
    }

    char line[MAX_LOG_SIZE];
    while (fgets(line, MAX_LOG_SIZE, fp)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(token, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                printf("Error: too many unique words in log file\n");
                exit(1);
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(fp);
}

void print_word_counts(struct word_count *word_counts, int num_words) {
    printf("Word\tCount\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    int num_words = 10;
    char words[num_words][MAX_WORD_LENGTH];
    int i;

    printf("Enter %d words to count in log file:\n", num_words);
    for (i = 0; i < num_words; i++) {
        printf("Word %d: ", i+1);
        scanf("%s", words[i]);
    }

    struct word_count word_counts[num_words];
    for (i = 0; i < num_words; i++) {
        strcpy(word_counts[i].word, words[i]);
        word_counts[i].count = 0;
    }

    char log_filename[MAX_LOG_SIZE];
    printf("Enter log file name: ");
    scanf("%s", log_filename);

    read_log_file(log_filename, word_counts, num_words);

    print_word_counts(word_counts, num_words);

    return 0;
}