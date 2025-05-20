//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int len = strlen(str);
    char *rev = malloc(len+1); //Creating a new string to store the reverse of the original string
    
    //Populating the new string with the reverse of the original string
    for(int i=0, j=len-1; i<len; i++, j--) {
        *(rev+i) = *(str+j);
    }
    *(rev+len) = '\0';
    
    //Comparing the original string with its reverse
    int res = strcmp(str, rev);
    free(rev); //Freeing the memory allocated to the new string
    
    //Returning 1 if the strings are equal and 0 otherwise
    if(res == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char str[100];
    printf("Welcome to Retro Palindrome Checker!\n");
    printf("Please enter a word or phrase to check if it is a palindrome:\n");
    scanf("%[^\n]", str); //Getting input from the user
    
    //Converting the input to lowercase and stripping of all non-alphabetic characters
    for(int i=0; i<strlen(str); i++) {
        if(!isalpha(*(str+i))) {
            for(int j=i; j<strlen(str); j++) {
                *(str+j) = *(str+j+1);
            }
        }
        *(str+i) = tolower(*(str+i));
    }
    
    //Checking if the input is a palindrome and displaying the result
    if(is_palindrome(str)) {
        printf("\nCongratulations! '%s' is a palindrome.", str);
    } else {
        printf("\nOops! '%s' is not a palindrome.", str);
    }
    
    return 0;
}