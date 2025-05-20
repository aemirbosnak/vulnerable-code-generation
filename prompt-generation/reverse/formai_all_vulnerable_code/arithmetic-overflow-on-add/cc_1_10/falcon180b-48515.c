//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readFile(FILE* file, WordCount words[MAX_WORDS]) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = tolower(ch);
            int j = 1;
            while ((ch = fgetc(file))!= EOF && isalnum(ch)) {
                words[i].word[j++] = tolower(ch);
            }
            words[i].word[j] = '\0';
            words[i].count++;
        } else if (isspace(ch)) {
            i++;
        }
    }
}

void printWords(WordCount words[MAX_WORDS]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    WordCount words[MAX_WORDS];
    readFile(file, words);

    fclose(file);
    printWords(words);

    return 0;
}