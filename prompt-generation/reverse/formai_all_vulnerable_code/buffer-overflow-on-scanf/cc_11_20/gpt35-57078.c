//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 100

int main() {

    char text[MAX_WORDS][MAX_LENGTH], word[MAX_LENGTH];
    int count[MAX_WORDS], i, j, k, n;

    printf("Welcome to the curious Word Frequency Counter Program!\n\n");

    printf("Enter your text here:\n\n");

    n = 0;

    // Reads input text and removes punctuation
    while(scanf("%s", word) == 1) {
        // Remove punctuation from the word
        for(i = 0; i < strlen(word); i++) {
            if(ispunct(word[i])) {
                for(j = i; j < strlen(word); j++) {
                    word[j] = word[j+1];
                }
            }
        }
        // Convert word to lowercase
        for(i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        // Add word to text array
        strcpy(text[n], word);
        n++;
    }

    printf("\nFrequency of words in the text:\n\n");

    // Initialize count array to 0
    for(i = 0; i < n; i++) {
        count[i] = 0;
    }

    // Count frequency of each word
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if(strcmp(text[i], text[j]) == 0) {
                count[i]++;
            }
        }
    }

    // Print results
    for(i = 0; i < n; i++) {
        if(count[i] == 0) {
            printf("%s: %d\n", text[i], 1);
        } else {
            printf("%s: %d\n", text[i], count[i]+1);
        }
    }

    printf("\nThank you for using the curious Word Frequency Counter Program.\n");

    return 0;
}