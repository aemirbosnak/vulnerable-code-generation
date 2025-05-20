//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to count the number of words in a given input string
int countWords(char* inputString) {

    int wordCount = 0; // initialize word count to be zero
    int flag = 0; // initialize a flag to indicate whether we are in a word or not

    // loop through the input string character by character
    for(int i = 0; i < strlen(inputString); i++) {
        
        // if the current character is not a whitespace character and the flag is not set, then we have encountered the beginning of a new word
        if(inputString[i] != ' ' && inputString[i] != '\t' && inputString[i] != '\n' && flag == 0) {
            wordCount++; // increment the word count
            flag = 1; // set the flag to indicate that we are in a word
        }
        // if the current character is a whitespace character and the flag is set, then we have encountered the end of a word
        else if((inputString[i] == ' ' || inputString[i] == '\t' || inputString[i] == '\n') && flag == 1) {
            flag = 0; // reset the flag to indicate that we are no longer in a word
        }

    }

    return wordCount;
}

int main() {

    char inputString[1000]; // initialize an array to store the input string
    
    // prompt the user for input
    printf("Enter a string of words:\n");

    // read the input string from standard input
    fgets(inputString, sizeof(inputString), stdin);

    // remove trailing newline character from input string, if it exists
    if(inputString[strlen(inputString)-1] == '\n') {
        inputString[strlen(inputString)-1] = '\0';
    }

    // call the countWords function to count the number of words in the input string
    int wordCount = countWords(inputString);

    // output the result to standard output
    printf("There are %d words in the input string.\n", wordCount);

    return 0;
}