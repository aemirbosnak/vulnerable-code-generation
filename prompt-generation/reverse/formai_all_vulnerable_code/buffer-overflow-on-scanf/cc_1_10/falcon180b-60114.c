//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 100

typedef struct {
    char *word;
    int length;
} Word;

void read_words(FILE *file, Word *words, int *num_words) {
    *num_words = 0;
    char word[MAX_WORD_SIZE];
    while (fscanf(file, "%s", word)!= EOF) {
        Word *new_word = malloc(sizeof(Word));
        new_word->word = strdup(word);
        new_word->length = strlen(word);
        words[*num_words] = *new_word;
        (*num_words)++;
    }
}

int is_palindrome(char *word) {
    int i, j;
    for (i = 0, j = strlen(word) - 1; i < j; i++, j--) {
        if (tolower(word[i])!= tolower(word[j])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    FILE *file;
    char filename[100];
    printf("Enter the name of the file: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found!\n");
        exit(1);
    }
    Word words[1000];
    int num_words = 0;
    read_words(file, words, &num_words);
    for (int i = 0; i < num_words; i++) {
        if (is_palindrome(words[i].word)) {
            printf("%s is a palindrome!\n", words[i].word);
        } else {
            printf("%s is not a palindrome.\n", words[i].word);
        }
    }
    fclose(file);
    return 0;
}