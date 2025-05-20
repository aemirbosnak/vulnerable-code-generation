//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct Word {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int main() {
    FILE *fp;
    char filename[50];
    int i, j;
    char ch;
    struct Word words[MAX_WORDS];
    int num_words = 0;

    printf("Enter a filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            if (num_words >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                break;
            }

            words[num_words].word[0] = tolower(ch);
            words[num_words].frequency = 1;
            num_words++;

            while ((ch = fgetc(fp))!= EOF && isalpha(ch)) {
                words[num_words - 1].word[strlen(words[num_words - 1].word)] = tolower(ch);
                words[num_words - 1].frequency++;
            }

            words[num_words - 1].word[strlen(words[num_words - 1].word)] = '\0';
        }
        else {
            if (num_words >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                break;
            }

            words[num_words].word[0] = '\0';
            words[num_words].frequency = 1;
            num_words++;
        }
    }

    fclose(fp);

    printf("Enter a word to search for: ");
    scanf("%s", filename);

    for (i = 0; i < num_words; i++) {
        if (strcmp(filename, words[i].word) == 0) {
            printf("Frequency of '%s' is %d.\n", filename, words[i].frequency);
            break;
        }
    }

    return 0;
}