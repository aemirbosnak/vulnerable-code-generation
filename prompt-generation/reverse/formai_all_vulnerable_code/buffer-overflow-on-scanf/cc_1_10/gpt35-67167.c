//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 10000

// Function to remove punctuation from a given string
void remove_punct(char *str) {
    int len = strlen(str);
    
    for(int i=0; i<len; i++) {
        if(ispunct(str[i])) {
            for(int j=i; j<len; j++) {
                str[j] = str[j+1];
            }
            len--;
        }
    }
}

int main() {
    char text[MAX_WORDS][MAX_WORD_LENGTH];
    int freq[MAX_WORDS];
    int count = 0;
    char word[MAX_WORD_LENGTH+1];
    
    printf("Enter your text (max: %d words):\n", MAX_WORDS);
    
    // Read text from user
    while(count < MAX_WORDS && scanf("%s", word) == 1) {
        remove_punct(word);
        
        // Convert word to lower case
        for(int i=0; i<strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        
        // Check if word already exists in array
        int found = 0;
        for(int i=0; i<count; i++) {
            if(strcmp(text[i], word) == 0) {
                freq[i]++;
                found = 1;
                break;
            }
        }
        
        // Add new word to array if not found
        if(!found) {
            strcpy(text[count], word);
            freq[count] = 1;
            count++;
        }
    }
    
    printf("\nWord Frequency:\n");
    printf("-----------------\n");
    
    // Print word frequency
    for(int i=0; i<count; i++) {
        printf("%-20s %d\n", text[i], freq[i]);
    }
    
    return 0;
}