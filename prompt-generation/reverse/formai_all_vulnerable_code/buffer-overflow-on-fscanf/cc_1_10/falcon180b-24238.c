//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of words in the eBook
#define MAX_WORDS 10000

// Define the structure of a word in the eBook
typedef struct {
    char word[50];
    int frequency;
} Word;

// Function to compare two words based on their frequency
int compareWords(const void *a, const void *b) {
    const Word *word1 = a;
    const Word *word2 = b;

    if (word1->frequency > word2->frequency) {
        return -1;
    } else if (word1->frequency < word2->frequency) {
        return 1;
    } else {
        return 0;
    }
}

// Function to read the eBook from a file
void readeBook(FILE *file, Word words[]) {
    char word[50];
    int i = 0;

    // Read each word from the file
    while (fscanf(file, "%s", word)!= EOF) {
        // Check if the word is already in the array
        int found = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(word, words[j].word) == 0) {
                words[j].frequency++;
                found = 1;
                break;
            }
        }

        // If the word is not found, add it to the array
        if (!found) {
            strcpy(words[i].word, word);
            words[i].frequency = 1;
            i++;
        }
    }

    // Sort the array based on frequency
    qsort(words, i, sizeof(Word), compareWords);
}

// Function to print the top 10 most frequent words
void printTopWords(Word words[], int n) {
    printf("Top %d most frequent words:\n", n);
    for (int i = 0; i < n && i < MAX_WORDS; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <eBook file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    Word words[MAX_WORDS];
    readeBook(file, words);
    fclose(file);

    printTopWords(words, 10);

    return 0;
}