//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 1000
#define MAX_WORD_COUNT 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    WordCount *word1 = (WordCount *) a;
    WordCount *word2 = (WordCount *) b;
    return strcmp(word1->word, word2->word);
}

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    WordCount word_counts[MAX_WORD_COUNT];
    int word_count = 0;

    printf("Enter file name: ");
    scanf("%s", line);

    file = fopen(line, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char *token = strtok(line, " \t\n\r\f\v.,!?;:\"'");
        while (token!= NULL) {
            strcpy(word, token);
            int i = 0;
            while (i < strlen(word)) {
                if (!isalpha(word[i])) {
                    word[i] = '\0';
                }
                i++;
            }
            for (int j = 0; j < word_count; j++) {
                if (strcmp(word_counts[j].word, word) == 0) {
                    word_counts[j].count++;
                    break;
                }
            }
            if (word_count == MAX_WORD_COUNT) {
                printf("Error: maximum word count reached.\n");
                return 1;
            }
            strcpy(word_counts[word_count].word, word);
            word_counts[word_count].count = 1;
            word_count++;
            token = strtok(NULL, " \t\n\r\f\v.,!?;:\"'");
        }
    }

    qsort(word_counts, word_count, sizeof(WordCount), compare);

    printf("Word\tCount\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s\t%d\n", word_counts[i].word, word_counts[i].count);
    }

    fclose(file);
    return 0;
}