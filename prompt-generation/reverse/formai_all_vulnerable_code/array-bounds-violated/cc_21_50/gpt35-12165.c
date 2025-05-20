//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to convert character to Morse code string
char* charToMorse(char ch){
    switch(ch){
        case 'A': return ".-";
        case 'B': return "-...";
        case 'C': return "-.-.";
        case 'D': return "-..";
        case 'E': return ".";
        case 'F': return "..-.";
        case 'G': return "--.";
        case 'H': return "....";
        case 'I': return "..";
        case 'J': return ".---";
        case 'K': return "-.-";
        case 'L': return ".-..";
        case 'M': return "--";
        case 'N': return "-.";
        case 'O': return "---";
        case 'P': return ".--.";
        case 'Q': return "--.-";
        case 'R': return ".-.";
        case 'S': return "...";
        case 'T': return "-";
        case 'U': return "..-";
        case 'V': return "...-";
        case 'W': return ".--";
        case 'X': return "-..-";
        case 'Y': return "-.--";
        case 'Z': return "--..";
        case '0': return "-----";
        case '1': return ".----";
        case '2': return "..---";
        case '3': return "...--";
        case '4': return "....-";
        case '5': return ".....";
        case '6': return "-....";
        case '7': return "--...";
        case '8': return "---..";
        case '9': return "----.";
        default: return "";
    }
}

int main(){
    char word[100];
    int len;
    printf("Enter a word or sentence to convert to Morse code: ");
    fgets(word, 100, stdin);
    len = strlen(word);
    if(word[len-1] == '\n') word[len-1] = '\0'; //removing new line character from fgets input
    char *morse = (char*)malloc(sizeof(char)*100); //allocating memory to a string for holding Morse code
    *morse = '\0'; //initializing Morse code string to empty
    for(int i=0; i<len; i++){
        if(word[i] == ' ') strcat(morse, " "); //adding space between words in Morse code
        else strcat(morse, charToMorse(toupper(word[i]))); //converting character to uppercase and converting to Morse code
        if(i != len-1) strcat(morse, " "); //adding space between characters in Morse code except for last character
    }
    printf("Morse code: %s", morse);
    free(morse); //freeing memory allocated to Morse code string
    return 0;
}