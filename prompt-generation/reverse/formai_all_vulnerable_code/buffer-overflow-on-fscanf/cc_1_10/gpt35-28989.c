//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: satisfied
#include <stdio.h>
#include <ctype.h>

// function to count word frequency
void countWords(FILE *filePtr) {
    char word[50];
    int count = 0, freq = 0;
    
    // read from file until end of file is reached
    while(fscanf(filePtr, "%s", word) != EOF) {
        // convert word to lowercase
        for(int i=0; i<strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        
        // check if word is "unique"
        if(countUnique(filePtr, word) == 1) {
            // reset to beginning of file
            rewind(filePtr);
            // count frequency of word in file
            freq = countFrequency(filePtr, word);
            printf("%s: %d\n", word, freq);
        }
    }
}

// function to count frequency of word in file
int countFrequency(FILE *filePtr, char word[]) {
    char currWord[50];
    int count = 0;
    
    // read from file until end of file is reached
    while(fscanf(filePtr, "%s", currWord) != EOF) {
        // convert word to lowercase
        for(int i=0; i<strlen(currWord); i++) {
            currWord[i] = tolower(currWord[i]);
        }
        
        // check if current word matches input word
        if(strcmp(currWord, word) == 0) {
            count++;
        }
    }
    
    return count;
}

// function to count "unique" occurrences of word in file
int countUnique(FILE *filePtr, char word[]) {
    char currWord[50];
    int count = 0;
    
    // read from file until end of file is reached
    while(fscanf(filePtr, "%s", currWord) != EOF) {
        // convert word to lowercase
        for(int i=0; i<strlen(currWord); i++) {
            currWord[i] = tolower(currWord[i]);
        }
        
        // check if current word matches input word
        if(strcmp(currWord, word) == 0) {
            count++;
            // if count is greater than 1, return 0
            if(count > 1) {
                return 0;
            }
        }
    }
    
    return 1;
}

int main() {
    // open file for reading
    FILE *filePtr = fopen("example.txt", "r");
    
    // check for errors
    if(filePtr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    // call function to count word frequency
    countWords(filePtr);
    
    // close file
    fclose(filePtr);
    
    return 0;
}