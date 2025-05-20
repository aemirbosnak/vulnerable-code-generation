//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to convert the given string to C Alien Language
char* toCAlienLanguage(char* inputString) {
    int length = strlen(inputString);
    char* outputString = malloc(length*sizeof(char));

    for(int i=0; i<length; i++) {
        if(inputString[i] == 'a') {
            outputString[i] = 'z';
        } else if(inputString[i] == 'b') {
            outputString[i] = 'y';
        } else if(inputString[i] == 'c') {
            outputString[i] = 'x';
        } else if(inputString[i] == 'd') {
            outputString[i] = 'w';
        } else if(inputString[i] == 'e') {
            outputString[i] = 'v';
        } else if(inputString[i] == 'f') {
            outputString[i] = 'u';
        } else if(inputString[i] == 'g') {
            outputString[i] = 't';
        } else if(inputString[i] == 'h') {
            outputString[i] = 's';
        } else if(inputString[i] == 'i') {
            outputString[i] = 'r';
        } else if(inputString[i] == 'j') {
            outputString[i] = 'q';
        } else if(inputString[i] == 'k') {
            outputString[i] = 'p';
        } else if(inputString[i] == 'l') {
            outputString[i] = 'o';
        } else if(inputString[i] == 'm') {
            outputString[i] = 'n';
        } else if(inputString[i] == 'n') {
            outputString[i] = 'm';
        } else if(inputString[i] == 'o') {
            outputString[i] = 'l';
        } else if(inputString[i] == 'p') {
            outputString[i] = 'k';
        } else if(inputString[i] == 'q') {
            outputString[i] = 'j';
        } else if(inputString[i] == 'r') {
            outputString[i] = 'i';
        } else if(inputString[i] == 's') {
            outputString[i] = 'h';
        } else if(inputString[i] == 't') {
            outputString[i] = 'g';
        } else if(inputString[i] == 'u') {
            outputString[i] = 'f';
        } else if(inputString[i] == 'v') {
            outputString[i] = 'e';
        } else if(inputString[i] == 'w') {
            outputString[i] = 'd';
        } else if(inputString[i] == 'x') {
            outputString[i] = 'c';
        } else if(inputString[i] == 'y') {
            outputString[i] = 'b';
        } else if(inputString[i] == 'z') {
            outputString[i] = 'a';
        } else {
            outputString[i] = inputString[i];
        }
    }

    return outputString;
}

//Driver function to test the above function
int main() {
    char input[50];
    printf("Enter a string in English: ");
    fgets(input, 50, stdin);

    char* output = toCAlienLanguage(input);
    printf("String in C Alien Language: %s\n", output);

    free(output);
    return 0;
}