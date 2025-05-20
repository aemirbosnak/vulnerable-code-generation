//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

//Defining the maximum number of words that can be stored in the array
#define MAX_WORDS 1000

//Defining the structure for each word
typedef struct {
    char word[50]; //Maximum length of each word
    int frequency; //Frequency of each word
} Word;

//Function to compare two words
int compareWords(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

//Function to read the input file and store the words in an array
void readInputFile(FILE* inputFile, Word words[]) {
    char word[50];
    while(fscanf(inputFile, "%s", word)!= EOF) {
        //Converting the word to lowercase
        for(int i=0; word[i]!='\0'; i++) {
            word[i] = tolower(word[i]);
        }
        //Checking if the word is already in the array
        Word* foundWord = bsearch(&word, words, MAX_WORDS, sizeof(Word), compareWords);
        if(foundWord == NULL) {
            //If the word is not found, add it to the array
            strcpy(foundWord->word, word);
            foundWord->frequency = 1;
        }
        else {
            //If the word is found, increase its frequency
            foundWord->frequency++;
        }
    }
}

//Function to print the word frequency in descending order
void printWordFrequency(Word words[]) {
    qsort(words, MAX_WORDS, sizeof(Word), compareWords);
    printf("Word\tFrequency\n");
    for(int i=0; i<MAX_WORDS; i++) {
        printf("%s\t%d\n", words[i].word, words[i].frequency);
    }
}

//Main function
int main() {
    FILE* inputFile;
    inputFile = fopen("input.txt", "r");
    if(inputFile == NULL) {
        printf("Error: Cannot open input file.\n");
        return 1;
    }
    Word words[MAX_WORDS];
    readInputFile(inputFile, words);
    fclose(inputFile);
    printWordFrequency(words);
    return 0;
}