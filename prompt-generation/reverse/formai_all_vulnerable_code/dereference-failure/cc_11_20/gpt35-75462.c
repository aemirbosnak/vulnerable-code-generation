//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: shape shifting
// Welcome to the User Input Sanitizer program!
// I am a shape shifter, and I will change my function depending on your input!

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {

    printf("Enter one of the following options:\n");
    printf("a: Uppercase all letters in input\n");
    printf("b: Lowercase all letters in input\n");
    printf("c: Capitalize the first letter of each word in input\n");
    printf("d: Remove all spaces from input\n");
    printf("e: Reverse the input\n");
    printf("f: Quit program\n");

    char input[100]; // maximum input length of 100 characters
    char option = getchar();
    getchar(); // to clear the '\n' character from the input buffer
    
    while(option != 'f') {
    
        printf("Please enter your input:\n");
        fgets(input, 100, stdin);

        switch(option) {
            case 'a': {
                for(int i=0; i<strlen(input); i++) {
                    input[i] = toupper(input[i]);
                }
                printf("Your input in all uppercase: %s\n", input);
                break;
            }
            case 'b': {
                for(int i=0; i<strlen(input); i++) {
                    input[i] = tolower(input[i]);
                }
                printf("Your input in all lowercase: %s\n", input);
                break;
            }
            case 'c': {
                for(int i=0; i<strlen(input); i++) {
                    if(i==0 || input[i-1]==' ') {
                        input[i] = toupper(input[i]);
                    }
                }
                printf("Your input with first letter of each word capitalized: %s\n", input);
                break;
            }
            case 'd': {
                char* newString = malloc(strlen(input) * sizeof(char));
                int count = 0;
                for(int i=0; i<strlen(input); i++) {
                    if(input[i] != ' ') {
                        newString[count] = input[i];
                        count++;
                    }
                }
                newString[count] = '\0';
                strcpy(input, newString); // Copy new string back to original string
                printf("Your input without spaces: %s\n", input);
                free(newString);
                break;
            }
            case 'e': {
                char* newString = malloc(strlen(input) * sizeof(char));
                int count = 0;
                for(int i=strlen(input)-1; i>=0; i--) {
                    newString[count] = input[i];
                    count++;
                }
                newString[count] = '\0';
                strcpy(input, newString); // Copy new string back to original string
                printf("Your input reversed: %s\n", input);
                free(newString);
                break;
            }
            default: {
                printf("Invalid option selected.\n");
                break;
            }
        }
        
        printf("Enter one of the following options:\n");
        printf("a: Uppercase all letters in input\n");
        printf("b: Lowercase all letters in input\n");
        printf("c: Capitalize the first letter of each word in input\n");
        printf("d: Remove all spaces from input\n");
        printf("e: Reverse the input\n");
        printf("f: Quit program\n");
        option = getchar();
        getchar(); // to clear the '\n' character from the input buffer
    }
    
    printf("Thank you for using the User Input Sanitizer program!");
    
    return 0;
}