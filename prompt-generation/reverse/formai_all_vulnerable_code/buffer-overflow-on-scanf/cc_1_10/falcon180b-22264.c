//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct Word {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

struct Word words[MAX_WORDS];
int num_words = 0;

void add_word(char* word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word, words[i].word) == 0) {
            words[i].frequency++;
            return;
        }
    }
    if (num_words >= MAX_WORDS) {
        printf("Error: Maximum number of words reached.\n");
        return;
    }
    strcpy(words[num_words].word, word);
    words[num_words].frequency = 1;
    num_words++;
}

void display_words() {
    int i;
    printf("Word\tFrequency\n");
    for (i = 0; i < num_words; i++) {
        printf("%s\t%d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    char filename[50];
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    char ch;
    int in_word = 0;
    char word[MAX_WORD_LENGTH];
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            in_word = 1;
            strcpy(word, "");
            strcat(word, &ch);
        } else if (in_word) {
            strcat(word, &ch);
        } else {
            add_word(word);
            in_word = 0;
        }
    }
    if (in_word) {
        add_word(word);
    }

    fclose(fp);

    display_words();

    return 0;
}