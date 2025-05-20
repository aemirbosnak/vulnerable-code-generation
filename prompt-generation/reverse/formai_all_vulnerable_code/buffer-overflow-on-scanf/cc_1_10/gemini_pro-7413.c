//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code character map
char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", "-.--.", "...--", "-.--.-",
    ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..",
    "----.", "-----", "|", ".-.-.-", "..--..", "...-..-", "....--", ".....-"
};

// Text to Morse code conversion function
char *text_to_morse(char *text) {
    int text_len = strlen(text);
    char *morse_code_str = malloc(text_len * 5);
    int morse_code_str_len = 0;

    for (int i = 0; i < text_len; i++) {
        int char_index = text[i] - 'a';
        if (char_index >= 0 && char_index < 26) {
            strcat(morse_code_str, morse_code[char_index]);
            morse_code_str_len += strlen(morse_code[char_index]);
        } else {
            morse_code_str[morse_code_str_len++] = ' ';
        }
    }

    return morse_code_str;
}

// Morse code to text conversion function
char *morse_to_text(char *morse_code) {
    int morse_code_len = strlen(morse_code);
    char *text = malloc(morse_code_len);
    int text_len = 0;

    char *token = strtok(morse_code, " ");
    while (token != NULL) {
        for (int i = 0; i < 26; i++) {
            if (strcmp(token, morse_code[i]) == 0) {
                text[text_len++] = 'a' + i;
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    return text;
}

// Main function
int main() {
    // Get the text input from the user
    char text[100];
    printf("Enter the text to be converted to Morse code: ");
    scanf("%s", text);

    // Convert the text to Morse code
    char *morse_code_str = text_to_morse(text);

    // Print the Morse code
    printf("Morse code: %s\n", morse_code_str);

    // Convert the Morse code back to text
    char *text_str = morse_to_text(morse_code_str);

    // Print the converted text
    printf("Converted text: %s\n", text_str);

    return 0;
}