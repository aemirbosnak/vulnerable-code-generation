//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: synchronous
#include <stdio.h>
#include <string.h>

// Morse code lookup table
const char* MORSE_CODES[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"};

// ASCII character lookup table
const char ASCII_TO_MORSE[127][5] = {
    {'\0'},    // null character
    {".-.-.-"}, // period (.)
    {"--..--"}, // comma (,)
    {"..--.."}, // question mark (?)
    {"-.-.--"}, // exclamation point (!)
    {".----."}, // apostrophe (')
    {"-..-."},  // slash (/)
    {"-.--."},  // parentheses ()
    {"-.--.-"}, // parentheses ()
    {".-..."},  // ampersand (&)
    {"---..."}, // colon (:)
    {"-.-.-."}, // semicolon (;)
    {"-...-"},  // equal (=)
    {"-....-"}, // dash (-)
    {".-.-."},  // plus (+)
    {"..--.-"}, // at (@)
    {".-"},     // A
    {"-..."},   // B
    {"-.-."},   // C
    {"-.."},    // D
    {". "},     // E
    {"..-."},   // F
    {"--."},    // G
    {"...."},   // H
    {".."},     // I
    {".---"},   // J
    {"-.-"},    // K
    {".-.."},   // L
    {"--"},     // M
    {"-."},     // N
    {"---"},    // O
    {".--."},   // P
    {"--.-"},   // Q
    {".-."},    // R
    {"..."},    // S
    {"-"},      // T
    {"..-"},    // U
    {"...-"},   // V
    {".--"},    // W
    {"-..-"},   // X
    {"-.--"},   // Y
    {"--.."},   // Z
};

void text_to_morse(char* input, char* output) {
    int i, j, k, length;
    int output_index = 0;

    // Replace spaces with underscores for easier parsing
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            input[i] = '_';
        }
    }

    // Convert each character to Morse code
    for (i = 0; i < strlen(input); i++) {
        length = strlen(ASCII_TO_MORSE[(int)input[i]]);
        for (j = 0; j < length; j++) {
            output[output_index++] = ASCII_TO_MORSE[(int)input[i]][j];
        }
        // Separate each character with a space
        if (i != strlen(input) - 1) {
            output[output_index++] = ' ';
        }
    }

    // Null terminate the output string
    output[output_index] = '\0';
}

int main() {
    char input[256];
    char output[1024];

    printf("Enter text to convert to Morse code: ");
    fgets(input, 256, stdin);
    input[strcspn(input, "\n")] = 0;

    text_to_morse(input, output);

    printf("Morse code:\n%s\n", output);

    return 0;
}