//FormAI DATASET v1.0 Category: Spell checking ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    //Defining the dictionary of correct spellings
    char *dict[10] = {"apple", "banana", "cherry", "orange", "grape", "kiwi", "mango", "peach", "pear", "watermelon"};

    //Defining the user input word
    char word[20];

    //Prompting the user to enter a word
    printf("Please enter a word to spell check: ");

    //Taking the user input
    scanf("%s", word);

    //Declaring a variable to count the number of matched letters
    int matchedLetters = 0;

    //Looping through the user input word
    for(int i=0; i<strlen(word); i++){

        //Looping through the dictionary words
        for(int j=0; j<10; j++){

            //Looping through the letters in a dictionary word
            for(int k=0; k<strlen(dict[j]); k++){

                //Checking if the letters match
                if(word[i] == dict[j][k]){

                    //If the matched letter is the first letter in dictionary word and it is the first matched letter for user word, 
                    //increase matched letters count
                    if(k==0 && matchedLetters==i){
                        matchedLetters++;
                    }

                    //Once all letters in user word are matched to any of the dictionary words, output message
                    if(matchedLetters == strlen(word)){
                        printf("Your word '%s' is spelled correctly!\n", word);
                        return 0;
                    }
                    
                    //Exiting the nested loops if the letters match to avoid unnecessary checks
                    break;
                
                }

            }

        }

    }

    //If the word is not in the dictionary, output message
    printf("Your word '%s' is spelled incorrectly. Please check again.\n", word);

    return 0;
}