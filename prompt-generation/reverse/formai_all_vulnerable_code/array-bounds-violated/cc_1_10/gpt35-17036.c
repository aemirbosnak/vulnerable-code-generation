//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: satisfied
#include <stdio.h>
#include <string.h>

int main(){
    char phrase[100];

    printf("Enter a phrase in the C Alien Language:\n");
    fgets(phrase, 100, stdin); //get phrase from user
    phrase[strcspn(phrase, "\n")] = 0; //remove newline character

    char word[10];
    int wordIndex = 0;

    printf("Translated phrase: ");

    //loop through each character in the phrase
    for(int i = 0; i < strlen(phrase); i++){
        char currentChar = phrase[i];
        if(currentChar == ' '){ //if whitespace, translation is complete
            word[wordIndex] = '\0'; //add null terminator to end of word
            wordIndex = 0;
            //translate word and print
            if(strcmp(word, "Hello") == 0){
                printf("Salutations ");
            }
            else if(strcmp(word, "Goodbye") == 0){
                printf("Farewell ");
            }
            else if(strcmp(word, "Please") == 0){
                printf("Kindly ");
            }
            else{
                printf("%s ", word);
            }
        }
        else{ //if not whitespace, continue adding characters to current word
            word[wordIndex] = currentChar;
            wordIndex++;
        }
    }

    word[wordIndex] = '\0'; //add null terminator to end of last word
    //translate last word and print
    if(strcmp(word, "Hello") == 0){
        printf("Salutations");
    }
    else if(strcmp(word, "Goodbye") == 0){
        printf("Farewell");
    }
    else if(strcmp(word, "Please") == 0){
        printf("Kindly");
    }
    else{
        printf("%s", word);
    }

    return 0;
}