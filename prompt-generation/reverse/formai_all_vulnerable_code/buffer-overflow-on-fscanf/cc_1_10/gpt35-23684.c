//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_WORD_LEN 50 // max length of word
#define MAX_WORDS 1000 // max number of unique words

//Function to convert the given string to lowercase
void toLower(char* str) {
    for(int i=0; i<strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

//Structure to hold word information
typedef struct WordInfo {
    char word[MAX_WORD_LEN];
    int count;
} WordInfo;

//Function to compare two words for sorting the array
int compare(const void* x, const void* y) {
    return ((WordInfo*)y)->count - ((WordInfo*)x)->count;
}

int main() {
    WordInfo words[MAX_WORDS]; // array of words
    char currWord[MAX_WORD_LEN];
    int numWords = 0;

    //open input file
    FILE* inFile = fopen("input.txt", "r");

    if(inFile == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    //read input file word by word
    while(fscanf(inFile, "%s", currWord) != EOF) {
        toLower(currWord);

        //check if word is already in array and increment the count if it is
        int found = 0;
        for(int i=0; i<numWords; i++) {
            if(strcmp(words[i].word, currWord) == 0) {
                found = 1;
                words[i].count++;
                break;
            }
        }

        //if word not found in array, add it to the array
        if(!found) {
            strcpy(words[numWords].word, currWord);
            words[numWords].count = 1;
            numWords++;
        }
    }

    //sort array in decreasing order of count
    qsort(words, numWords, sizeof(WordInfo), compare);

    //print the word frequency table
    printf("Words\t\tFrequency\n");
    printf("----------------------------\n");
    for(int i=0; i<numWords; i++) {
        printf("%-15s %d\n", words[i].word, words[i].count);
    }

    fclose(inFile);

    return 0;
}