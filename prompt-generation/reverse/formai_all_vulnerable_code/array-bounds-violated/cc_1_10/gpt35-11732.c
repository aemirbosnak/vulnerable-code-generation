//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: future-proof
#include <stdio.h>
#include <string.h>

// define morse code for each character
const char* morseCode[] = { 
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", 
    "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", 
    "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
    "-.--", "--..", ".----", "..---", "...--", "....-", ".....", 
    "-....", "--...", "---..", "----.", "-----", "--..--", ".-.-.-", "..--.." 
}; 

// the size of the morse code array
const int morseCodeSize = sizeof(morseCode) / sizeof(morseCode[0]);

// converts a given character to morse code
void convertCharToMorseCode(char character) {
    // if the character is a space
    if (character == ' '){
        printf(" ");
        return;
    }

    // if the character is a number
    if (isdigit(character)){
        // convert the character to an integer
        int n = character - '0';
        printf("%s ", morseCode[n+26]);
        return;
    }

    // if the character is an uppercase letter
    if (isupper(character)){
        // convert the character to lowercase
        character = tolower(character);
        int index = character - 'a';
        printf("%s ", morseCode[index]);
        return;
    }

    // if the character is a lowercase letter
    int index = character - 'a';
    printf("%s ", morseCode[index]);
}

// converts a given string to morse code
void convertStringToMorseCode(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        convertCharToMorseCode(str[i]);
    }
    printf("\n");
}

int main() {
    char name[100];

    printf("Enter a text to convert to morse code:\n");
    fgets(name, 100, stdin);

    // remove newline character from input string
    if (name[strlen(name) - 1] == '\n') {
        name[strlen(name) - 1] = '\0';
    }

    convertStringToMorseCode(name);
    
    return 0;
}