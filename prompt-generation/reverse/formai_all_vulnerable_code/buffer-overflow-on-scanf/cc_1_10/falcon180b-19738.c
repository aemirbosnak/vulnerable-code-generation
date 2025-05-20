//Falcon-180B DATASET v1.0 Category: Text processing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

int main() {
    FILE *file;
    char filename[100];
    char word[MAX_WORD_LENGTH];
    int word_count = 0;
    int word_lengths[MAX_WORDS];
    int max_word_length = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        if (word_count >= MAX_WORDS) {
            printf("Maximum number of words exceeded.\n");
            exit(1);
        }
        word_count++;
        int word_length = strlen(word);
        if (word_length > MAX_WORD_LENGTH) {
            printf("Word length exceeded maximum limit.\n");
            exit(1);
        }
        if (word_length > max_word_length) {
            max_word_length = word_length;
        }
        strcpy(word_lengths[word_count - 1], &word_length);
    }

    fclose(file);

    printf("Number of words: %d\n", word_count);
    printf("Maximum word length: %d\n", max_word_length);

    for (int i = 0; i < word_count; i++) {
        printf("Word %d length: %d\n", i+1, word_lengths[i]);
    }

    return 0;
}