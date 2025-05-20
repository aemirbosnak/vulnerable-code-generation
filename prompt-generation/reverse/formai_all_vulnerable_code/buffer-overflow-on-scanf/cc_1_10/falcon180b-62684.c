//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_words(FILE *file, struct word_count *words) {
    char line[100];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            int len = strlen(word);
            if (len < MAX_WORD_LENGTH) {
                strcpy(words->word, word);
                words->count++;
            }
            word = strtok(NULL, ",.?!;:");
        }
    }
}

int compare_words(const void *a, const void *b) {
    return strcmp(((struct word_count *)a)->word, ((struct word_count *)b)->word);
}

int main() {
    FILE *file;
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    struct word_count words[MAX_WORDS];
    int num_words = 0;
    read_words(file, words);
    fclose(file);
    qsort(words, num_words, sizeof(struct word_count), compare_words);
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
    return 0;
}