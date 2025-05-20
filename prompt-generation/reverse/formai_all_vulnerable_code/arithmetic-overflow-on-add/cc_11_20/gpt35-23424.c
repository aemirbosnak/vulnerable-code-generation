//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: complex
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[1000], word[1000];
    int count = 0, i, j, k;
    
    // Prompt user for input
    printf("Enter a string: ");
    fgets(str, 1000, stdin);
    
    // Convert all characters to lowercase
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
    
    // Remove all punctuation marks and replace with spaces
    for (i = 0; str[i] != '\0'; i++) {
        if (ispunct(str[i])) {
            str[i] = ' ';
        }
    }
    
    // Split the string into words and store in an array
    char words[1000][1000];
    int word_count = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            word[j] = '\0';
            if (strlen(word) > 0) {
                strcpy(words[word_count], word);
                word_count++;
            }
            j = 0;
        } else {
            word[j] = str[i];
            j++;
        }
    }
    
    // Count the frequency of each word
    int freq[word_count];
    for (i = 0; i < word_count; i++) {
        freq[i] = 1;
        for (j = i+1; j < word_count; j++) {
            if (strcmp(words[i],words[j]) == 0) {
                freq[i]++;
            }
        }
    }
    
    // Print the word frequency table
    printf("\nWord\tFrequency\n");
    for (i = 0; i < word_count; i++) {
        if (freq[i] > 0) {
            printf("%s\t%d\n", words[i], freq[i]);
        }
    }
    
    return 0;
}