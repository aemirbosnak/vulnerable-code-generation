//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 10000
#define MAX_SPAM_WORDS 100
#define MAX_HAM_WORDS 100

// Initialize the list of spam words
char *spam_words[] = {
    "free", "money", "click", "win", "offer", "sale", "discount", "earn", "cash", "prize"
};

// Initialize the list of ham words
char *ham_words[] = {
    "hello", "hi", "thanks", "you", "me", "my", "your", "his", "her", "the"
};

// Create a struct to store the word and its frequency
typedef struct {
    char *word;
    int frequency;
} word_t;

// Create a function to compare two words
int compare_words(const void *a, const void *b) {
    word_t *word_a = (word_t *)a;
    word_t *word_b = (word_t *)b;

    return strcmp(word_a->word, word_b->word);
}

// Create a function to count the frequency of words in a text
int count_words(char *text, word_t *words, int num_words) {
    int i, j;
    char *word;
    int frequency = 0;

    // Tokenize the text
    word = strtok(text, " ");
    while (word != NULL) {
        // Convert the word to lowercase
        for (i = 0; word[i] != '\0'; i++) {
            word[i] = tolower(word[i]);
        }

        // Check if the word is in the list of spam words
        for (j = 0; j < num_words; j++) {
            if (strcmp(word, spam_words[j]) == 0) {
                frequency++;
                break;
            }
        }

        // Check if the word is in the list of ham words
        for (j = 0; j < num_words; j++) {
            if (strcmp(word, ham_words[j]) == 0) {
                frequency--;
                break;
            }
        }

        // Get the next word
        word = strtok(NULL, " ");
    }

    return frequency;
}

// Create a function to classify a text as spam or ham
int classify_text(char *text) {
    // Count the frequency of words in the text
    int frequency = count_words(text, spam_words, MAX_SPAM_WORDS);
    frequency += count_words(text, ham_words, MAX_HAM_WORDS);

    // Classify the text as spam or ham
    if (frequency > 0) {
        return 1; // Spam
    } else {
        return 0; // Ham
    }
}

// Main function
int main() {
    // Get the text to classify
    char text[1000];
    printf("Enter the text to classify: ");
    gets(text);

    // Classify the text as spam or ham
    int classification = classify_text(text);

    // Print the classification result
    if (classification == 1) {
        printf("The text is spam.\n");
    } else {
        printf("The text is ham.\n");
    }

    return 0;
}