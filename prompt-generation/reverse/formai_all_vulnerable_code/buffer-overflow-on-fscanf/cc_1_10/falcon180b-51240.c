//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_WORD_LENGTH 64
#define MAX_NUM_WORDS 1000

char *book_file = "romance_novel.txt";
char *word_list_file = "romantic_words.txt";

int main() {
    FILE *book_fp;
    FILE *word_list_fp;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int num_words = 0;

    word_list_fp = fopen(word_list_file, "r");
    if (word_list_fp == NULL) {
        printf("Error opening word list file.\n");
        exit(1);
    }

    // Read in the list of romantic words
    while (fscanf(word_list_fp, "%s", word)!= EOF) {
        num_words++;
    }
    rewind(word_list_fp);
    char *word_list[MAX_NUM_WORDS];
    for (int i = 0; i < num_words; i++) {
        fscanf(word_list_fp, "%s", word_list[i]);
    }
    fclose(word_list_fp);

    // Open the romance novel file
    book_fp = fopen(book_file, "r");
    if (book_fp == NULL) {
        printf("Error opening book file.\n");
        exit(1);
    }

    // Read in the book line by line
    int num_lines = 0;
    while (fgets(line, MAX_LINE_LENGTH, book_fp)!= NULL) {
        num_lines++;

        // Convert the line to lowercase
        for (int i = 0; i < strlen(line); i++) {
            line[i] = tolower(line[i]);
        }

        // Count the number of romantic words in the line
        int num_romantic_words = 0;
        for (int i = 0; i < num_words; i++) {
            char *romantic_word = word_list[i];
            int word_length = strlen(romantic_word);
            int j = 0;
            while ((j < strlen(line)) && (strncmp(romantic_word, &line[j], word_length) == 0)) {
                j += word_length;
                num_romantic_words++;
            }
        }

        // Print the line with the number of romantic words
        printf("%d romantic words found in line %d:\n%s\n", num_romantic_words, num_lines, line);
    }

    fclose(book_fp);
    return 0;
}