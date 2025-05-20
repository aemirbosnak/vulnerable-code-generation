//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Morse code array 
const char* morseCodeArr[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", 
                        "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", 
                        "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
                        "-.--", "--..", "/", " "};

// Function to convert plain text to Morse code
void textToMorse(char* plainText) {
    for(int i = 0; plainText[i]; i++) {
        char c = toupper(plainText[i]);
        if(c == ' ')
            printf("%s ", morseCodeArr[26]);
        else if(c >= 'A' && c <= 'Z')
            printf("%s ", morseCodeArr[c - 'A']);
    }
}

// Function to convert Morse code to plain text
void morseToText(char* morseCode) {
    char* token = strtok(morseCode, " ");
    while(token != NULL) {
        for(int i = 0; i < 27; i++) {
            if(strcmp(morseCodeArr[i], token) == 0) {
                if(i != 26)
                    printf("%c", i + 'A');
                break;
            }
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    int choice;
    char str[100];
    printf("Enter 1 to convert plain text to Morse code or 2 to convert Morse code to plain text: ");
    scanf("%d", &choice);
    fflush(stdin);
    if(choice == 1) {
        printf("Enter the plain text: ");
        gets(str);
        printf("Morse code: ");
        textToMorse(str);
    }
    else if(choice == 2) {
        printf("Enter the Morse code: ");
        gets(str);
        printf("Plain text: ");
        morseToText(str);
    }
    else {
        printf("Invalid choice.");
        return 0;
    }
    return 0;
}