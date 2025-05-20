//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define SENTENCE_END '.'
#define SENTENCE_END_INDEX -1

// Function to count the frequency of words in a given sentence
void countWords(char *sentence) {
    int i, j, k;
    char word[MAX_WORD_LENGTH];
    int wordCount[MAX_WORDS] = {0};

    // Convert sentence to lowercase
    for (i = 0; i < strlen(sentence); i++) {
        sentence[i] = tolower(sentence[i]);
    }

    // Count the frequency of each word
    i = 0;
    j = 0;
    while (sentence[i]!= SENTENCE_END) {
        if (isalpha(sentence[i])) { // Check if character is alphabetic
            word[j] = sentence[i];
            j++;
        } else if (j > 0) { // Check if word is complete
            word[j] = '\0';
            wordCount[k] += 1;
            k++;
            j = 0;
        }
        i++;
    }
    if (j > 0) { // Check if last word is complete
        word[j] = '\0';
        wordCount[k] += 1;
    }

    // Print the frequency of each word
    for (i = 0; i < k; i++) {
        printf("%s: %d\n", word[i], wordCount[i]);
    }
}

int main() {
    char sentence[1000];

    // Get a sentence from the user
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);

    // Count the frequency of words in the sentence
    countWords(sentence);

    return 0;
}