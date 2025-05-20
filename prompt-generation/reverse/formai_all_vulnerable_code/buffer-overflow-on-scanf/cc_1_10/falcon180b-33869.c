//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void read_file(FILE *fp, char *filename) {
    char ch;
    int in_word = 0;
    char word[MAX_WORD_LEN];
    WordCount words[MAX_WORDS];
    int num_words = 0;

    while ((ch = fgetc(fp))!= EOF) {
        if (isalnum(ch)) {
            if (!in_word) {
                in_word = 1;
                strcpy(word, "");
            }
            strcat(word, tolower(ch));
        } else {
            in_word = 0;
            if (strlen(word) > 0) {
                for (int i = 0; i < num_words; i++) {
                    if (strcmp(word, words[i].word) == 0) {
                        words[i].count++;
                        break;
                    }
                }
                if (num_words >= MAX_WORDS) {
                    break;
                }
                strcpy(words[num_words].word, word);
                words[num_words].count = 1;
                num_words++;
            }
        }
    }

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE *fp;
    char filename[100];

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    read_file(fp, filename);

    fclose(fp);

    return 0;
}