//FormAI DATASET v1.0 Category: Spell checking ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000 //maximum number of unique words in the dictionary
#define MAX_WORD_LENGTH 50 //maximum length of a word in the dictionary
#define MAX_LINE_LENGTH 200 //maximum length of a line of text

//Dictionary structure
typedef struct {
    char* words[MAX_WORDS]; //array of words
    int count; //number of unique words in the dictionary
} Dictionary;

//Function to read the dictionary file
void readDictionary(Dictionary* dict, char* filename) {
    FILE* file = fopen(filename, "r"); //open the dictionary file
    
    if(file == NULL) { //if the file cannot be opened
        fprintf(stderr, "Error: failed to open file `%s`!\n", filename);
        exit(-1);
    }
    
    char word[MAX_WORD_LENGTH];
    while(fscanf(file, "%s", word) != EOF) { //read each word from the file
        dict->words[dict->count] = (char*)malloc(strlen(word) + 1); //allocate memory for the word
        
        if(dict->words[dict->count] == NULL) { //if memory allocation fails
            fprintf(stderr, "Error: failed to allocate memory for the word `%s`!\n", word);
            exit(-1);
        }
        
        strcpy(dict->words[dict->count], word); //copy the word to the dictionary
        dict->count++; //increment the number of words in the dictionary
    }
    
    fclose(file); //close the dictionary file
}

//Function to check if a string is a valid word (i.e. contains only alphabets)
int isValidWord(char* str) {
    for(int i=0; str[i]; i++) {
        if(!isalpha(str[i])) {
            return 0;
        }
    }
    return 1;
}

//Function to perform spell checking on a line of text
void spellCheckLine(Dictionary* dict, char* line) {
    printf("%s", line); //print the line to the console
    
    char* word = strtok(line, " "); //split the line into words using delimiter space
    
    while(word != NULL) { //iterate over each word in the line
        if(!isValidWord(word)) { //if the word is not a valid word, skip to the next word
            word = strtok(NULL, " ");
            continue;
        }
        
        int found = 0; //flag to indicate if the word is found in the dictionary
        
        for(int i=0; i<dict->count; i++) { //iterate over each word in the dictionary
            if(strcmp(dict->words[i], word) == 0) { //if the word is found in the dictionary
                found = 1; //set the flag
                break;
            }
        }
        
        if(!found) { //if the word is not found in the dictionary, print the word with a caret symbol
            printf("^%s", word);
        }
        else { //otherwise, print the word as it is
            printf("%s", word);
        }
        
        //get the next word in the line
        word = strtok(NULL, " ");
        if(word != NULL) {
            printf(" "); //print the space delimiter if the word is not the last word in the line
        }
    }
    
    printf("\n"); //print a new line character after spell checking the line
}

//Main function
int main() {
    //Initialize the dictionary
    Dictionary dictionary = {
        .words = { NULL },
        .count = 0
    };
    
    //Read the dictionary file
    readDictionary(&dictionary, "dictionary.txt");
    
    //Read lines of text from the standard input and perform spell checking
    char line[MAX_LINE_LENGTH];
    while(fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        spellCheckLine(&dictionary, line);
    }
    
    //Free the memory allocated for the dictionary words
    for(int i=0; i<dictionary.count; i++) {
        free(dictionary.words[i]);
    }
    
    return 0;
}