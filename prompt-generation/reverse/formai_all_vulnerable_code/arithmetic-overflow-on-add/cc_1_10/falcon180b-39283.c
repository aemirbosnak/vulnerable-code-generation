//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void process_line(char* line, struct word_count words[MAX_WORDS]) {
    char* word = strtok(line, " ");
    while (word!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == MAX_WORDS) {
            strcpy(words[MAX_WORDS - 1].word, word);
            words[MAX_WORDS - 1].count = 1;
        }
        word = strtok(NULL, " ");
    }
}

void print_word_counts(struct word_count words[MAX_WORDS]) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE* file;
    char line[1000];
    struct word_count words[MAX_WORDS];

    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int i = 0;
    while (fgets(line, sizeof(line), file)!= NULL) {
        process_line(line, words);
        i++;
        if (i == MAX_WORDS) {
            break;
        }
    }

    fclose(file);

    printf("Word counts:\n");
    print_word_counts(words);

    return 0;
}