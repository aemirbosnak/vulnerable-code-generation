//FormAI DATASET v1.0 Category: String manipulation ; Style: funny
#include <stdio.h>
#include <string.h>

int main(){
    // Introducing the program  
    printf("Welcome to the String Manipulator 3000! \n");

    // Getting user input 
    char userInput[100];
    printf("Please enter a word: \n");
    scanf("%s", userInput);

    // Counting the length of the user input
    int inputLength = strlen(userInput);
    printf("Your word is %d letters long! \n", inputLength);

    // Reversing the user input
    int i, j;
    char reversedInput[inputLength];
    for(i = inputLength-1, j=0; i >= 0; i--, j++){
        reversedInput[j] = userInput[i];
    }

    // Printing out the reversed input
    printf("Your word backwards is: %s \n", reversedInput);

    // Checking if the user input is a palindrome
    int palindrome = 1;
    for(i = 0; i <= inputLength/2; i++){
        if(userInput[i] != userInput[inputLength-1-i]){
            palindrome = 0;
            break;
        }
    }

    // Telling the user if their word is a palindrome or not
    if(palindrome == 1){
        printf("Your word is a palindrome! \n");
    } else {
        printf("Your word is not a palindrome. :( \n");
    }

    // Creating a new string with the middle letter capitalized
    char newString[inputLength];
    int middleIndex = inputLength / 2;
    for(i = 0; i < inputLength; i++){
        if(i == middleIndex){
            newString[i] = userInput[i] - 32;
        } else {
            newString[i] = userInput[i];
        }
    }

    // Printing out the new string with the middle letter capitalized
    printf("Here's your word with the middle letter capitalized: %s \n", newString);

    // Saying goodbye to the user 
    printf("Thanks for using the String Manipulator 3000! Goodbye! \n");

    // The end! 
    return 0;
}