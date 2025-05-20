//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compareWords(const void *a, const void *b) {
    struct Word *wordA = (struct Word *) a;
    struct Word *wordB = (struct Word *) b;

    return strcmp(wordA->word, wordB->word);
}

void readResume(char *filename, struct Word *words) {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char *token;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        token = strtok(line, " ");
        while (token!= NULL) {
            int i;
            for (i = 0; i < MAX_NUM_WORDS; i++) {
                if (strcmp(words[i].word, token) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == MAX_NUM_WORDS) {
                if (strcmp(token, "the")!= 0 && strcmp(token, "and")!= 0 && strcmp(token, "a")!= 0 && strcmp(token, "an")!= 0) {
                    strcpy(words[i].word, token);
                    words[i].count = 1;
                }
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(file);
}

void printWords(struct Word *words) {
    int i;

    qsort(words, MAX_NUM_WORDS, sizeof(struct Word), compareWords);

    for (i = 0; i < MAX_NUM_WORDS; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    char filename[MAX_WORD_LENGTH];
    struct Word words[MAX_NUM_WORDS];

    printf("Enter the name of the resume file: ");
    scanf("%s", filename);

    readResume(filename, words);
    printWords(words);

    return 0;
}