//FormAI DATASET v1.0 Category: Spell checking ; Style: automated
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int checkSpell(char word[50], char dictionary[100][50], int n) { //function to check spelling of the input word

    int i, flag = 0;

    for (i = 0; i < n; i++) {
        if (strcmp(word, dictionary[i]) == 0) { //if input word is found in dictionary, return 1
            flag = 1;
            break;
        }
    }

    if(flag == 0) { //if input word is not in dictionary
        char newWord[50];
        int j = 0;

        for(i = 0; i < strlen(word); i++) {
            if(isalpha(word[i])) { //removing any non-alphabetic characters from the word
                newWord[j] = tolower(word[i]); //converting all characters to lowercase
                j++;
            }
        }
        newWord[j] = '\0'; //end the new word with null character
        
        for(i = 0; i < n; i++) {
            if(strcmp(newWord, dictionary[i]) == 0) { //if new word is found in dictionary, return 2
                flag = 2;
                break;
            }
        }
    }

    return flag; //returning the flag to indicate if word is correct (1), incorrect (0) or can be corrected (2)
}

int main() {
    char input[50];
    char dictionary[100][50] = {"apple", "banana", "cherry", "orange", "peach", "pear", "strawberry"}; //dictionary of valid words
    int n = 7; //number of words in the dictionary

    printf("Enter a word to check its spelling: ");
    scanf("%s", input);

    int result = checkSpell(input, dictionary, n);

    if(result == 1) {
        printf("\nThe word is spelled correctly.\n");
    }
    else if(result == 0) {
        printf("\nThe word is misspelled.\n");
    }
    else if(result == 2) {
        printf("\nThe word is not in the dictionary, but it could be corrected to: %s\n", dictionary[result]);
    }

    return 0;
}