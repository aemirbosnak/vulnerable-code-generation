//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000 // Maximum number of words to be counted
#define MAX_WORD_LENGTH 20 // Maximum length of a word

typedef struct {
    char word[MAX_WORD_LENGTH]; // The word itself
    int count; // The number of times the word appears in the text
} WordCount;

int compare(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;

    return strcmp(wc1->word, wc2->word);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char text[MAX_WORDS * MAX_WORD_LENGTH]; // Buffer to hold the entire text
    int text_length = 0; // Length of the text

    char word[MAX_WORD_LENGTH]; // Buffer to hold a word
    int word_length; // Length of the current word

    while (fscanf(file, "%s", word)!= EOF) { // Read words from the file
        word_length = strlen(word);

        // Convert the word to lowercase
        for (int i = 0; i < word_length; i++) {
            word[i] = tolower(word[i]);
        }

        // Check if the word is already in the text
        char *pos = strstr(text, word);
        if (pos == NULL) { // If not, add it to the text
            strncat(text, word, word_length);
            text_length += word_length;
        }
    }

    fclose(file);

    // Count the frequency of each word
    WordCount words[MAX_WORDS];
    int num_words = 0;

    char *token = strtok(text, ",.?!;:");
    while (token!= NULL) {
        if (num_words >= MAX_WORDS) {
            break;
        }

        strncpy(words[num_words].word, token, MAX_WORD_LENGTH);
        words[num_words].count = 1;
        num_words++;

        token = strtok(NULL, ",.?!;:");
    }

    // Sort the words by frequency
    qsort(words, num_words, sizeof(WordCount), compare);

    // Print the top 10 most frequent words
    printf("Top 10 most frequent words:\n");
    for (int i = 0; i < 10 && i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}