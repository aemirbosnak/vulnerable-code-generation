//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: creative
#include<stdio.h>
#include<string.h>

void printArray(int array[], int size); // Function to print the array
void countCharFreq(char input[], int charFreq[]); // Function to count the frequency of characters in the input

int main() {
    char input[1000]; // Input string of maximum 1000 characters
    int charFreq[26] = {0}; // Array to store the frequencies of each character
    int i;
    
    printf("Enter the input string:\n");
    fgets(input, 1000, stdin); // Reading input string from stdin
    
    // Removing trailing newline character from input
    if(input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
    
    countCharFreq(input, charFreq); // Counting the character frequency
    
    printf("\nFrequency of each character in input:\n\n");
    for(i=0; i<26; i++) {
        if(charFreq[i] != 0) {
            printf("%c - %d\n", i+97, charFreq[i]); // Printing the frequencies of each character
        }
    }
    
    return 0;
}

void countCharFreq(char input[], int charFreq[]) {
    int i;
    
    for(i=0; i<strlen(input); i++) {
        if(input[i] >= 'a' && input[i] <= 'z') {
            charFreq[input[i] - 97]++; // Incrementing the frequency of the character in the array
        }
    }
}

void printArray(int array[], int size) {
    int i;
    
    for(i=0; i<size; i++) {
        printf("%d ", array[i]);
    }
    
    printf("\n");
}