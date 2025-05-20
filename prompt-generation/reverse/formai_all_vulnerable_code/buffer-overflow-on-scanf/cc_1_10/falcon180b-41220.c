//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: scalable
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

void process_line(char *line, struct word_count *word_counts) {
    char *word = strtok(line, ",.?!;:\"'");
    while (word!= NULL) {
        int len = strlen(word);
        if (len > 0 && len <= MAX_WORD_LENGTH) {
            word[len-1] = '\0'; // remove punctuation
            for (int i = 0; i < len; i++) {
                word[i] = tolower(word[i]);
            }
            struct word_count *wc = NULL;
            for (int i = 0; i < MAX_WORDS; i++) {
                if (strcmp(word_counts[i].word, word) == 0) {
                    wc = &word_counts[i];
                    break;
                }
            }
            if (wc == NULL) {
                if (word_counts[MAX_WORDS-1].word[0]!= '\0') {
                    printf("Error: maximum number of words reached\n");
                    exit(1);
                }
                strcpy(wc->word, word);
                wc->count = 1;
            } else {
                wc->count++;
            }
        }
        word = strtok(NULL, ",.?!;:\"'");
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    struct word_count word_counts[MAX_WORDS];
    for (int i = 0; i < MAX_WORDS; i++) {
        word_counts[i].word[0] = '\0';
    }

    char line[10000];
    while (fgets(line, sizeof(line), file)!= NULL) {
        process_line(line, word_counts);
    }

    fclose(file);

    printf("Word\tCount\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        if (word_counts[i].word[0]!= '\0') {
            printf("%s\t%d\n", word_counts[i].word, word_counts[i].count);
        }
    }

    return 0;
}