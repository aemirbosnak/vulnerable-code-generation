//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Morse code lookup table */
char *morseTable[37] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
                        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", 
                        ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", 
                        "--..", ".----", "..---", "...--", "....-", ".....", 
                        "-....", "--...", "---..", "----.", "-----"};

/* Function to convert a single character to morse code */
char *charToMorse(char c){
    /* Check if the character is a letter, digit, or special character */
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
        /* Convert the character to uppercase to match the lookup table */
        c = toupper(c);
        /* Find the index of the character in the lookup table */
        int index = c - 'A';
        /* Return the morse code for that character */
        return morseTable[index];
    }else if(c >= '0' && c <= '9'){
        /* Find the index of the digit in the lookup table */
        int index = c - '0' + 26;
        /* Return the morse code for that digit */
        return morseTable[index];
    }else{
        /* Check if the character is a space */
        if(c == ' '){
            /* Return the morse code for a space */
            return "/";
        }else{
            /* Return an empty string for any other character */
            return "";
        }
    }
}

/* Function to convert a string to morse code */
void textToMorse(char *text, char *morse){
    /* Loop through each character in the string */
    for(int i = 0; i < strlen(text); i++){
        /* Convert the character to morse code */
        char *morseChar = charToMorse(text[i]);
        /* Append the morse code character to the output string */
        strcat(morse, morseChar);
        /* Append a space to separate the morse code characters */
        strcat(morse, " ");
    }
}

int main(){
    /* Get input text from user */
    char text[100];
    printf("Enter text to convert to Morse code: ");
    scanf("%[^\n]", text);
    getchar(); /* Consume the newline character */

    /* Convert the text to morse code */
    char *morse = malloc(1000); /* Allocate memory for the morse code string */
    morse[0] = '\0'; /* Set the first character to null */
    textToMorse(text, morse);

    /* Print the morse code */
    printf("Morse Code: %s\n", morse);

    /* Free the memory allocated for the morse code string */
    free(morse);

    return 0;
}