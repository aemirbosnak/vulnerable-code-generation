//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-.--.--", ".-.-.-", "-.--.-", "---.-", ".-.-.", "---...", ".-..-"
};

// Character to Morse code conversion function
char *text_to_morse(char text) {
    int index = text - 'a';
    if (index >= 0 && index < 26) {
        return morse_code[index];
    } else {
        return NULL;
    }
}

// Morse code to text conversion function
char text_from_morse(char *morse) {
    for (int i = 0; i < 26; i++) {
        if (strcmp(morse, morse_code[i]) == 0) {
            return 'a' + i;
        }
    }
    return '\0';
}

// Main function
int main() {
    // Get the input text
    char text[100];
    printf("Enter the text to convert to Morse code: ");
    scanf("%s", text);

    // Convert the text to Morse code
    char morse_code[100];
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        char *morse = text_to_morse(text[i]);
        if (morse != NULL) {
            strcat(morse_code, morse);
        }
    }

    // Print the Morse code
    printf("Morse code: %s\n", morse_code);

    // Convert the Morse code back to text
    char text_back[100];
    length = strlen(morse_code);
    for (int i = 0; i < length; i += 4) {
        char morse[5];
        strncpy(morse, &morse_code[i], 4);
        morse[4] = '\0';
        char letter = text_from_morse(morse);
        if (letter != '\0') {
            text_back[i / 4] = letter;
        }
    }

    // Print the converted text
    printf("Text back: %s\n", text_back);

    return 0;
}