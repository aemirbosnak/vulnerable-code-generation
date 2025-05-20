//Code Llama-13B DATASET v1.0 Category: Text to Morse code conversion ; Style: visionary
/*
 * C Text to Morse code conversion example program
 *
 * Author: [Your Name]
 * Date:   [Today's Date]
 */

#include <stdio.h>
#include <string.h>

// Morse code map
char *morse_code_map[] = {
    ".-", // A
    "-...", // B
    "-.-.", // C
    "-..", // D
    ".", // E
    "..-.", // F
    "--.", // G
    "....", // H
    "..", // I
    ".---", // J
    "-.-", // K
    ".-..", // L
    "--", // M
    "-.", // N
    "---", // O
    ".--.", // P
    "--.-", // Q
    ".-.", // R
    "...", // S
    "-", // T
    "..-", // U
    "...-", // V
    ".--", // W
    "-..-", // X
    "-.--", // Y
    "--.." // Z
};

// Function to convert text to morse code
void text_to_morse(char *text) {
    // Loop through each character in the text
    for (int i = 0; i < strlen(text); i++) {
        // Check if character is uppercase
        if (text[i] >= 'A' && text[i] <= 'Z') {
            // Convert to lowercase
            text[i] = text[i] + 32;
        }
        // Get the corresponding morse code from the map
        char *morse = morse_code_map[text[i] - 'a'];
        // Print the morse code
        printf("%s ", morse);
    }
}

int main() {
    // Test the function with a sample text
    char text[] = "hello world";
    printf("Text: %s\n", text);
    text_to_morse(text);
    return 0;
}