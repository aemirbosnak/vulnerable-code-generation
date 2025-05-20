//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: medieval
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readFile(char* filename, WordCount words[]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        int i = 0;
        while (line[i]!= '\0') {
            if (isalpha(line[i])) {
                char word[MAX_WORD_LENGTH];
                int j = 0;
                while (isalpha(line[i])) {
                    word[j++] = tolower(line[i++]);
                }
                word[j] = '\0';

                for (int k = 0; k < MAX_WORDS; k++) {
                    if (strcmp(words[k].word, word) == 0) {
                        words[k].count++;
                        break;
                    } else if (strcmp(words[k].word, "") == 0) {
                        strcpy(words[k].word, word);
                        words[k].count = 1;
                        break;
                    }
                }
            }
            i++;
        }
    }

    fclose(file);
}

void printWords(WordCount words[], int numWords) {
    printf("Total words: %d\n", numWords);
    for (int i = 0; i < numWords; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    WordCount words[MAX_WORDS];
    readFile(argv[1], words);
    printWords(words, MAX_WORDS);

    return 0;
}