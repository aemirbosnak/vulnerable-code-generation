//FormAI DATASET v1.0 Category: Spell checking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Struct to hold each word and its frequency
typedef struct wordCount {
    char word[50];
    int count;
} WordCount;

// Function to check if a character is a valid letter/digit
int isvalid(char c) {
    return isalpha(c) || isdigit(c);
}

// Function to convert string to lowercase
void tolowercase(char *str) {
    for(int i=0; str[i]!='\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    // Open the text file to be checked
    FILE *file = fopen("text.txt", "r");
    if(!file) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Read the file and count all the words
    WordCount words[1000];
    int count = 0;
    char word[50];
    while(fscanf(file, "%s", word) != EOF) {
        tolowercase(word);

        // Remove punctuation from the end of the word
        while(!isvalid(word[strlen(word)-1])) {
            word[strlen(word)-1] = '\0';
        }

        // Check if the word is already in the array
        int found = 0;
        for(int i=0; i<count; i++) {
            if(strcmp(word, words[i].word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        // If the word is not in the array, add it
        if(!found) {
            strcpy(words[count].word, word);
            words[count].count = 1;
            count++;
        }
    }

    // Check each word in the array against a dictionary of correct spellings
    FILE *dict = fopen("dictionary.txt", "r");
    if(!dict) {
        printf("Error opening dictionary!\n");
        exit(1);
    }

    char dictWord[50];
    while(fscanf(dict, "%s", dictWord) != EOF) {
        tolowercase(dictWord);

        // Check if the word is in the array of counted words
        int found = 0;
        for(int i=0; i<count; i++) {
            if(strcmp(dictWord, words[i].word) == 0) {
                printf("%s (%d)\n", dictWord, words[i].count);
                found = 1;
                break;
            }
        }

        // If the word is not in the array, it is misspelled
        if(!found) {
            printf("%s (0)\n", dictWord);
        }
    }

    // Close the files and exit
    fclose(file);
    fclose(dict);
    return 0;
}