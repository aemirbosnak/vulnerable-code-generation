//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char ch;
    int count = 0;
    int word_count = 0;
    char word[100];
    char longest_word[100];
    int longest_word_length = 0;

    if (argc!= 2) {
        printf("Usage:./word_count <filename>\n");
        exit(1);
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            count++;
        } else if (isdigit(ch)) {
            count++;
        } else if (isspace(ch)) {
            if (word_count > 0) {
                word[word_count] = '\0';
                if (strlen(word) > longest_word_length) {
                    strcpy(longest_word, word);
                    longest_word_length = strlen(word);
                }
                word_count = 0;
            }
        } else {
            printf("Invalid character found.\n");
            exit(1);
        }

        if (word_count == 0 && count > 0) {
            strcpy(word, &ch);
            word_count++;
        } else if (word_count > 0) {
            word[word_count] = ch;
            word_count++;
        }
    }

    if (word_count > 0) {
        word[word_count] = '\0';
        if (strlen(word) > longest_word_length) {
            strcpy(longest_word, word);
            longest_word_length = strlen(word);
        }
    }

    printf("Total number of words: %d\n", count);
    printf("Number of unique words: %d\n", word_count);
    printf("Longest word: %s\n", longest_word);
    printf("Length of longest word: %d\n", longest_word_length);

    fclose(fp);
    return 0;
}