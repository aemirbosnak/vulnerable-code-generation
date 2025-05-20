//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a structure to store the word and its frequency
struct wordFrequency{
    char* word;
    int frequency;
};

int main(){
    char input[1000]; // Max input size is 1000 characters
    printf("Enter your input: ");
    fgets(input, sizeof(input), stdin); //fgets is used to read input from standard input
    
    int n = strlen(input);
    if(input[n-1] == '\n'){ // If last character of input is a newline character, remove it and replace it with null terminator
        input[n-1] = '\0';
    }
    
    struct wordFrequency freq[100]; // Maximum words that can be counted is 100
    int numOfWords = 0;
    
    // Split the input into words
    char *token = strtok(input, " ");
    while(token != NULL){
        int isNewWord = 1;
        char* currentWord = token;
        for(int i=0; i<numOfWords; i++){
            if(strcmp(freq[i].word, currentWord) == 0){ // If the word is already in the list, increment its frequency
                freq[i].frequency++;
                isNewWord = 0;
                break;
            }
        }
        if(isNewWord){ // If the word is not in the list, add it to the list and initialize its frequency to 1
            struct wordFrequency newWord;
            newWord.word = currentWord;
            newWord.frequency = 1;
            freq[numOfWords] = newWord;
            numOfWords++;
        }
        token = strtok(NULL, " ");
    }
    
    // Sort the list in descending order of frequency
    for(int i=0; i<numOfWords-1; i++){
        for(int j=i+1; j<numOfWords; j++){
            if(freq[i].frequency < freq[j].frequency){
                struct wordFrequency temp = freq[i];
                freq[i] = freq[j];
                freq[j] = temp;
            }
        }
    }
    
    // Print the list
    printf("\nWord Frequency Count:\n");
    for(int i=0; i<numOfWords; i++){
        printf("%s: %d\n", freq[i].word, freq[i].frequency);
    }
    
    return 0;
}