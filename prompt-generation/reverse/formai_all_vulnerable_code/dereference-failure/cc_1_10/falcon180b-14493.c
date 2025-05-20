//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
int countWords(char *sentence);
char *reverseString(char *str);
void printReverse(char *str);

// Main function
int main(int argc, char *argv[]) {
    char sentence[100]; // Maximum length of sentence is 100 characters
    char reversed[200]; // Maximum length of reversed string is 200 characters
    int numWords; // Number of words in the sentence

    // Prompt user for input
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin); // Read input from user

    // Remove newline character from input
    sentence[strcspn(sentence, "\n")] = '\0';

    // Count number of words in the sentence
    numWords = countWords(sentence);

    // Reverse the sentence
    strcpy(reversed, sentence);
    reverseString(reversed);

    // Print the reversed sentence
    printf("Reversed sentence: %s\n", reversed);
    printf("Number of words: %d\n", numWords);

    return 0;
}

// Function to count the number of words in a sentence
int countWords(char *sentence) {
    int count = 0;
    char *token;

    // Split the sentence into words using space as a delimiter
    token = strtok(sentence, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }

    return count;
}

// Function to reverse a string
char *reverseString(char *str) {
    char *ptr1, *ptr2;
    char temp;

    // Reverse the string
    ptr1 = str;
    ptr2 = str + strlen(str) - 1;
    while (ptr1 < ptr2) {
        temp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = temp;
        ptr1++;
        ptr2--;
    }

    return str;
}

// Function to print the reversed string
void printReverse(char *str) {
    int i;

    // Print the reversed string
    for (i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}