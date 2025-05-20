//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int count;
} Word;

Word words[MAX_WORDS];

void process_line(char *line) {
    char word[WORD_LENGTH];
    char *p = word;
    int i;

    for (i = 0; i < strlen(line) && p - word < WORD_LENGTH; i++) {
        *p++ = tolower(line[i]);
        if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n') {
            *p++ = '\0';
            if (p > word && *word != '\0') {
                int index = 0;
                for (; index < MAX_WORDS; index++) {
                    if (strcmp(words[index].word, word) == 0) {
                        words[index].count++;
                        break;
                    }
                }
                if (index == MAX_WORDS) {
                    for (index = 0; index < MAX_WORDS; index++) {
                        if (words[index].count == 0) {
                            strcpy(words[index].word, word);
                            words[index].count = 1;
                            break;
                        }
                    }
                }
                p = word;
            }
        }
    }
    *p = '\0';
}

int main() {
    FILE *fp;
    char filename[100];
    char line[1024];

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        process_line(line);
    }

    fclose(fp);

    printf("\nWord frequencies starting with letter 'C':\n");

    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0 && words[i].word[0] == 'c') {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }

    return 0;
}