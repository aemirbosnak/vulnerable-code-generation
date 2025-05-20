//Falcon2-11B DATASET v1.0 Category: Text to Morse code conversion ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the Morse code table
const char* morse_table[] = {
    ".-",
    "..",
    "...",
    "-.-.",
    "-..",
    ".",
    "..-.",
    "--.",
    "....",
    "..",
    ".---",
    "-.-",
    ".-..",
    "--",
    "-.",
    "---",
    ".--.",
    "--.-",
    ".-.",
    "...",
    "-",
    "..-",
    "...-",
    ".--",
    "-..-",
    "-.--",
    "--.."};

// Function to convert a string of text to Morse code
void text_to_morse(char* text, int length) {
    // Iterate over each character in the input string
    for (int i = 0; i < length; i++) {
        // Convert the character to its corresponding Morse code
        char* morse_code = morse_table[text[i] - 'A'];
        // Output the Morse code with a delay between each character
        printf("%s\n", morse_code);
        sleep(1);
    }
}

// Main function
int main() {
    // Get the input text from the user
    char input_text[100];
    printf("Enter some text: ");
    fgets(input_text, sizeof(input_text), stdin);

    // Remove any trailing newline character from the input text
    int length = strlen(input_text);
    if (input_text[length-1] == '\n') {
        input_text[length-1] = '\0';
    }

    // Convert the input text to Morse code
    text_to_morse(input_text, length);

    return 0;
}