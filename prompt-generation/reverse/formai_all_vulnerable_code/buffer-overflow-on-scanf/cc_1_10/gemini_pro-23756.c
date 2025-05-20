//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ASCII to Morse code conversion table
const char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
    "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
    "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...",
    "---..", "----.", "-----"
};

// Function to convert a character to its Morse code representation
char *char_to_morse(char c) {
    c = toupper(c);
    if (c >= 'A' && c <= 'Z') {
        return (char *)morse_table[c - 'A'];
    }
    else if (c >= '0' && c <= '9') {
        return (char *)morse_table[c - '0' + 26];
    }
    else if (c == ' ') {
        return " ";
    }
    else {
        return "";
    }
}

// Function to convert a string to its Morse code representation
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse_code = malloc(len * 5 + 1);
    int index = 0;
    for (int i = 0; i < len; i++) {
        char *morse = char_to_morse(str[i]);
        strcat(morse_code, morse);
        strcat(morse_code, " ");
        index += strlen(morse) + 1;
    }
    morse_code[index - 1] = '\0';
    return morse_code;
}

// Main function
int main() {
    // Get the input string from the user
    char str[100];
    printf("Enter a string to convert to Morse code: ");
    scanf("%s", str);

    // Convert the string to Morse code
    char *morse_code = string_to_morse(str);

    // Print the Morse code representation of the string
    printf("Morse code: %s\n", morse_code);

    // Free the allocated memory
    free(morse_code);
    return 0;
}