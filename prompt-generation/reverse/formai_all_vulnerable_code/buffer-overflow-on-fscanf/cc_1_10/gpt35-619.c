//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 1000

int main(void) {
    FILE *fp;
    char *filename = "example.txt";
    char word[MAX_LEN];
    int count = 0;
    
    // Open the input file
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    // Create an array to store the word counts
    int word_count[MAX_LEN] = {0};
    
    // Read the file and count the words
    while (fscanf(fp, "%s", word) != EOF) {
        // Remove any non-letter characters from the word
        char *p = word;
        while (*p) {
            if (!isalpha(*p)) {
                memmove(p, p+1, strlen(p));
            } else {
                ++p;
            }
        }
        // Convert the word to lowercase
        for (int i = 0; i < strlen(word); ++i) {
            word[i] = tolower(word[i]);
        }
        // Increment the corresponding count in the array
        ++word_count[hash(word)];
    }
    
    // Print the results
    printf("Word Frequency Count:\n");
    for (int i = 0; i < MAX_LEN; ++i) {
        if (word_count[i] > 0) {
            printf("%d: %d\n", i, word_count[i]);
        }
    }
    
    // Close the file and exit
    fclose(fp);
    return 0;
}

// Hash function to determine the array index for a given word
int hash(char *str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (*str++ + hash) * 31;
    }
    return hash % MAX_LEN;
}