//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the structure for a word
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

// Define the structure for an ebook
typedef struct {
    int num_words;
    Word words[1000];
} Ebook;

// Function to load an ebook from a file
void load_ebook(Ebook *ebook, FILE *file) {
    int i = 0;
    while (fscanf(file, "%s", ebook->words[i].word)!= EOF) {
        ebook->words[i].count = 1;
        i++;
    }
    ebook->num_words = i;
}

// Function to display the top 10 most frequent words in an ebook
void display_top_words(Ebook *ebook) {
    int i = 0;
    for (i = 0; i < ebook->num_words; i++) {
        ebook->words[i].count++;
    }
    for (i = 0; i < ebook->num_words; i++) {
        if (ebook->words[i].count > 1) {
            printf("%s: %d\n", ebook->words[i].word, ebook->words[i].count);
        }
    }
}

// Main function
int main() {
    Ebook ebook;
    FILE *file;

    // Load the ebook from a file
    file = fopen("ebook.txt", "r");
    if (file == NULL) {
        printf("Error: could not open ebook file.\n");
        return 1;
    }
    load_ebook(&ebook, file);
    fclose(file);

    // Display the top 10 most frequent words
    printf("Top 10 most frequent words:\n");
    display_top_words(&ebook);

    return 0;
}