//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: puzzling
#include <stdio.h>
#include <string.h>

// Function to convert text to Morse code
void textToMorse(char *str) {
    // Morse code characters
    char *morse[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", 
                      "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
                      "-.--", "--.." };
    // Text characters
    char *text[] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", 
                     "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
    // Loop through input string
    for(int i=0; i<strlen(str); i++) {
        // If character is not a letter or a space
        if((str[i] < 'A' || str[i] > 'Z') && str[i]!=' ') {
            printf("Sorry, I cannot convert this character to Morse code\n");
            return;
        }
    }
    printf("Here is your text in Morse code:\n");
    // Loop through input string again
    for(int i=0; i<strlen(str); i++) {
        // If character is a space
        if(str[i] == ' ') {
            printf("/ ");
        }
        // If character is a letter
        else {
            // Find corresponding Morse code character
            for(int j=0; j<26; j++) {
                if(str[i] == text[j][0]) {
                    printf("%s ", morse[j]);
                    break;
                }
            }
        }
    }
}

int main() {
    char input[100];
    printf("Welcome to our Morse Code converter!\n");
    printf("Please input the text you want to convert: ");
    fgets(input, 100, stdin);
    // Remove newline character from input
    input[strlen(input)-1] = '\0';
    // Convert the text to Morse code
    textToMorse(input);
    return 0;
}