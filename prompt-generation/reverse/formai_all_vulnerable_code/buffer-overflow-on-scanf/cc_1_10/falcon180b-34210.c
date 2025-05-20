//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char filename[MAX_WORD_LENGTH];
    int i, j, wordCount = 0;
    WordFrequency words[MAX_WORDS];

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        i = 0;
        while (line[i]!= '\n' && line[i]!= '\0') {
            if (isalpha(line[i])) {
                j = 0;
                while (isalpha(line[i]) && j < MAX_WORD_LENGTH - 1) {
                    words[wordCount].word[j] = tolower(line[i]);
                    i++;
                    j++;
                }
                words[wordCount].word[j] = '\0';
                words[wordCount].count = 1;
                wordCount++;
            } else {
                i++;
            }
        }
    }

    fclose(file);

    printf("Word\tFrequency\n");
    for (i = 0; i < wordCount; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}