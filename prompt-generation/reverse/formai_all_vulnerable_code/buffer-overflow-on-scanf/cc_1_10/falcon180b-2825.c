//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_SIZE 1000000 // Maximum size of the log file
#define MAX_WORD_LENGTH 50 // Maximum length of a word

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void init_word_count(WordCount* wc) {
    memset(wc, 0, sizeof(WordCount));
}

int compare_word_count(const void* a, const void* b) {
    const WordCount* wc1 = a;
    const WordCount* wc2 = b;
    return strcmp(wc1->word, wc2->word);
}

int main() {
    FILE* fp;
    char log_file[100];
    char line[MAX_LOG_SIZE];
    WordCount word_counts[100];
    int num_words = 0;

    printf("Enter the name of the log file: ");
    scanf("%s", log_file);

    fp = fopen(log_file, "r");
    if (fp == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    while (fgets(line, MAX_LOG_SIZE, fp)!= NULL) {
        char* word = strtok(line, " ");
        while (word!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                if (num_words >= 100) {
                    printf("Error: Too many unique words.\n");
                    fclose(fp);
                    return 1;
                }
                init_word_count(&word_counts[num_words]);
                strcpy(word_counts[num_words].word, word);
                num_words++;
            }
            word = strtok(NULL, " ");
        }
    }

    fclose(fp);

    qsort(word_counts, num_words, sizeof(WordCount), compare_word_count);

    printf("Word Count:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    return 0;
}