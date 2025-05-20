//FormAI DATASET v1.0 Category: Spell checking ; Style: accurate
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//Function to check if given character is a punctuation mark
int isPunctuation(char c){
    if (c == '.' || c == ',' || c == ';' || c == ':' || c == '!' || c == '?'){
        return 1;
    }
    return 0;
}

//Function to replace punctuation marks with spaces
void replacePunctuation(char* word){
    int len = strlen(word);
    for (int i=0; i<len; i++){
        if (isPunctuation(word[i])){
            word[i] = ' ';
        }
    }
}

//Function to check if given word is spelled correctly
int isSpelledCorrectly(char* word, char** dictionary, int numWordsInDictionary){
    replacePunctuation(word);
    for (int i=0; i<numWordsInDictionary; i++){
        if (strcmp(word, dictionary[i]) == 0){
            return 1;
        }
    }
    return 0;
}

int main(){
    //Declare and initialize dictionary of correct words
    char* dictionary[] = {"hello", "world", "computer", "science", "programming", "language", "algorithm"};
    int numWordsInDictionary = sizeof(dictionary)/sizeof(dictionary[0]);

    //Read in sentence to check for spelling errors
    char sentence[100];
    printf("Enter a sentence to check for spelling errors: ");
    fgets(sentence, 100, stdin);
    int len = strlen(sentence);
    if (sentence[len-1] == '\n'){
        sentence[len-1] = '\0'; //Replace newline character with null terminator
    }

    //Tokenize sentence into words and check each word for spelling errors
    char* word = strtok(sentence, " ");
    while (word != NULL){
        if (!isSpelledCorrectly(word, dictionary, numWordsInDictionary)){
            printf("'%s' is spelled incorrectly.\n", word);
        }
        word = strtok(NULL, " ");
    }

    return 0;
}