//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: brave
// A Simple Text to Morse Code Conversion Program in C

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convertTextToMorseCode(char text[], int size);
// function to convert the text to morse code

void playMorseCode(char morse_code[]);
// function to play the morse code as sound

int main() {
    char text[500];
    // maximum length of text should be less than 500 characters
    int size;

    printf("Enter the text to convert to morse code:\n");
    fgets(text, 500, stdin);
    // read the input text from the user

    size = strlen(text);
    if (text[size - 1] == '\n') {
        // if the input text contains a new line character at the end, remove it
        text[size - 1] = '\0';
        size--;
    }

    printf("\nConverting to morse code...\n\n");
    convertTextToMorseCode(text, size);   // function call to convert the text to morse code

    return 0;
}


void convertTextToMorseCode(char text[], int size) {
    // array containing the morse code for each alphabet and digit
    char *morseCodes[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
                        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
                        "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
                        "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." };

    for (int i = 0; i < size; i++) {
        char character = toupper(text[i]);
        int code_index;

        if (isalpha(character)) {
            if (character >= 'A' && character <= 'Z') {
                code_index = character - 'A';
                printf("%s ", morseCodes[code_index]);
                // print the morse code for the alphabet
                playMorseCode(morseCodes[code_index]);
                // play the morse code sound
            }
        }
        else if (isdigit(character)) {
            // if the character is a digit, print its morse code
            code_index = character - '0' + 26;    // add 26 to the index to get to the digits
            printf("%s ", morseCodes[code_index]);
            // print the morse code for the digit
            playMorseCode(morseCodes[code_index]);
            // play the morse code sound
        }
        else {
            // if the character is not an alphabet or digit, just print it
            printf("%c ", character);
        }
    }
}

void playMorseCode(char morse_code[]) {
    // function to play the morse code as sound
    for (int i = 0; morse_code[i] != '\0'; i++) {
        if (morse_code[i] == '.') {
            printf("dot ");
        }
        else if (morse_code[i] == '-') {
            printf("dash ");
        }
        // print the dots and dashes as sound
    }
    printf("\n");
}