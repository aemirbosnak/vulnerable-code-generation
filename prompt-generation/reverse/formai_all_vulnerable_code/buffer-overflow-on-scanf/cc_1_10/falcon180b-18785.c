//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main() {
    FILE *file;
    char line[100];
    char word[MAX_WORD_LENGTH];
    int count = 0;
    struct word_count words[MAX_WORDS];

    printf("Enter the name of the text file: ");
    scanf("%s", line);

    file = fopen(line, "r");

    if (file == NULL) {
        printf("File not found!\n");
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        count++;
        if (count > MAX_WORDS) {
            printf("Maximum number of words exceeded!\n");
            exit(1);
        }
        strcpy(words[count-1].word, word);
        words[count-1].count = 1;
    }

    for (int i = 0; i < count; i++) {
        for (int j = i+1; j < count; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].count += words[j].count;
                words[j].word[0] = '\0';
            }
        }
    }

    printf("Word\tFrequency\n");
    for (int i = 0; i < count; i++) {
        if (words[i].word[0]!= '\0') {
            printf("%s\t%d\n", words[i].word, words[i].count);
        }
    }

    fclose(file);
    return 0;
}