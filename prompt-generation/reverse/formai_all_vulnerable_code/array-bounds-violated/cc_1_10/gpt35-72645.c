//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: creative
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *convert(char c) {         // helper function to convert a character to its Morse code equivalent
    static char *morse_codes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/"};
    if(isalpha(c)) {
        return morse_codes[toupper(c) - 'A'];
    }
    else if(isdigit(c)) {
        return morse_codes[c - '0' + 26];
    }
    else {
        switch(c) {
            case ' ':
                return " ";
            case ',':
                return "--..--";
            case '.':
                return ".-.-.-";
            case '?':
                return "..--..";
            case '/':
                return "-..-.";
            default:
                return "";
        }
    }
}

int main() {
    char text[1000], morse_code[5000];
    int i, j;
    printf("Enter the text to convert to Morse code: ");
    fgets(text, sizeof(text), stdin);    // input the text from the user
    text[strcspn(text, "\n")] = 0;       // remove the newline character
    for(i = 0, j = 0; i < strlen(text); i++) {     // iterate over the input text
        char *code = convert(text[i]);
        if(strcmp(code, "") != 0) {    // if the character is not a space
            strcat(morse_code, code);   // append the Morse code to the output string
            strcat(morse_code, " ");    // add a space between Morse codes
        }
        else {                          // if the character is a space
            if(i != 0 && text[i - 1] != ' ') {    // ignore consecutive spaces
                strcat(morse_code, "/ ");
            }
        }
    }
    printf("The Morse code for '%s' is:\n%s\n", text, morse_code);  // output the Morse code
    return 0;
}