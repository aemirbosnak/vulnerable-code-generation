//Falcon-180B DATASET v1.0 Category: Text processing ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int main() {
    FILE *file;
    char line[MAX_WORD_LEN];
    char delimiters[] = ",.!?;:\"'()[]{}<>";
    int i, j, k, word_count = 0;
    WordCount words[MAX_WORDS];

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LEN, file)!= NULL) {
        for (i = 0; line[i]!= '\0'; i++) {
            if (strchr(delimiters, line[i])!= NULL) {
                line[i] = '\0';
            }
        }
        for (j = 0; j < MAX_WORDS; j++) {
            if (words[j].count == 0) {
                strcpy(words[j].word, line);
                words[j].count = 1;
                word_count++;
                break;
            } else if (strcmp(words[j].word, line) == 0) {
                words[j].count++;
                break;
            }
        }
    }

    for (k = 0; k < word_count; k++) {
        printf("%s: %d\n", words[k].word, words[k].count);
    }

    fclose(file);
    return 0;
}