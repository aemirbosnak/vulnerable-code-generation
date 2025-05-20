//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare_words(const void *a, const void *b) {
    struct word_count *wc1 = (struct word_count *)a;
    struct word_count *wc2 = (struct word_count *)b;

    return strcmp(wc1->word, wc2->word);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[1024];
    char *word;
    int word_count = 0;
    struct word_count *word_list = (struct word_count *)malloc(MAX_WORDS * sizeof(struct word_count));

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            int i;

            for (i = 0; i < strlen(word); i++) {
                if (!isalpha(word[i])) {
                    word[i] = '\0';
                }
            }

            if (word_count >= MAX_WORDS) {
                printf("Maximum number of words (%d) reached.\n", MAX_WORDS);
                exit(1);
            }

            strcpy(word_list[word_count].word, word);
            word_list[word_count].count = 1;
            word_count++;

            word = strtok(NULL, ",.?!;:");
        }
    }

    qsort(word_list, word_count, sizeof(struct word_count), compare_words);

    printf("Word\tCount\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s\t%d\n", word_list[i].word, word_list[i].count);
    }

    free(word_list);
    fclose(file);

    return 0;
}