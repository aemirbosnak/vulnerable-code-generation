//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 1000000 // Maximum size of the eBook
#define MAX_WORDS 100000 // Maximum number of words in the eBook
#define MAX_CHARS 50 // Maximum length of a word

// Struct to store each word in the eBook
struct word {
    char word[MAX_CHARS]; // The word
    int frequency; // The frequency of the word in the eBook
};

// Function to compare two words (for sorting)
int compareWords(const void *a, const void *b) {
    struct word *wordA = (struct word *)a;
    struct word *wordB = (struct word *)b;

    return strcmp(wordA->word, wordB->word);
}

// Function to read the eBook from a file
void readeBook(char *filename, struct word *words) {
    FILE *file;
    char ch;
    int i = 0;

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = tolower(ch);
            words[i].word[1] = '\0';
            i++;
        }
    }

    fclose(file);
}

// Function to count the frequency of each word in the eBook
void countWords(struct word *words, int n) {
    int i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].frequency += words[j].frequency;
                words[j].frequency = 0;
            }
        }
    }
}

// Function to print the words and their frequencies
void printWords(struct word *words, int n) {
    qsort(words, n, sizeof(struct word), compareWords);

    for (int i = 0; i < n; i++) {
        if (words[i].frequency > 0) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main() {
    char filename[100];
    printf("Enter the name of the eBook file: ");
    scanf("%s", filename);

    struct word words[MAX_WORDS];

    readeBook(filename, words);
    countWords(words, MAX_WORDS);
    printWords(words, MAX_WORDS);

    return 0;
}