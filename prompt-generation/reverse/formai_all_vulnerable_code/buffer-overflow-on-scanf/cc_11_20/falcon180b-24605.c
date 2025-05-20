//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int main() {
    FILE *fp;
    char filename[100];
    char ch;
    int i = 0;
    WordCount words[MAX_WORDS];

    // Get filename from user input
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read file and count words
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = tolower(ch);
            int j = 1;
            while ((ch = fgetc(fp))!= EOF && isalnum(ch)) {
                words[i].word[j++] = tolower(ch);
            }
            words[i].word[j] = '\0';
            words[i].count = 1;
            i++;
        }
    }

    // Close file
    fclose(fp);

    // Sort words by frequency
    for (i = 0; i < MAX_WORDS - 1; i++) {
        for (int j = i + 1; j < MAX_WORDS; j++) {
            if (words[i].count < words[j].count) {
                WordCount temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Print word count
    printf("Word\tFrequency\n");
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s\t%d\n", words[i].word, words[i].count);
        }
    }

    return 0;
}