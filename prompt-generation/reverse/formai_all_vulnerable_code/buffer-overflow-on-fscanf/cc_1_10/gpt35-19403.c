//FormAI DATASET v1.0 Category: Word Count Tool ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100 // maximum length of a word

typedef struct {
    char* word;
    int count;
} WordCount;

// helper function to trim white space from beginning and end of string
char* trim(char* string) {
    char* end = string + strlen(string) - 1;
    while (isspace(*string)) {
        string++;
    }
    while (isspace(*end)) {
        end--;
    }
    *(end + 1) = '\0';
    return string;
}

// helper function to compare two word counts for sorting
int compare(const void* a, const void* b) {
    WordCount* w1 = (WordCount*) a;
    WordCount* w2 = (WordCount*) b;
    return w2->count - w1->count;
}

int main(int argc, char* argv[]) {

    if (argc != 2) {
        printf("Usage: wordcount <filename>\n");
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        printf("Unable to open file: %s\n", argv[1]);
        return 1;
    }

    WordCount* wordCounts = (WordCount*) malloc(sizeof(WordCount) * 1000); // assume max 1000 words
    int count = 0;

    char buffer[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", buffer) != EOF) {
        char* word = trim(buffer);
        if (strlen(word) > 0) { // skip empty words
            int found = 0;
            // check if word already exists in wordCounts
            for (int i = 0; i < count; i++) {
                if (strcmp(word, wordCounts[i].word) == 0) {
                    wordCounts[i].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) { // word not found, add to wordCounts
                wordCounts[count].word = (char*) malloc(sizeof(char) * (strlen(word) + 1));
                strcpy(wordCounts[count].word, word);
                wordCounts[count].count = 1;
                count++;
            }
        }
    }

    // sort wordCounts by count in descending order
    qsort(wordCounts, count, sizeof(WordCount), compare);

    // print top 10 words
    printf("Top 10 words:\n");
    for (int i = 0; i < 10 && i < count; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    // free memory
    for (int i = 0; i < count; i++) {
        free(wordCounts[i].word);
    }
    free(wordCounts);

    return 0;
}