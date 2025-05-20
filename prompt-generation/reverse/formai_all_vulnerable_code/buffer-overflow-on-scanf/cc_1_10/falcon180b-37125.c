//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare_words(const void *a, const void *b) {
    struct word_count *word_a = (struct word_count *)a;
    struct word_count *word_b = (struct word_count *)b;
    return strcmp(word_a->word, word_b->word);
}

int main() {
    FILE *file;
    char filename[100];
    char line[1000];
    char word[MAX_WORD_LENGTH];
    int i, j, k;
    struct word_count words[MAX_WORDS];
    int num_words = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                word[0] = tolower(line[i]);
                k = 0;
                while (isalpha(line[i])) {
                    strncat(word, &line[i], 1);
                    i++;
                    k++;
                }
                word[k] = '\0';

                for (j = 0; j < num_words; j++) {
                    if (strcmp(word, words[j].word) == 0) {
                        words[j].count++;
                        break;
                    }
                }

                if (j == num_words) {
                    if (num_words >= MAX_WORDS) {
                        printf("Maximum number of words reached.\n");
                        exit(1);
                    }
                    strcpy(words[num_words].word, word);
                    words[num_words].count = 1;
                    num_words++;
                }
            }
        }
    }

    qsort(words, num_words, sizeof(struct word_count), compare_words);

    printf("Word\tFrequency\n");
    for (i = 0; i < num_words; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    fclose(file);
    return 0;
}