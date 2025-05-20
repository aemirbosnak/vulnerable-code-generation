//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readFile(FILE *file, WordCount words[MAX_WORDS]) {
    char ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            if (i >= MAX_WORDS) {
                printf("Error: Too many words in file.\n");
                exit(1);
            }
            words[i].word[0] = tolower(ch);
            int j = 1;
            while ((ch = fgetc(file))!= EOF && isalpha(ch)) {
                words[i].word[j] = tolower(ch);
                j++;
            }
            words[i].word[j] = '\0';
            words[i].count = 1;
            i++;
        } else if (isspace(ch)) {
            continue;
        } else {
            printf("Error: Invalid character in file.\n");
            exit(1);
        }
    }
}

void countWords(WordCount words[MAX_WORDS]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].word[0]!= '\0') {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *file;
    char filename[100];

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    WordCount words[MAX_WORDS];

    readFile(file, words);

    countWords(words);

    fclose(file);

    return 0;
}