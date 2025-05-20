//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: systematic
#include<stdio.h>
#include<string.h>

//Function to convert a single alien letter to a corresponding english letter
char alienToEnglish(char letter){
    if(letter == 'e') return 'a';
    else if(letter == 'd') return 'b';
    else if(letter == 'c') return 'c';
    else if(letter == 'b') return 'd';
    else if(letter == 'a') return 'e';
    else return ' '; //if input letter is not a valid alien letter
}

//Function to translate a single word from alien to english language
//Returns 1 if translation is successful, 0 if unsuccessful
int translateWord(char* alienWord, char* translation){
    int length = strlen(alienWord);
    for(int i=0; i<length; i++){
        char englishLetter = alienToEnglish(alienWord[i]);
        if(englishLetter == ' '){ //if input word contains an invalid alien letter
            printf("\nError translating '%s': '%c' is not a valid alien letter!\n", alienWord, alienWord[i]);
            return 0;
        }
        translation[i] = englishLetter;
    }
    translation[length] = '\0'; //add null terminator to the end of translation string
    return 1;
}

//Function to translate a full sentence from alien to english language
void translateSentence(char* alienSentence){
    char* word = strtok(alienSentence, " "); //tokenize input sentence into words
    while(word != NULL){
        char* translation = (char*)malloc(sizeof(char) * strlen(word)); //allocate memory for translation string
        if(translateWord(word, translation)){
            printf("%s ", translation); //print translated word
        }
        free(translation); //free memory allocated for translation string
        word = strtok(NULL, " "); //get next word
    }
    printf("\n");
}

//Driver function
int main(){
    char alienSentence[100];
    printf("Enter a sentence in Alien language: ");
    scanf("%[^\n]", alienSentence); //get input sentence (including spaces)
    getchar(); //consume newline character from input buffer
    translateSentence(alienSentence); //translate input sentence to english
    return 0;
}