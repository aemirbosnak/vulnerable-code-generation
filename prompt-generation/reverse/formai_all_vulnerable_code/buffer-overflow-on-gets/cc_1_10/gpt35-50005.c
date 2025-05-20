//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

char* convertToMorse(char c);

int main() {
    
    char text[100];
    char morse[200];
    int i = 0, j = 0;
    
    printf("Enter text to convert to Morse code: ");
    gets(text);
    
    while(text[i] != '\0') {
        if(text[i] == ' ') {
            morse[j++] = ' ';
            i++;
            continue;
        }
        char* morseChar = convertToMorse(text[i]);
        int len = strlen(morseChar);
        for(int k = 0; k < len; k++) {
            morse[j++] = morseChar[k];
        }
        i++;
    }
    morse[j] = '\0';
    printf("Morse code: %s", morse);
    
    return 0;
}

char* convertToMorse(char c) {
    char* morseCode[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", 
        ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", 
        "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
    };
    char* result;
    
    if(c >= 'a' && c <= 'z') {      //Convert lower case to upper case
        c = c - 32;
    }
    
    if(c >= 'A' && c <= 'Z') {
        result = morseCode[c - 'A'];
    } else if(c >= '0' && c <= '9') {
        result = morseCode[c - '0' + 26];
    } else {
        result = "";
    }
    return result;
}