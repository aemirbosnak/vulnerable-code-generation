//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--",
    "....-", ".....", "-....", "--...", "---..", "----.", "-----", " "
};

// Convert a character to its Morse code representation
char *char_to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        c = c - 32;
    }
    int index = c - 'A';
    if (index >= 0 && index < 27) {
        return morse_table[index];
    } else {
        return "?";
    }
}

// Convert a string to its Morse code representation
char *string_to_morse(char *str) {
    int len = strlen(str);
    char *morse = malloc(len * 5 + 1);
    int index = 0;
    for (int i = 0; i < len; i++) {
        char *morse_char = char_to_morse(str[i]);
        strcat(morse, morse_char);
        strcat(morse, " ");
        index += strlen(morse_char) + 1;
    }
    morse[index - 1] = '\0';
    return morse;
}

// Main function
int main() {
    // Get the input string
    char str[100];
    printf("Enter a string to convert to Morse code: ");
    scanf("%s", str);

    // Convert the string to Morse code
    char *morse = string_to_morse(str);

    // Print the Morse code representation
    printf("Morse code: %s\n", morse);

    // Free the allocated memory
    free(morse);

    return 0;
}