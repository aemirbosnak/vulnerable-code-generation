//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 200

typedef struct Word {
    char word[MAX_WORDS];
    int frequency;
} Word;

Word words[MAX_WORDS];

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    int i, j, word_count = 0;

    // Get the sentence from the user
    printf("Enter a sentence: ");
    gets(sentence);

    // Tokenize the sentence into words
    char *word = strtok(sentence, " ");
    while (word) {
        Word newWord;

        // Check if the word already exists
        for (i = 0; i < word_count; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].frequency++;
                goto nextWord;
            }
        }

        // Add the word to the list
        strcpy(newWord.word, word);
        newWord.frequency = 1;
        words[word_count++] = newWord;

nextWord:
        word = strtok(NULL, " ");
    }

    // Print the words and their frequencies
    for (i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    return 0;
}